#include "CustomMeshPassActor.h"
#include "CustomMeshPassComponent.h"

ACustomMeshPassActor::ACustomMeshPassActor()
{
	PrimaryActorTick.bCanEverTick = false;
	MeshComponent = CreateDefaultSubobject<UCustomMeshPassComponent>(TEXT("CustomMeshPassMesh"));
	SetRootComponent(MeshComponent);
}
