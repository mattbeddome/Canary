// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CanaryItem.h"
#include "ConsumableItem.generated.h"

/**
 * 
 */
UCLASS()
class CANARY_API UConsumableItem : public UCanaryItem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TSubclassOf<class UGameplayAbility> ItemAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Properties")
		uint8 stackLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Properties")
		uint8 quantity;

protected:

private:

};
