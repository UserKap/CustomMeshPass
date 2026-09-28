#include "CustomMeshPassShaders.h"

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
	void BindSurface(
		const FCustomMeshPassSurface& Surface,
		const FShaderParameter& BaseColorParam,
		const FShaderParameter& MetallicParam,
		const FShaderParameter& RoughnessParam,
		FMeshDrawSingleShaderBindings& ShaderBindings)
	{
		ShaderBindings.Add(BaseColorParam, Surface.BaseColor);
		ShaderBindings.Add(MetallicParam, Surface.Metallic);
		ShaderBindings.Add(RoughnessParam, Surface.Roughness);
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
// FCustomMeshPassForwardPS

FCustomMeshPassForwardPS::FCustomMeshPassForwardPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
	: FCustomMeshPassShader(Initializer)
{
	BaseColorParam.Bind(Initializer.ParameterMap, TEXT("BaseColor"));
	MetallicParam.Bind(Initializer.ParameterMap, TEXT("Metallic"));
	RoughnessParam.Bind(Initializer.ParameterMap, TEXT("Roughness"));
	bLumenValidParam.Bind(Initializer.ParameterMap, TEXT("bLumenValid"));
	LumenGridZParamsParam.Bind(Initializer.ParameterMap, TEXT("LumenGridZParams"));
	LumenGridSizeParam.Bind(Initializer.ParameterMap, TEXT("LumenGridSize"));
	LumenVolume0Param.Bind(Initializer.ParameterMap, TEXT("LumenVolume0"));
	LumenVolume1Param.Bind(Initializer.ParameterMap, TEXT("LumenVolume1"));
	LumenVolumeSamplerParam.Bind(Initializer.ParameterMap, TEXT("LumenVolumeSampler"));
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

	BindSurface(ShaderElementData.Surface, BaseColorParam, MetallicParam, RoughnessParam, ShaderBindings);

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
}

// ---------------------------------------------------------------------------
// FCustomMeshPassGBufferPS

FCustomMeshPassGBufferPS::FCustomMeshPassGBufferPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
	: FCustomMeshPassShader(Initializer)
{
	BaseColorParam.Bind(Initializer.ParameterMap, TEXT("BaseColor"));
	MetallicParam.Bind(Initializer.ParameterMap, TEXT("Metallic"));
	RoughnessParam.Bind(Initializer.ParameterMap, TEXT("Roughness"));
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

	BindSurface(ShaderElementData.Surface, BaseColorParam, MetallicParam, RoughnessParam, ShaderBindings);
}
