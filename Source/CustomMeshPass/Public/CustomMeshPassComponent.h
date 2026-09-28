#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CustomMeshPassTypes.h"
#include "Engine/Texture2D.h"
#include "CustomMeshPassComponent.generated.h"

/**
 * 由 CustomMeshPass 绘制的 StaticMeshComponent。
 * bRenderInMainPass=false：不进默认 Deferred 材质光照。
 * bRenderInDepthPass=true：写深度，供自定义 Pass / GBuffer 写入做深度测试。
 *
 * 光照路径在 项目设置 → 插件 → Custom Mesh Pass 切换（等价于控制台 r.CustomMeshPass.LightingPath）：
 * - ForwardCustom (0)：PrePostProcess 自写 BRDF
 * - DeferredLumen (1)：写 GBuffer → Deferred + Lumen
 *
 * 材质槽仍被 DepthPass / 阴影 / 拾取使用，请保持不透明、无 WPO 的材质，否则深度会与本 Pass 不一致。
 */
UCLASS(ClassGroup = (Rendering), meta = (BlueprintSpawnableComponent), Blueprintable)
class CUSTOMMESHPASS_API UCustomMeshPassComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UCustomMeshPassComponent();

	virtual void OnRegister() override;
	virtual void OnUnregister() override;

	/** 本帧是否应由 CustomMeshPass 绘制（可见且已创建 SceneProxy） */
	bool ShouldDrawWithCustomMeshPass() const;

	/** 拷贝标量表面参数。贴图由渲染层在同一帧另取 TextureRHI */
	FCustomMeshPassSurface GetSurface() const;

	/** 线性颜色。有 BaseMap 时与贴图相乘；BaseMap 请打开 sRGB */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material")
	FLinearColor BaseColor = FLinearColor(0.1f, 0.85f, 0.3f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material")
	TObjectPtr<UTexture2D> BaseMap;

	/** 切线空间法线。关闭 sRGB；导入时的 Flip Green Channel 已烘焙进纹理，着色器不再翻转 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material")
	TObjectPtr<UTexture2D> NormalMap;

	/** 法线贴图强度：0 = 完全平面，1 = 原图，大于 1 加强凹凸。没有 NormalMap 时无效 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material", meta = (ClampMin = "0", UIMax = "4"))
	float NormalStrength = 1.0f;

	/** 没有贴图时使用。有 MetallicMap 时被贴图的 R 通道替换 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material", meta = (ClampMin = "0", ClampMax = "1"))
	float Metallic = 0.0f;

	/** 关闭 sRGB，使用 R 通道。指定后替换 Metallic */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material")
	TObjectPtr<UTexture2D> MetallicMap;

	/** 电介质高光强度，默认 0.5（F0 = 0.08 * Specular = 0.04） */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material", meta = (ClampMin = "0", ClampMax = "1"))
	float Specular = 0.5f;

	/** 没有贴图时使用。有 RoughnessMap 时被贴图的 R 通道替换 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material", meta = (ClampMin = "0.02", ClampMax = "1"))
	float Roughness = 0.45f;

	/** 关闭 sRGB，使用 R 通道。指定后替换 Roughness */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material")
	TObjectPtr<UTexture2D> RoughnessMap;

	/** 没有贴图时使用，默认 1。有 AOMap 时被贴图的 R 通道替换。只压间接光 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material", meta = (ClampMin = "0", ClampMax = "1"))
	float AmbientOcclusion = 1.0f;

	/** 环境光遮蔽，关闭 sRGB，使用 R 通道 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material")
	TObjectPtr<UTexture2D> AOMap;

	/** 自发光（线性）。前向直接加到颜色上；GBuffer 路径以加法写入 SceneColor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material")
	FLinearColor Emissive = FLinearColor(0.0f, 0.0f, 0.0f, 1.0f);

	/** 所有贴图采样用的网格 UV 通道（0 = UV0）。超过网格已有的通道数时退回最后一个通道 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material|UV", meta = (ClampMin = "0", ClampMax = "7"))
	int32 UVChannel = 0;

	/** 贴图重复次数（Tiling），所有贴图共用。UV = MeshUV * UVTiling + UVOffset */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material|UV")
	FVector2D UVTiling = FVector2D(1.0, 1.0);

	/** 贴图偏移，在 Tiling 之后叠加 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material|UV")
	FVector2D UVOffset = FVector2D::ZeroVector;
};
