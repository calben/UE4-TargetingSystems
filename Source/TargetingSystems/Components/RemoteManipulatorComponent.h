// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "RemoteManipulatorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TARGETINGSYSTEMS_API URemoteManipulatorComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URemoteManipulatorComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsManipulating;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bMovedTargetAboutManipulatorRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BaseImpulseScale = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BaseForceScale = 1000;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class AActor* CurrentTarget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UPrimitiveComponent* CurrentTargetPrimitiveRoot;

	UFUNCTION(BlueprintCallable, Category = Manipulating)
		void AddImpulseToTargetAlongForwardVector(float ImpulseAmount);

	UFUNCTION(BlueprintCallable, Category = Manipulating)
		void AddImpulseToTargetTowardWorldLocation(FVector Location, float ImpulseAmount);

	UFUNCTION(BlueprintCallable, Category = Manipulating)
		void AddForceToTargetAlongForwardVector(float ForceScale);

	UFUNCTION(BlueprintCallable, Category = Manipulating)
		void AddForceToTargetTowardWorldLocation(FVector Location, float ForceScale);

	UFUNCTION(BlueprintCallable, Category = Manipulating)
		void ToggleCurrentTargetGravity();

	UFUNCTION(BlueprintCallable, Category = Manipulating)
		void DampenTargetForces(float DampeningAmount);

	UFUNCTION(BlueprintCallable, Category = Manipulating)
		void SetCurrentTarget(class AActor* NewTarget);
};
