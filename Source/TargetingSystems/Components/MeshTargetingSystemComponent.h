// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/TargetingSystemComponent.h"
#include "MeshTargetingSystemComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TARGETINGSYSTEMS_API UMeshTargetingSystemComponent : public UTargetingSystemComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMeshTargetingSystemComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StaticMesh;

	virtual void SetCurrentTarget() override;


};
