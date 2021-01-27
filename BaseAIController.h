// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Components/SphereComponent.h"
#include "BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class CANARY_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

public:
	ABaseAIController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* DetectionRadius;

protected:
	virtual void BeginPlay() override;

private:

	
};
