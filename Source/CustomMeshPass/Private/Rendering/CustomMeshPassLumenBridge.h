#pragma once

#include "CoreMinimal.h"
#include "RenderGraphDefinitions.h"

class FRDGBuilder;
class FSceneView;

/** 前向路径采样用的 Lumen 半透明 GI 体积；不可用时 Volume0/1 是黑色 3D 纹理 */
struct FCustomMeshPassLumenVolume
{
	FRDGTextureRef Volume0 = nullptr;
	FRDGTextureRef Volume1 = nullptr;
	FVector3f GridZParams = FVector3f::ZeroVector;
	FIntVector GridSize = FIntVector::ZeroValue;
	bool bValid = false;
};

namespace CustomMeshPass
{
	/** 渲染器私有 Lumen 头只在这个函数的实现里出现，引擎升级时只需改这一处 */
	FCustomMeshPassLumenVolume GetLumenTranslucencyGIVolume(FRDGBuilder& GraphBuilder, const FSceneView& View);
}
