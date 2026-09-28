#pragma once

#include "CoreMinimal.h"
#include "MeshPassProcessor.h"
#include "CustomMeshPassShaders.h"

enum class ECustomMeshPassDrawMode : uint8
{
	/** PrePostProcess：自写 BRDF，直接输出到 SceneColor */
	ForwardCustomBRDF,
	/** PostRenderBasePassDeferred：写 GBuffer，由 Deferred + Lumen 照亮 */
	WriteGBufferForLumen,
};

/**
 * 把 FMeshBatch 转成 FMeshDrawCommand
 * 材质固定用默认表面材质（只借用它的顶点工厂/几何输入），颜色参数来自 CurrentElementData
 */
class FCustomMeshPassMeshProcessor : public FMeshPassProcessor
{
public:
	FCustomMeshPassMeshProcessor(
		const FScene* InScene,
		const FSceneView* InView,
		FMeshPassDrawListContext* InDrawListContext,
		ECustomMeshPassDrawMode InDrawMode);

	virtual void AddMeshBatch(
		const FMeshBatch& RESTRICT MeshBatch,
		uint64 BatchElementMask,
		const FPrimitiveSceneProxy* RESTRICT PrimitiveSceneProxy,
		int32 StaticMeshId = -1) override;

	/** 下一次 AddMeshBatch 使用的参数，调用方逐物体设置 */
	FCustomMeshPassShaderElementData CurrentElementData;

private:
	template<typename PixelShaderType>
	void BuildCommands(
		const FMeshBatch& MeshBatch,
		uint64 BatchElementMask,
		const FPrimitiveSceneProxy* PrimitiveSceneProxy,
		const FMaterialRenderProxy& MaterialRenderProxy,
		const FMaterial& Material,
		const FMaterialShaders& Shaders,
		const FCustomMeshPassShaderElementData& ElementData);

	FMeshPassProcessorRenderState PassDrawRenderState;
	ECustomMeshPassDrawMode DrawMode;
};
