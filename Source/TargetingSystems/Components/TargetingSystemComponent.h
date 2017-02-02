// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "TargetingSystemComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TARGETINGSYSTEMS_API UTargetingSystemComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTargetingSystemComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsTargeting = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class AActor* CurrentTarget;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class AActor* PreviousTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bDrawDebug = false;

	UFUNCTION(BlueprintCallable, Category = Targeting)
		virtual void SetCurrentTarget();

	UFUNCTION(BlueprintCallable, Category = Targeting)
		void OnTargetChanged();

	UFUNCTION(BlueprintCallable, Category = Rendering)
		void UpdateHighlighting();

};
