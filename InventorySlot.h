// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CanaryItem.h"
#include "InventorySlot.generated.h"

/**
 * 
 */
UCLASS()
class CANARY_API UInventorySlot : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties")
		TSubclassOf<UCanaryItem> ItemInSlot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties")
		uint8 Quantity;
};
