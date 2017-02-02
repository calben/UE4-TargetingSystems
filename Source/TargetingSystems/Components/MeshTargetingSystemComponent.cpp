// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetingSystems.h"
#include "MeshTargetingSystemComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

// Sets default values for this component's properties
UMeshTargetingSystemComponent::UMeshTargetingSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetSimulatePhysics(false);
	StaticMesh->SetEnableGravity(false);
	StaticMesh->SetCollisionProfileName(FName("OverlapAll"));
	StaticMesh->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);

	// ...
}


// Called when the game starts
void UMeshTargetingSystemComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...

}


// Called every frame
void UMeshTargetingSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMeshTargetingSystemComponent::SetCurrentTarget()
{
	TArray<AActor*> Overlapping;
	StaticMesh->GetOverlappingActors(Overlapping, nullptr);
	CurrentTarget = nullptr;
	float distance = 999999.f;
	for (AActor* actor : Overlapping)
	{
		if (!actor->GetName().Contains("BP_MotionController"))
		{
			float d = UKismetMathLibrary::GetPointDistanceToSegment(actor->GetActorLocation(), GetComponentLocation(), GetComponentLocation() + GetForwardVector() * 99999.f);
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("OBJECT %s IS %f AWAY FROM CENTER LINE"), *actor->GetName(), d));
			if (d < distance)
			{
				distance = d;
				CurrentTarget = actor;
			}
		}
	}
}


