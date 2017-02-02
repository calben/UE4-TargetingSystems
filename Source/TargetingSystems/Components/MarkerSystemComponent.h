// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "MarkerSystemComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TARGETINGSYSTEMS_API UMarkerSystemComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMarkerSystemComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bMultipleMarkerMode = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class TSubclassOf<class AActor> MarkerClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class AActor*> DeployedMarkers;

	UFUNCTION(BlueprintCallable, Category = Markers)
		void DeployMarker(FVector WorldLocation, FRotator WorldRotation);

};