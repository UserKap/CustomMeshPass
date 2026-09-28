#pragma once

#include "CoreMinimal.h"
#include "RenderGraphDefinitions.h"
#include "CustomMeshPassDrawItem.h"

class FRDGBuilder;
class FSceneView;
struct FRenderTargetBindingSlots;
struct FPostProcessingInputs;

namespace CustomMeshPass
{
	/** 在 BasePass 之后复用其 MRT 写 GBuffer（深度改为可写） */
	void AddGBufferPass(
		FRDGBuilder& GraphBuilder,
		const FSceneView& View,
		const FRenderTargetBindingSlots& BasePassRenderTargets,
		const TArray<FCustomMeshPassDrawItem>& Items);

	/** 在后处理之前用自写 BRDF 直接画进 SceneColor */
	void AddForwardPass(
		FRDGBuilder& GraphBuilder,
		const FSceneView& View,
		const FPostProcessingInputs& Inputs,
		const TArray<FCustomMeshPassDrawItem>& Items);
}
