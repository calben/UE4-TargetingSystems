// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetingSystems.h"
#include "Actors/Marker.h"
#include "MarkerSystemComponent.h"


// Sets default values for this component's properties
UMarkerSystemComponent::UMarkerSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMarkerSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMarkerSystemComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UMarkerSystemComponent::DeployMarker(FVector WorldLocation, FRotator WorldRotation)
{
	if (!bMultipleMarkerMode)
	{
		for(AActor* actor : DeployedMarkers)
		{
			actor->Destroy();
		}
		DeployedMarkers.Empty();
	}
	AMarker* NewMarker = GetWorld()->SpawnActor<AMarker>(WorldLocation, WorldRotation);
	this->DeployedMarkers.Add(NewMarker);
}

