#pragma once

#include "CoreMinimal.h"
#include "CustomMeshPassTypes.generated.h"

/** 光照路径，数值与 r.CustomMeshPass.LightingPath 一一对应 */
UENUM(BlueprintType)
enum class ECustomMeshPassLightingPath : uint8
{
	/** 自写 BRDF，在 PrePostProcess 直接画进 SceneColor（不接收阴影） */
	ForwardCustom = 0 UMETA(DisplayName = "Forward (Custom BRDF)"),
	/** 写 GBuffer，由引擎 Deferred + Lumen 照亮；平台无经典 GBuffer（如 Substrate）时自动回退前向 */
	DeferredLumen = 1 UMETA(DisplayName = "Deferred + Lumen (GBuffer)"),
};

/** 一个物体的表面参数，游戏线程从组件拷贝后交给渲染线程 */
struct FCustomMeshPassSurface
{
	FVector3f BaseColor = FVector3f(0.1f, 0.85f, 0.3f);
	float Metallic = 0.0f;
	float Roughness = 0.45f;
};
