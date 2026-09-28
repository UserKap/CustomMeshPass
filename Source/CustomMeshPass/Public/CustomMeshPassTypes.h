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

/**
 * 一个物体的标量表面参数（Default Lit）。
 * 贴图不放在这里：Public 头不依赖 RHI，纹理在渲染层另存 FTextureRHIRef。
 * 有对应贴图时用贴图，没有贴图时用这里的标量；BaseColor 在有 BaseMap 时作为颜色相乘。
 */
struct FCustomMeshPassSurface
{
	FVector3f BaseColor = FVector3f(0.1f, 0.85f, 0.3f);
	float Metallic = 0.0f;
	/** 电介质高光，0.5 对应 F0 = 0.04 */
	float Specular = 0.5f;
	float Roughness = 0.45f;
	float AmbientOcclusion = 1.0f;
	FVector3f Emissive = FVector3f::ZeroVector;

	/** 法线贴图强度：0 = 平面，1 = 原图 */
	float NormalStrength = 1.0f;

	/** 所有贴图共用的网格 UV 通道与变换：UV = MeshUV[UVChannel] * UVTiling + UVOffset */
	uint32 UVChannel = 0;
	FVector2f UVTiling = FVector2f(1.0f, 1.0f);
	FVector2f UVOffset = FVector2f::ZeroVector;
};
