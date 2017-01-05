// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetingSystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "RemoteManipulatorComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values for this component's properties
URemoteManipulatorComponent::URemoteManipulatorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URemoteManipulatorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void URemoteManipulatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URemoteManipulatorComponent::AddImpulseToTargetAlongForwardVector(float ImpulseAmount)
{
	if (CurrentTargetPrimitiveRoot)
	{
		CurrentTargetPrimitiveRoot->AddImpulse(this->GetForwardVector() * ImpulseAmount * BaseImpulseScale);
	}
}

void URemoteManipulatorComponent::AddImpulseToTargetTowardWorldLocation(FVector Location, float ImpulseAmount)
{
	if (CurrentTargetPrimitiveRoot)
	{
		FVector DirectionVector = UKismetMathLibrary::FindLookAtRotation(CurrentTargetPrimitiveRoot->GetComponentLocation(), Location).Vector();
		CurrentTargetPrimitiveRoot->AddImpulse(DirectionVector * ImpulseAmount * BaseImpulseScale);
	}
}

void URemoteManipulatorComponent::AddForceToTargetAlongForwardVector(float ForceScale)
{
	if (CurrentTargetPrimitiveRoot)
	{
		CurrentTargetPrimitiveRoot->AddForce(this->GetForwardVector() * ForceScale * BaseForceScale);
	}
}

void URemoteManipulatorComponent::AddForceToTargetTowardWorldLocation(FVector Location, float ForceScale)
{
	if (CurrentTargetPrimitiveRoot)
	{
		FVector DirectionVector = UKismetMathLibrary::FindLookAtRotation(CurrentTargetPrimitiveRoot->GetComponentLocation(), Location).Vector();
		CurrentTargetPrimitiveRoot->AddForce(DirectionVector * ForceScale * BaseForceScale);
	}
}

void URemoteManipulatorComponent::ToggleCurrentTargetGravity()
{
	if (CurrentTargetPrimitiveRoot)
	{
		CurrentTargetPrimitiveRoot->SetEnableGravity(!CurrentTargetPrimitiveRoot->IsGravityEnabled());
	}
}

void URemoteManipulatorComponent::DampenTargetForces(float DampeningAmount)
{
	if (CurrentTargetPrimitiveRoot)
	{
		const FVector vel = CurrentTargetPrimitiveRoot->GetPhysicsLinearVelocity();
		if (vel.Size() >= DampeningAmount)
		{
			CurrentTargetPrimitiveRoot->AddImpulse(-1 * DampeningAmount * vel);
		}
		else
		{
			CurrentTargetPrimitiveRoot->SetAllPhysicsLinearVelocity(FVector::ZeroVector);
		}
	}
}

void URemoteManipulatorComponent::SetCurrentTarget(AActor* NewTarget)
{
	if (NewTarget)
	{
		UPrimitiveComponent* Primitive = Cast<UPrimitiveComponent>(NewTarget->GetRootComponent());
		if (Primitive)
		{
			if (NewTarget->GetRootComponent()->IsSimulatingPhysics())
			{
				CurrentTarget = NewTarget;
				CurrentTargetPrimitiveRoot = Primitive;
			}
		}
	}
}

