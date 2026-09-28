#pragma once

#include "CoreMinimal.h"
#include "MeshMaterialShader.h"
#include "CustomMeshPassTypes.h"

/** 与 CustomMeshPassSurface.ush 的 CMP_MAP_* 一致 */
namespace CustomMeshPassSurfaceMap
{
	constexpr uint32 Base = 1u << 0;
	constexpr uint32 Normal = 1u << 1;
	constexpr uint32 AO = 1u << 2;
	constexpr uint32 Roughness = 1u << 3;
	constexpr uint32 Metallic = 1u << 4;
}

/** 每次绘制传给 Shader 的参数：表面参数 + 贴图 + 前向路径用的 Lumen 体积 */
struct FCustomMeshPassShaderElementData : public FMeshMaterialShaderElementData
{
	FCustomMeshPassSurface Surface;

	/** 空指针 = 该槽无贴图。绘制期间由 DrawItem 的 FTextureRHIRef 保住寿命 */
	FRHITexture* BaseMap = nullptr;
	FRHITexture* NormalMap = nullptr;
	FRHITexture* AOMap = nullptr;
	FRHITexture* RoughnessMap = nullptr;
	FRHITexture* MetallicMap = nullptr;

	FRHITexture* LumenVolume0 = nullptr;
	FRHITexture* LumenVolume1 = nullptr;
	FVector3f LumenGridZParams = FVector3f::ZeroVector;
	FIntVector LumenGridSize = FIntVector::ZeroValue;
	uint32 bLumenValid = 0;

	/** 前向局部光源（Light Grid），只有 ForwardPS 使用 */
	FRHIUniformBuffer* ForwardLightUniformBuffer = nullptr;
};

/**
 * 共同基类
 * 只为 默认表面材质 × FLocalVertexFactory 编译，避免给项目里每个材质都生成一份变体
 */
class FCustomMeshPassShader : public FMeshMaterialShader
{
public:
	FCustomMeshPassShader() = default;
	FCustomMeshPassShader(const FMeshMaterialShaderType::CompiledShaderInitializerType& Initializer);

	static bool ShouldCompilePermutation(const FMeshMaterialShaderPermutationParameters& Parameters);
};

/** 两条路径共用；UV 通道选择与 Tiling / Offset 在这里算好再插值 */
class FCustomMeshPassVS : public FCustomMeshPassShader
{
	DECLARE_SHADER_TYPE(FCustomMeshPassVS, MeshMaterial);

public:
	FCustomMeshPassVS() = default;
	FCustomMeshPassVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer);

	void GetShaderBindings(
		const FScene* Scene,
		ERHIFeatureLevel::Type FeatureLevel,
		const FPrimitiveSceneProxy* PrimitiveSceneProxy,
		const FMaterialRenderProxy& MaterialRenderProxy,
		const FMaterial& Material,
		const FCustomMeshPassShaderElementData& ShaderElementData,
		FMeshDrawSingleShaderBindings& ShaderBindings) const;

private:
	LAYOUT_FIELD(FShaderParameter, UVChannelParam);
	LAYOUT_FIELD(FShaderParameter, UVTilingOffsetParam);
};

/** 前向：自写 BRDF（主方向光 + Light Grid 局部光源）+ Lumen 半透明 GI 体积 / 天光 SH */
class FCustomMeshPassForwardPS : public FCustomMeshPassShader
{
	DECLARE_SHADER_TYPE(FCustomMeshPassForwardPS, MeshMaterial);

public:
	FCustomMeshPassForwardPS() = default;
	FCustomMeshPassForwardPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer);

	static void ModifyCompilationEnvironment(const FMeshMaterialShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment);

	void GetShaderBindings(
		const FScene* Scene,
		ERHIFeatureLevel::Type FeatureLevel,
		const FPrimitiveSceneProxy* PrimitiveSceneProxy,
		const FMaterialRenderProxy& MaterialRenderProxy,
		const FMaterial& Material,
		const FCustomMeshPassShaderElementData& ShaderElementData,
		FMeshDrawSingleShaderBindings& ShaderBindings) const;

private:
	LAYOUT_FIELD(FShaderParameter, BaseColorParam);
	LAYOUT_FIELD(FShaderParameter, MetallicParam);
	LAYOUT_FIELD(FShaderParameter, SpecularParam);
	LAYOUT_FIELD(FShaderParameter, RoughnessParam);
	LAYOUT_FIELD(FShaderParameter, AmbientOcclusionParam);
	LAYOUT_FIELD(FShaderParameter, EmissiveParam);
	LAYOUT_FIELD(FShaderParameter, NormalStrengthParam);
	LAYOUT_FIELD(FShaderParameter, SurfaceMapMaskParam);
	LAYOUT_FIELD(FShaderResourceParameter, BaseMapParam);
	LAYOUT_FIELD(FShaderResourceParameter, NormalMapParam);
	LAYOUT_FIELD(FShaderResourceParameter, AOMapParam);
	LAYOUT_FIELD(FShaderResourceParameter, RoughnessMapParam);
	LAYOUT_FIELD(FShaderResourceParameter, MetallicMapParam);
	LAYOUT_FIELD(FShaderResourceParameter, SurfaceSamplerParam);
	LAYOUT_FIELD(FShaderParameter, bLumenValidParam);
	LAYOUT_FIELD(FShaderParameter, LumenGridZParamsParam);
	LAYOUT_FIELD(FShaderParameter, LumenGridSizeParam);
	LAYOUT_FIELD(FShaderResourceParameter, LumenVolume0Param);
	LAYOUT_FIELD(FShaderResourceParameter, LumenVolume1Param);
	LAYOUT_FIELD(FShaderResourceParameter, LumenVolumeSamplerParam);
};

/** GBuffer：写表面属性，自发光加法进 SceneColor，光照交给 Deferred + Lumen */
class FCustomMeshPassGBufferPS : public FCustomMeshPassShader
{
	DECLARE_SHADER_TYPE(FCustomMeshPassGBufferPS, MeshMaterial);

public:
	FCustomMeshPassGBufferPS() = default;
	FCustomMeshPassGBufferPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer);

	void GetShaderBindings(
		const FScene* Scene,
		ERHIFeatureLevel::Type FeatureLevel,
		const FPrimitiveSceneProxy* PrimitiveSceneProxy,
		const FMaterialRenderProxy& MaterialRenderProxy,
		const FMaterial& Material,
		const FCustomMeshPassShaderElementData& ShaderElementData,
		FMeshDrawSingleShaderBindings& ShaderBindings) const;

private:
	LAYOUT_FIELD(FShaderParameter, BaseColorParam);
	LAYOUT_FIELD(FShaderParameter, MetallicParam);
	LAYOUT_FIELD(FShaderParameter, SpecularParam);
	LAYOUT_FIELD(FShaderParameter, RoughnessParam);
	LAYOUT_FIELD(FShaderParameter, AmbientOcclusionParam);
	LAYOUT_FIELD(FShaderParameter, EmissiveParam);
	LAYOUT_FIELD(FShaderParameter, NormalStrengthParam);
	LAYOUT_FIELD(FShaderParameter, SurfaceMapMaskParam);
	LAYOUT_FIELD(FShaderResourceParameter, BaseMapParam);
	LAYOUT_FIELD(FShaderResourceParameter, NormalMapParam);
	LAYOUT_FIELD(FShaderResourceParameter, AOMapParam);
	LAYOUT_FIELD(FShaderResourceParameter, RoughnessMapParam);
	LAYOUT_FIELD(FShaderResourceParameter, MetallicMapParam);
	LAYOUT_FIELD(FShaderResourceParameter, SurfaceSamplerParam);
};
