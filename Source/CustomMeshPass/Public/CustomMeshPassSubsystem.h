#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Templates/Function.h"
#include "CustomMeshPassTypes.h"
#include "CustomMeshPassSubsystem.generated.h"

class UCustomMeshPassComponent;
class FCustomMeshPassSceneViewExtension;

/**
 * CustomMeshPass 的 WorldSubsystem。
 * WorldSubsystem 是UE5中新增的系统，用于管理世界中的子系统。
 * 管理 CustomMeshPassComponent 和 FCustomMeshPassSceneViewExtension。
 * 另外向蓝图暴露开关 / 光照路径（底层是全局 CVar，对所有 World 生效）。
 */
UCLASS()
class CUSTOMMESHPASS_API UCustomMeshPassSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void RegisterComponent(UCustomMeshPassComponent* Component);
	void UnregisterComponent(UCustomMeshPassComponent* Component);

	const TArray<TWeakObjectPtr<UCustomMeshPassComponent>>& GetComponents() const { return Components; }

	/** 遍历本帧需要绘制的组件（已过滤无效 / 隐藏 / 没有 SceneProxy 的） */
	void ForEachDrawableComponent(TFunctionRef<void(const UCustomMeshPassComponent&)> Func) const;

	/** 总开关，等价于 r.CustomMeshPass（以 SetByCode 优先级写入，会覆盖项目设置） */
	UFUNCTION(BlueprintCallable, Category = "CustomMeshPass")
	void SetEnabled(bool bEnabled);

	UFUNCTION(BlueprintPure, Category = "CustomMeshPass")
	bool IsEnabled() const;

	/** 光照路径，等价于 r.CustomMeshPass.LightingPath（以 SetByCode 优先级写入，会覆盖项目设置） */
	UFUNCTION(BlueprintCallable, Category = "CustomMeshPass")
	void SetLightingPath(ECustomMeshPassLightingPath Path);

	UFUNCTION(BlueprintPure, Category = "CustomMeshPass")
	ECustomMeshPassLightingPath GetLightingPath() const;

	/** 当前 World 注册的组件数（含隐藏的） */
	UFUNCTION(BlueprintPure, Category = "CustomMeshPass")
	int32 GetRegisteredComponentCount() const;

private:
	TSharedPtr<FCustomMeshPassSceneViewExtension, ESPMode::ThreadSafe> ViewExtension;
	TArray<TWeakObjectPtr<UCustomMeshPassComponent>> Components;
};
