#include "CustomMeshPassShaders.h"

#include "BasePassRendering.h"
#include "CustomMeshPassForwardLight.h"
#include "DataDrivenShaderPlatformInfo.h"
#include "GlobalRenderResources.h"
#include "MaterialDomain.h"
#include "MeshDrawShaderBindings.h"
#include "RHIStaticStates.h"
#include "SceneTexturesConfig.h"

IMPLEMENT_MATERIAL_SHADER_TYPE(, FCustomMeshPassVS, TEXT("/Plugin/CustomMeshPass/Private/CustomMeshPassVertex.usf"), TEXT("MainVS"), SF_Vertex);
IMPLEMENT_MATERIAL_SHADER_TYPE(, FCustomMeshPassForwardPS, TEXT("/Plugin/CustomMeshPass/Private/CustomMeshPassForward.usf"), TEXT("MainPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(, FCustomMeshPassGBufferPS, TEXT("/Plugin/CustomMeshPass/Private/CustomMeshPassGBuffer.usf"), TEXT("MainPS"), SF_Pixel);

namespace
{
	void BindSurfaceNames(
		const FShaderParameterMap& ParameterMap,
		FShaderParameter& BaseColorParam,
		FShaderParameter& MetallicParam,
		FShaderParameter& SpecularParam,
		FShaderParameter& RoughnessParam,
		FShaderParameter& AmbientOcclusionParam,
		FShaderParameter& EmissiveParam,
		FShaderParameter& NormalStrengthParam,
		FShaderParameter& SurfaceMapMaskParam,
		FShaderResourceParameter& BaseMapParam,
		FShaderResourceParameter& NormalMapParam,
		FShaderResourceParameter& AOMapParam,
		FShaderResourceParameter& RoughnessMapParam,
		FShaderResourceParameter& MetallicMapParam,
		FShaderResourceParameter& SurfaceSamplerParam)
	{
		BaseColorParam.Bind(ParameterMap, TEXT("BaseColor"));
		MetallicParam.Bind(ParameterMap, TEXT("Metallic"));
		SpecularParam.Bind(ParameterMap, TEXT("Specular"));
		RoughnessParam.Bind(ParameterMap, TEXT("Roughness"));
		AmbientOcclusionParam.Bind(ParameterMap, TEXT("AmbientOcclusion"));
		EmissiveParam.Bind(ParameterMap, TEXT("Emissive"));
		NormalStrengthParam.Bind(ParameterMap, TEXT("NormalStrength"));
		SurfaceMapMaskParam.Bind(ParameterMap, TEXT("SurfaceMapMask"));
		BaseMapParam.Bind(ParameterMap, TEXT("BaseMap"));
		NormalMapParam.Bind(ParameterMap, TEXT("NormalMap"));
		AOMapParam.Bind(ParameterMap, TEXT("AOMap"));
		RoughnessMapParam.Bind(ParameterMap, TEXT("RoughnessMap"));
		MetallicMapParam.Bind(ParameterMap, TEXT("MetallicMap"));
		SurfaceSamplerParam.Bind(ParameterMap, TEXT("SurfaceSampler"));
	}

	void BindSurface(
		const FCustomMeshPassShaderElementData& Data,
		const FShaderParameter& BaseColorParam,
		const FShaderParameter& MetallicParam,
		const FShaderParameter& SpecularParam,
		const FShaderParameter& RoughnessParam,
		const FShaderParameter& AmbientOcclusionParam,
		const FShaderParameter& EmissiveParam,
		const FShaderParameter& NormalStrengthParam,
		const FShaderParameter& SurfaceMapMaskParam,
		const FShaderResourceParameter& BaseMapParam,
		const FShaderResourceParameter& NormalMapParam,
		const FShaderResourceParameter& AOMapParam,
		const FShaderResourceParameter& RoughnessMapParam,
		const FShaderResourceParameter& MetallicMapParam,
		const FShaderResourceParameter& SurfaceSamplerParam,
		FMeshDrawSingleShaderBindings& ShaderBindings)
	{
		const FCustomMeshPassSurface& Surface = Data.Surface;
		ShaderBindings.Add(BaseColorParam, Surface.BaseColor);
		ShaderBindings.Add(MetallicParam, Surface.Metallic);
		ShaderBindings.Add(SpecularParam, Surface.Specular);
		ShaderBindings.Add(RoughnessParam, Surface.Roughness);
		ShaderBindings.Add(AmbientOcclusionParam, Surface.AmbientOcclusion);
		ShaderBindings.Add(EmissiveParam, Surface.Emissive);
		ShaderBindings.Add(NormalStrengthParam, Surface.NormalStrength);

		uint32 MapMask = 0;
		if (Data.BaseMap) { MapMask |= CustomMeshPassSurfaceMap::Base; }
		if (Data.NormalMap) { MapMask |= CustomMeshPassSurfaceMap::Normal; }
		if (Data.AOMap) { MapMask |= CustomMeshPassSurfaceMap::AO; }
		if (Data.RoughnessMap) { MapMask |= CustomMeshPassSurfaceMap::Roughness; }
		if (Data.MetallicMap) { MapMask |= CustomMeshPassSurfaceMap::Metallic; }
		ShaderBindings.Add(SurfaceMapMaskParam, MapMask);

		FRHITexture* White = GWhiteTexture->TextureRHI.GetReference();
		FRHISamplerState* Sampler = TStaticSamplerState<SF_AnisotropicLinear, AM_Wrap, AM_Wrap, AM_Wrap>::GetRHI();
		ShaderBindings.AddTexture(BaseMapParam, SurfaceSamplerParam, Sampler, Data.BaseMap ? Data.BaseMap : White);
		ShaderBindings.AddTexture(NormalMapParam, SurfaceSamplerParam, Sampler, Data.NormalMap ? Data.NormalMap : White);
		ShaderBindings.AddTexture(AOMapParam, SurfaceSamplerParam, Sampler, Data.AOMap ? Data.AOMap : White);
		ShaderBindings.AddTexture(RoughnessMapParam, SurfaceSamplerParam, Sampler, Data.RoughnessMap ? Data.RoughnessMap : White);
		ShaderBindings.AddTexture(MetallicMapParam, SurfaceSamplerParam, Sampler, Data.MetallicMap ? Data.MetallicMap : White);
	}
}

// ---------------------------------------------------------------------------
// FCustomMeshPassShader

FCustomMeshPassShader::FCustomMeshPassShader(const FMeshMaterialShaderType::CompiledShaderInitializerType& Initializer)
	: FMeshMaterialShader(Initializer)
{
	PassUniformBuffer.Bind(
		Initializer.ParameterMap,
		FSceneTextureUniformParameters::FTypeInfo::GetStructMetadata()->GetShaderVariableName());
}

bool FCustomMeshPassShader::ShouldCompilePermutation(const FMeshMaterialShaderPermutationParameters& Parameters)
{
	if (!IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5))
	{
		return false;
	}
	// 渲染时统一用 UMaterial::GetDefaultMaterial(MD_Surface)，其它材质不需要这组 Shader
	if (!Parameters.MaterialParameters.bIsDefaultMaterial
		|| Parameters.MaterialParameters.MaterialDomain != MD_Surface)
	{
		return false;
	}
	return Parameters.VertexFactoryType
		&& Parameters.VertexFactoryType->GetFName() == FName(TEXT("FLocalVertexFactory"));
}

// ---------------------------------------------------------------------------
// FCustomMeshPassVS

FCustomMeshPassVS::FCustomMeshPassVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
	: FCustomMeshPassShader(Initializer)
{
	UVChannelParam.Bind(Initializer.ParameterMap, TEXT("UVChannel"));
	UVTilingOffsetParam.Bind(Initializer.ParameterMap, TEXT("UVTilingOffset"));
}

void FCustomMeshPassVS::GetShaderBindings(
	const FScene* Scene,
	ERHIFeatureLevel::Type FeatureLevel,
	const FPrimitiveSceneProxy* PrimitiveSceneProxy,
	const FMaterialRenderProxy& MaterialRenderProxy,
	const FMaterial& Material,
	const FCustomMeshPassShaderElementData& ShaderElementData,
	FMeshDrawSingleShaderBindings& ShaderBindings) const
{
	FMeshMaterialShader::GetShaderBindings(
		Scene, FeatureLevel, PrimitiveSceneProxy, MaterialRenderProxy, Material, ShaderElementData, ShaderBindings);

	const FCustomMeshPassSurface& Surface = ShaderElementData.Surface;
	ShaderBindings.Add(UVChannelParam, Surface.UVChannel);
	ShaderBindings.Add(UVTilingOffsetParam, FVector4f(Surface.UVTiling.X, Surface.UVTiling.Y, Surface.UVOffset.X, Surface.UVOffset.Y));
}

// ---------------------------------------------------------------------------
// FCustomMeshPassForwardPS

FCustomMeshPassForwardPS::FCustomMeshPassForwardPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
	: FCustomMeshPassShader(Initializer)
{
	BindSurfaceNames(
		Initializer.ParameterMap,
		BaseColorParam, MetallicParam, SpecularParam, RoughnessParam, AmbientOcclusionParam, EmissiveParam, NormalStrengthParam, SurfaceMapMaskParam,
		BaseMapParam, NormalMapParam, AOMapParam, RoughnessMapParam, MetallicMapParam, SurfaceSamplerParam);
	bLumenValidParam.Bind(Initializer.ParameterMap, TEXT("bLumenValid"));
	LumenGridZParamsParam.Bind(Initializer.ParameterMap, TEXT("LumenGridZParams"));
	LumenGridSizeParam.Bind(Initializer.ParameterMap, TEXT("LumenGridSize"));
	LumenVolume0Param.Bind(Initializer.ParameterMap, TEXT("LumenVolume0"));
	LumenVolume1Param.Bind(Initializer.ParameterMap, TEXT("LumenVolume1"));
	LumenVolumeSamplerParam.Bind(Initializer.ParameterMap, TEXT("LumenVolumeSampler"));
}

void FCustomMeshPassForwardPS::ModifyCompilationEnvironment(const FMeshMaterialShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
{
	FCustomMeshPassShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

	// 引擎的 FForwardLightingParameters::ModifyCompilationEnvironment 依赖 Renderer 未导出的
	// NumCulledLightsGridStride / NumCulledGridPrimitiveTypes（LightGridInjection.cpp，均为 2）
	OutEnvironment.SetDefine(TEXT("FORWARD_LIGHT_DATA_STRIDE"), FMath::DivideAndRoundUp<int32>(sizeof(FForwardLightData), sizeof(FVector4f)));
	OutEnvironment.SetDefine(TEXT("NUM_CULLED_LIGHTS_GRID_STRIDE"), 2);
	OutEnvironment.SetDefine(TEXT("NUM_CULLED_GRID_PRIMITIVE_TYPES"), 2);
}

void FCustomMeshPassForwardPS::GetShaderBindings(
	const FScene* Scene,
	ERHIFeatureLevel::Type FeatureLevel,
	const FPrimitiveSceneProxy* PrimitiveSceneProxy,
	const FMaterialRenderProxy& MaterialRenderProxy,
	const FMaterial& Material,
	const FCustomMeshPassShaderElementData& ShaderElementData,
	FMeshDrawSingleShaderBindings& ShaderBindings) const
{
	FMeshMaterialShader::GetShaderBindings(
		Scene, FeatureLevel, PrimitiveSceneProxy, MaterialRenderProxy, Material, ShaderElementData, ShaderBindings);

	BindSurface(
		ShaderElementData,
		BaseColorParam, MetallicParam, SpecularParam, RoughnessParam, AmbientOcclusionParam, EmissiveParam, NormalStrengthParam, SurfaceMapMaskParam,
		BaseMapParam, NormalMapParam, AOMapParam, RoughnessMapParam, MetallicMapParam, SurfaceSamplerParam,
		ShaderBindings);

	ShaderBindings.Add(bLumenValidParam, ShaderElementData.bLumenValid);
	ShaderBindings.Add(LumenGridZParamsParam, ShaderElementData.LumenGridZParams);
	ShaderBindings.Add(LumenGridSizeParam, FVector3f(
		(float)ShaderElementData.LumenGridSize.X,
		(float)ShaderElementData.LumenGridSize.Y,
		(float)ShaderElementData.LumenGridSize.Z));

	FRHITexture* Volume0 = ShaderElementData.LumenVolume0
		? ShaderElementData.LumenVolume0
		: GBlackVolumeTexture->TextureRHI.GetReference();
	FRHITexture* Volume1 = ShaderElementData.LumenVolume1
		? ShaderElementData.LumenVolume1
		: GBlackVolumeTexture->TextureRHI.GetReference();

	FRHISamplerState* Sampler = TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
	ShaderBindings.AddTexture(LumenVolume0Param, LumenVolumeSamplerParam, Sampler, Volume0);
	ShaderBindings.AddTexture(LumenVolume1Param, LumenVolumeSamplerParam, Sampler, Volume1);

	const FShaderUniformBufferParameter& ForwardLightParam = GetUniformBufferParameter<FCustomMeshPassForwardLightParameters>();
	if (ForwardLightParam.IsBound())
	{
		check(ShaderElementData.ForwardLightUniformBuffer);
		ShaderBindings.Add(ForwardLightParam, ShaderElementData.ForwardLightUniformBuffer);
	}
}

// ---------------------------------------------------------------------------
// FCustomMeshPassGBufferPS

FCustomMeshPassGBufferPS::FCustomMeshPassGBufferPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
	: FCustomMeshPassShader(Initializer)
{
	BindSurfaceNames(
		Initializer.ParameterMap,
		BaseColorParam, MetallicParam, SpecularParam, RoughnessParam, AmbientOcclusionParam, EmissiveParam, NormalStrengthParam, SurfaceMapMaskParam,
		BaseMapParam, NormalMapParam, AOMapParam, RoughnessMapParam, MetallicMapParam, SurfaceSamplerParam);
}

void FCustomMeshPassGBufferPS::GetShaderBindings(
	const FScene* Scene,
	ERHIFeatureLevel::Type FeatureLevel,
	const FPrimitiveSceneProxy* PrimitiveSceneProxy,
	const FMaterialRenderProxy& MaterialRenderProxy,
	const FMaterial& Material,
	const FCustomMeshPassShaderElementData& ShaderElementData,
	FMeshDrawSingleShaderBindings& ShaderBindings) const
{
	FMeshMaterialShader::GetShaderBindings(
		Scene, FeatureLevel, PrimitiveSceneProxy, MaterialRenderProxy, Material, ShaderElementData, ShaderBindings);

	BindSurface(
		ShaderElementData,
		BaseColorParam, MetallicParam, SpecularParam, RoughnessParam, AmbientOcclusionParam, EmissiveParam, NormalStrengthParam, SurfaceMapMaskParam,
		BaseMapParam, NormalMapParam, AOMapParam, RoughnessMapParam, MetallicMapParam, SurfaceSamplerParam,
		ShaderBindings);
}
