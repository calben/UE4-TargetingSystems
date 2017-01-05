// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/TargetingSystemComponent.h"
#include "ConicalTargetingSystemComponent.generated.h"

/**
 *
 */
UCLASS()
class TARGETINGSYSTEMS_API UConicalTargetingSystemComponent : public UTargetingSystemComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RadiusAtStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RadiusAtEnd;

	virtual void SetCurrentTarget() override;
};
