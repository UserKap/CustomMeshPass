#include "CustomMeshPassComponent.h"
#include "CustomMeshPassSubsystem.h"
#include "Engine/World.h"

/*	
	设置组件属性：
	1. 不渲染在主渲染Pass中
	2. 渲染在深度Pass中
	3. 不接收Decals
*/
UCustomMeshPassComponent::UCustomMeshPassComponent()
{
	// 不渲染在主渲染Pass中
	bRenderInMainPass = false;
	// 渲染在深度Pass中
	bRenderInDepthPass = true;
	// 不接收Decals
	bReceivesDecals = false;
}

/*	
	注册组件：
	1. 获取World
	2. 获取CustomMeshPassSubsystem
	3. 注册组件
*/
void UCustomMeshPassComponent::OnRegister()
{
	// 调用静态网格体组件注册方法
	Super::OnRegister();
	// 获取World
	if (UWorld* World = GetWorld())
	{
		if (UCustomMeshPassSubsystem* Subsystem = World->GetSubsystem<UCustomMeshPassSubsystem>())
		{
			Subsystem->RegisterComponent(this);
		}
	}
}

/*	
	注销组件：
	1. 获取World
	2. 获取CustomMeshPassSubsystem
	3. 注销组件
*/
void UCustomMeshPassComponent::OnUnregister()
{
	if (UWorld* World = GetWorld())
	{
		if (UCustomMeshPassSubsystem* Subsystem = World->GetSubsystem<UCustomMeshPassSubsystem>())
		{
			Subsystem->UnregisterComponent(this);
		}
	}
	// 调用父类注销方法
	Super::OnUnregister();
}

bool UCustomMeshPassComponent::ShouldDrawWithCustomMeshPass() const
{
	return IsVisible() && SceneProxy != nullptr;
}

FCustomMeshPassSurface UCustomMeshPassComponent::GetSurface() const
{
	FCustomMeshPassSurface Surface;
	Surface.BaseColor = FVector3f(BaseColor.R, BaseColor.G, BaseColor.B);
	Surface.Metallic = Metallic;
	Surface.Specular = Specular;
	Surface.Roughness = Roughness;
	Surface.AmbientOcclusion = AmbientOcclusion;
	Surface.Emissive = FVector3f(Emissive.R, Emissive.G, Emissive.B);
	Surface.NormalStrength = FMath::Max(NormalStrength, 0.0f);
	Surface.UVChannel = (uint32)FMath::Clamp(UVChannel, 0, 7);
	Surface.UVTiling = FVector2f(UVTiling);
	Surface.UVOffset = FVector2f(UVOffset);
	return Surface;
}
