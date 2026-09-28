#include "CustomMeshPassForwardLight.h"

#include "DataDrivenShaderPlatformInfo.h"
#include "RenderGraphBuilder.h"
#include "SceneRendering.h"
#include "SystemTextures.h"

IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FCustomMeshPassForwardLightParameters, "CMPForwardLight");

namespace
{
	void CopyFromEngine(const FForwardLightUniformParameters& Src, FCustomMeshPassForwardLightParameters& Dst)
	{
		Dst.NumLocalLights = Src.NumLocalLights;
		Dst.NumDirectionalLights = Src.NumDirectionalLights;
		Dst.NumReflectionCaptures = Src.NumReflectionCaptures;
		Dst.HasDirectionalLight = Src.HasDirectionalLight;
		Dst.NumGridCells = Src.NumGridCells;
		Dst.LightNameDwords = Src.LightNameDwords;
		Dst.CulledGridSize = Src.CulledGridSize;
		Dst.MaxCulledLightsPerCell = Src.MaxCulledLightsPerCell;
		Dst.LightGridPixelSizeShift = Src.LightGridPixelSizeShift;
		Dst.LightGridZParams = Src.LightGridZParams;
		Dst.DirectionalLightDirection = Src.DirectionalLightDirection;
		Dst.DirectionalLightSourceRadius = Src.DirectionalLightSourceRadius;
		Dst.DirectionalLightSoftSourceRadius = Src.DirectionalLightSoftSourceRadius;
		Dst.DirectionalLightColor = Src.DirectionalLightColor;
		Dst.DirectionalLightVolumetricScatteringIntensity = Src.DirectionalLightVolumetricScatteringIntensity;
		Dst.DirectionalLightSpecularScale = Src.DirectionalLightSpecularScale;
		Dst.DirectionalLightDiffuseScale = Src.DirectionalLightDiffuseScale;
		Dst.DirectionalLightSceneInfoExtraDataPacked = Src.DirectionalLightSceneInfoExtraDataPacked;
		Dst.DirectionalLightDistanceFadeMAD = Src.DirectionalLightDistanceFadeMAD;
		Dst.DirectionalLightVSM = Src.DirectionalLightVSM;
		Dst.DirectionalLightHandledByMegaLights = Src.DirectionalLightHandledByMegaLights;
		Dst.DirectionalMegaLightsSupportedStartIndex = Src.DirectionalMegaLightsSupportedStartIndex;
		Dst.DirectLightingShowFlag = Src.DirectLightingShowFlag;
		Dst.CulledBufferOffsetISR = Src.CulledBufferOffsetISR;
		Dst.DirectionalLightLightFunctionAtlasLightIndex = Src.DirectionalLightLightFunctionAtlasLightIndex;
		Dst.DirectionalLightAffectsTranslucentLighting = Src.DirectionalLightAffectsTranslucentLighting;
		Dst.PreViewTranslationOffsetISR = Src.PreViewTranslationOffsetISR;
		Dst.ForwardLightBuffer = Src.ForwardLightBuffer;
		Dst.NumCulledLightsGrid = Src.NumCulledLightsGrid;
		Dst.CulledLightDataGrid32Bit = Src.CulledLightDataGrid32Bit;
		Dst.CulledLightDataGrid16Bit = Src.CulledLightDataGrid16Bit;
		Dst.DirectionalLightIndices = Src.DirectionalLightIndices;
		Dst.LightViewData = Src.LightViewData;
		Dst.LightNamesBuffer = Src.LightNamesBuffer;
	}

	/** 与引擎 SetupDummyForwardLightUniformParameters 相同的空资源，NumLocalLights = 0 时 Shader 不会读 */
	void SetupDummy(FRDGBuilder& GraphBuilder, EShaderPlatform Platform, FCustomMeshPassForwardLightParameters& Dst)
	{
		Dst = FCustomMeshPassForwardLightParameters();
		Dst.DirectionalLightVSM = INDEX_NONE;

		Dst.ForwardLightBuffer = GraphBuilder.CreateSRV(GSystemTextures.GetDefaultStructuredBuffer(GraphBuilder, sizeof(FVector4f)));
		Dst.NumCulledLightsGrid = GraphBuilder.CreateSRV(GSystemTextures.GetDefaultStructuredBuffer(GraphBuilder, sizeof(uint32)));

		// 与 LightGridCommon.ush 的 LIGHT_GRID_USES_16BIT_BUFFERS 对应
		FRDGBufferSRVRef CulledLightDataGridSRV = nullptr;
		if (RHISupportsBufferLoadTypeConversion(Platform) && !IsMobilePlatform(Platform))
		{
			CulledLightDataGridSRV = GraphBuilder.CreateSRV(GSystemTextures.GetDefaultBuffer(GraphBuilder, sizeof(uint16)), PF_R16_UINT);
		}
		else
		{
			CulledLightDataGridSRV = GraphBuilder.CreateSRV(GSystemTextures.GetDefaultStructuredBuffer(GraphBuilder, sizeof(uint32)));
		}
		Dst.CulledLightDataGrid32Bit = CulledLightDataGridSRV;
		Dst.CulledLightDataGrid16Bit = CulledLightDataGridSRV;

		Dst.DirectionalLightIndices = GraphBuilder.CreateSRV(GSystemTextures.GetDefaultStructuredBuffer(GraphBuilder, sizeof(uint32)));
		Dst.LightViewData = GraphBuilder.CreateSRV(GSystemTextures.GetDefaultStructuredBuffer(GraphBuilder, sizeof(FVector4f)));
		Dst.LightNamesBuffer = GraphBuilder.CreateSRV(GSystemTextures.GetDefaultByteAddressBuffer(GraphBuilder, sizeof(uint32)));
	}
}

namespace CustomMeshPass
{
	TRDGUniformBufferRef<FCustomMeshPassForwardLightParameters> CreateForwardLightUniformBuffer(
		FRDGBuilder& GraphBuilder,
		const FSceneView& View)
	{
		FCustomMeshPassForwardLightParameters* Parameters = GraphBuilder.AllocParameters<FCustomMeshPassForwardLightParameters>();

		const FForwardLightUniformParameters* Src = View.bIsViewInfo
			? static_cast<const FViewInfo&>(View).ForwardLightingResources.ForwardLightUniformParameters
			: nullptr;

		// 路径追踪等模式下 Light Grid 不会构建，SRV 可能为空
		if (Src && Src->ForwardLightBuffer && Src->NumCulledLightsGrid && Src->CulledLightDataGrid32Bit
			&& Src->DirectionalLightIndices && Src->LightViewData && Src->LightNamesBuffer)
		{
			CopyFromEngine(*Src, *Parameters);
		}
		else
		{
			SetupDummy(GraphBuilder, View.GetShaderPlatform(), *Parameters);
		}

		return GraphBuilder.CreateUniformBuffer(Parameters);
	}
}
