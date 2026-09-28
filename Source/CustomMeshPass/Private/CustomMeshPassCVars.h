#pragma once

#include "CoreMinimal.h"
#include "CustomMeshPassTypes.h"

/** 本帧实际要走的渲染路径（已结合平台能力做过回退） */
enum class ECustomMeshPassRenderPath : uint8
{
	Disabled,
	DeferredGBuffer,
	Forward,
};

/**
 * r.CustomMeshPass / r.CustomMeshPass.LightingPath 的唯一访问入口
 * 设置页、蓝图 API、渲染代码都只通过这里读写，避免各处直接碰 CVar
 */
namespace CustomMeshPass::CVars
{
	bool IsEnabled_GameThread();
	void SetEnabled(bool bEnabled);

	ECustomMeshPassLightingPath GetLightingPath_GameThread();
	void SetLightingPath(ECustomMeshPassLightingPath Path);

	ECustomMeshPassRenderPath ResolveRenderPath_RenderThread();
}
