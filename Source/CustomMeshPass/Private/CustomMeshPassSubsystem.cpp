/*	
	该脚本作用是管理CustomMeshPass组件和视口扩展
*/
#include "CustomMeshPassSubsystem.h"
#include "CustomMeshPassComponent.h"
#include "CustomMeshPassCVars.h"
#include "CustomMeshPassModule.h"
#include "Rendering/CustomMeshPassSceneViewExtension.h"
#include "SceneViewExtension.h"

/*	
	初始化：
	1. 创建视口扩展
	2. 打印日志
*/
void UCustomMeshPassSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	// 创建视口扩展
	ViewExtension = FSceneViewExtensions::NewExtension<FCustomMeshPassSceneViewExtension>(GetWorld());
	UE_LOG(LogCustomMeshPass, Verbose, TEXT("Subsystem + SceneViewExtension ready for world %s."), *GetNameSafe(GetWorld()));
}

/*	
	注销：
	1. 重置视口扩展
	2. 重置组件
	3. 调用父类注销方法
*/
void UCustomMeshPassSubsystem::Deinitialize()
{
	ViewExtension.Reset();
	Components.Reset();
	Super::Deinitialize();
}

/*	
	注册组件：
	1. 如果组件有效，则添加到组件列表中
*/
void UCustomMeshPassSubsystem::RegisterComponent(UCustomMeshPassComponent* Component)
{ 
	if (Component)
	{
		// 添加组件到组件列表中
		Components.AddUnique(Component);
	}
}

/*	
	注销组件：
	1. 如果组件有效，则从组件列表中移除
*/
void UCustomMeshPassSubsystem::UnregisterComponent(UCustomMeshPassComponent* Component)
{
	Components.RemoveAll([Component](const TWeakObjectPtr<UCustomMeshPassComponent>& Ptr)
	{
		return !Ptr.IsValid() || Ptr.Get() == Component;
	});
}

/*
	遍历可绘制组件：
	1. 遍历组件列表
	2. 如果组件有效，则调用函数
*/
void UCustomMeshPassSubsystem::ForEachDrawableComponent(TFunctionRef<void(const UCustomMeshPassComponent&)> Func) const
{
	for (const TWeakObjectPtr<UCustomMeshPassComponent>& WeakComp : Components)
	{
		const UCustomMeshPassComponent* Comp = WeakComp.Get();
		if (Comp && Comp->ShouldDrawWithCustomMeshPass())
		{
			Func(*Comp);
		}
	}
}

void UCustomMeshPassSubsystem::SetEnabled(bool bEnabled)
{
	CustomMeshPass::CVars::SetEnabled(bEnabled);
}

bool UCustomMeshPassSubsystem::IsEnabled() const
{
	return CustomMeshPass::CVars::IsEnabled_GameThread();
}

void UCustomMeshPassSubsystem::SetLightingPath(ECustomMeshPassLightingPath Path)
{
	CustomMeshPass::CVars::SetLightingPath(Path);
}

ECustomMeshPassLightingPath UCustomMeshPassSubsystem::GetLightingPath() const
{
	return CustomMeshPass::CVars::GetLightingPath_GameThread();
}

int32 UCustomMeshPassSubsystem::GetRegisteredComponentCount() const
{
	int32 Count = 0;
	for (const TWeakObjectPtr<UCustomMeshPassComponent>& WeakComp : Components)
	{
		Count += WeakComp.IsValid() ? 1 : 0;
	}
	return Count;
}
