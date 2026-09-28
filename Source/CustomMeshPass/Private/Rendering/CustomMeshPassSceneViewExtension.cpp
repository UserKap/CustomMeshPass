#include "CustomMeshPassSceneViewExtension.h"

#include "CustomMeshPassComponent.h"
#include "CustomMeshPassCVars.h"
#include "CustomMeshPassPasses.h"
#include "CustomMeshPassSubsystem.h"

#include "RenderingThread.h"

FCustomMeshPassSceneViewExtension::FCustomMeshPassSceneViewExtension(const FAutoRegister& AutoRegister, UWorld* InWorld)
	: FWorldSceneViewExtension(AutoRegister, InWorld)
{
}

bool FCustomMeshPassSceneViewExtension::IsActiveThisFrame_Internal(const FSceneViewExtensionContext& Context) const
{
	// 基类按 World 过滤：材质编辑器等预览视口属于别的 World，不应画本 World 的物体
	return FWorldSceneViewExtension::IsActiveThisFrame_Internal(Context)
		&& CustomMeshPass::CVars::IsEnabled_GameThread();
}

void FCustomMeshPassSceneViewExtension::BeginRenderViewFamily(FSceneViewFamily& InViewFamily)
{
	TArray<FCustomMeshPassDrawItem> Items;

	UWorld* WorldPtr = GetWorld();
	if (const UCustomMeshPassSubsystem* Subsystem = WorldPtr ? WorldPtr->GetSubsystem<UCustomMeshPassSubsystem>() : nullptr)
	{
		Subsystem->ForEachDrawableComponent([&Items](const UCustomMeshPassComponent& Comp)
		{
			FCustomMeshPassDrawItem& Item = Items.AddDefaulted_GetRef();
			Item.Proxy = Comp.SceneProxy;
			Item.Surface = Comp.GetSurface();
		});
	}

	// 渲染命令与本 ViewFamily 的渲染命令同序执行，保证渲染线程拿到的是与本帧场景一致的 Proxy
	TSharedRef<FCustomMeshPassSceneViewExtension, ESPMode::ThreadSafe> This =
		StaticCastSharedRef<FCustomMeshPassSceneViewExtension>(AsShared());
	ENQUEUE_RENDER_COMMAND(CustomMeshPassSetDrawItems)(
		[This, Items = MoveTemp(Items)](FRHICommandListImmediate&) mutable
		{
			This->DrawItems_RenderThread = MoveTemp(Items);
		});
}

void FCustomMeshPassSceneViewExtension::PostRenderViewFamily_RenderThread(FRDGBuilder& GraphBuilder, FSceneViewFamily& InViewFamily)
{
	// Proxy 可能在帧后被销毁，不留到下一次渲染
	DrawItems_RenderThread.Reset();
}

void FCustomMeshPassSceneViewExtension::PostRenderBasePassDeferred_RenderThread(
	FRDGBuilder& GraphBuilder,
	FSceneView& InView,
	const FRenderTargetBindingSlots& RenderTargets,
	TRDGUniformBufferRef<FSceneTextureUniformParameters> SceneTextures)
{
	if (DrawItems_RenderThread.IsEmpty()
		|| CustomMeshPass::CVars::ResolveRenderPath_RenderThread() != ECustomMeshPassRenderPath::DeferredGBuffer)
	{
		return;
	}

	CustomMeshPass::AddGBufferPass(GraphBuilder, InView, RenderTargets, DrawItems_RenderThread);
}

void FCustomMeshPassSceneViewExtension::PrePostProcessPass_RenderThread(
	FRDGBuilder& GraphBuilder,
	const FSceneView& View,
	const FPostProcessingInputs& Inputs)
{
	// GBuffer 路径生效时不再前向叠画；无经典 GBuffer 时 ResolveRenderPath 会回退到这里
	if (DrawItems_RenderThread.IsEmpty()
		|| CustomMeshPass::CVars::ResolveRenderPath_RenderThread() != ECustomMeshPassRenderPath::Forward)
	{
		return;
	}

	CustomMeshPass::AddForwardPass(GraphBuilder, View, Inputs, DrawItems_RenderThread);
}
