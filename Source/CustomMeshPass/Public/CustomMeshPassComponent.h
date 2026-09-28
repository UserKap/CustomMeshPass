#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CustomMeshPassTypes.h"
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

	/** 拷贝一份表面参数给渲染线程 */
	FCustomMeshPassSurface GetSurface() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material")
	FLinearColor BaseColor = FLinearColor(0.1f, 0.85f, 0.3f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material", meta = (ClampMin = "0", ClampMax = "1"))
	float Metallic = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomMeshPass|Material", meta = (ClampMin = "0.02", ClampMax = "1"))
	float Roughness = 0.45f;
};
