#pragma once

#include "CoreMinimal.h"
#include "CustomMeshPassTypes.h"
#include "RHIResources.h"

class FPrimitiveSceneProxy;

/** 游戏线程 → 渲染线程的一条绘制记录（Proxy 只在渲染线程解引用） */
struct FCustomMeshPassDrawItem
{
	const FPrimitiveSceneProxy* Proxy = nullptr;
	FCustomMeshPassSurface Surface;

	/** 空引用表示该槽没有贴图，着色器用 Surface 里的标量。引用保住这一帧的 RHI 纹理 */
	FTextureRHIRef BaseMap;
	FTextureRHIRef NormalMap;
	FTextureRHIRef AOMap;
	FTextureRHIRef RoughnessMap;
	FTextureRHIRef MetallicMap;
};
