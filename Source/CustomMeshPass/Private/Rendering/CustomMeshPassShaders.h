#pragma once

#include "CoreMinimal.h"
#include "MeshMaterialShader.h"
#include "CustomMeshPassTypes.h"

/** 每次绘制传给 Shader 的参数：表面参数 + 前向路径用的 Lumen 体积 */
struct FCustomMeshPassShaderElementData : public FMeshMaterialShaderElementData
{
	FCustomMeshPassSurface Surface;

	FRHITexture* LumenVolume0 = nullptr;
	FRHITexture* LumenVolume1 = nullptr;
	FVector3f LumenGridZParams = FVector3f::ZeroVector;
	FIntVector LumenGridSize = FIntVector::ZeroValue;
	uint32 bLumenValid = 0;
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

class FCustomMeshPassVS : public FCustomMeshPassShader
{
	DECLARE_SHADER_TYPE(FCustomMeshPassVS, MeshMaterial);

public:
	FCustomMeshPassVS() = default;
	FCustomMeshPassVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FCustomMeshPassShader(Initializer)
	{
	}
};

/** 前向：自写 BRDF + Lumen 半透明 GI 体积 / 天光 SH */
class FCustomMeshPassForwardPS : public FCustomMeshPassShader
{
	DECLARE_SHADER_TYPE(FCustomMeshPassForwardPS, MeshMaterial);

public:
	FCustomMeshPassForwardPS() = default;
	FCustomMeshPassForwardPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer);

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
	LAYOUT_FIELD(FShaderParameter, RoughnessParam);
	LAYOUT_FIELD(FShaderParameter, bLumenValidParam);
	LAYOUT_FIELD(FShaderParameter, LumenGridZParamsParam);
	LAYOUT_FIELD(FShaderParameter, LumenGridSizeParam);
	LAYOUT_FIELD(FShaderResourceParameter, LumenVolume0Param);
	LAYOUT_FIELD(FShaderResourceParameter, LumenVolume1Param);
	LAYOUT_FIELD(FShaderResourceParameter, LumenVolumeSamplerParam);
};

/** GBuffer：只写表面属性，光照交给 Deferred + Lumen */
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
	LAYOUT_FIELD(FShaderParameter, RoughnessParam);
};
