// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetingSystems.h"
#include "TargetingSystemComponent.h"


// Sets default values for this component's properties
UTargetingSystemComponent::UTargetingSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTargetingSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTargetingSystemComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (this->bIsTargeting)
		SetCurrentTarget();
	// ...
}


void UTargetingSystemComponent::SetCurrentTarget()
{
	FHitResult f(ForceInit);
	FVector start = this->GetComponentLocation();
	FVector direction = this->GetForwardVector();
	FCollisionQueryParams  params = FCollisionQueryParams(FName(TEXT("TargetingTrace")), true, NULL);
	params.bTraceAsyncScene = true;
	start = start + (direction * 100.0f);
	FVector end = start + (direction * 2000.0f);
	GetWorld()->LineTraceSingleByChannel(f, start, end, ECC_Visibility, params);
	// GetWorld()->DebugDrawTraceTag = "TargetingTrace";
	this->CurrentTarget = f.GetActor();
}
