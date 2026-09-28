#pragma once

#include "CoreMinimal.h"
#include "CustomMeshPassTypes.h"

class FPrimitiveSceneProxy;

/** 游戏线程 → 渲染线程的一条绘制记录（Proxy 只在渲染线程解引用） */
struct FCustomMeshPassDrawItem
{
	const FPrimitiveSceneProxy* Proxy = nullptr;
	FCustomMeshPassSurface Surface;
};
