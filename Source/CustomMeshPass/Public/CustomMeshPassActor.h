#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomMeshPassActor.generated.h"

class UCustomMeshPassComponent;

/** 拖进关卡即可：带自定义 Mesh Pass 的 StaticMesh Actor */
UCLASS(Blueprintable)
class CUSTOMMESHPASS_API ACustomMeshPassActor : public AActor
{
	GENERATED_BODY()

public:
	ACustomMeshPassActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CustomMeshPass")
	TObjectPtr<UCustomMeshPassComponent> MeshComponent;
};
