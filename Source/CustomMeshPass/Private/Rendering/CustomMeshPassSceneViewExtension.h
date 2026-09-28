#pragma once

#include "CoreMinimal.h"
#include "SceneViewExtension.h"
#include "CustomMeshPassDrawItem.h"

/**
 * 只负责「什么时候画」：收集本帧物体 → 按渲染路径分派到对应 Pass
 * 「怎么画」在 CustomMeshPassPasses / CustomMeshPassMeshProcessor 里
 *
 * - DeferredGBuffer：PostRenderBasePassDeferred 写 GBuffer，接入 Deferred + Lumen
 * - Forward：PrePostProcess 自写 BRDF
 */
class FCustomMeshPassSceneViewExtension : public FWorldSceneViewExtension
{
public:
	FCustomMeshPassSceneViewExtension(const FAutoRegister& AutoRegister, UWorld* InWorld);

	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override {}
	virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) override {}
	/** 游戏线程；此时 SendAllEndOfFrameUpdates 已执行，SceneProxy 是本帧最新的 */
	virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) override;
	virtual void PostRenderViewFamily_RenderThread(FRDGBuilder& GraphBuilder, FSceneViewFamily& InViewFamily) override;

	virtual void PostRenderBasePassDeferred_RenderThread(
		FRDGBuilder& GraphBuilder,
		FSceneView& InView,
		const FRenderTargetBindingSlots& RenderTargets,
		TRDGUniformBufferRef<FSceneTextureUniformParameters> SceneTextures) override;

	virtual void PrePostProcessPass_RenderThread(
		FRDGBuilder& GraphBuilder,
		const FSceneView& View,
		const FPostProcessingInputs& Inputs) override;

	virtual bool IsActiveThisFrame_Internal(const FSceneViewExtensionContext& Context) const override;

private:
	/** 只在渲染线程读写；由 BeginRenderViewFamily 通过渲染命令写入 */
	TArray<FCustomMeshPassDrawItem> DrawItems_RenderThread;
};
