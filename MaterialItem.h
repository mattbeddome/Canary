// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CanaryItem.h"
#include "MaterialItem.generated.h"

/**
 * 
 */
UCLASS()
class CANARY_API UMaterialItem : public UCanaryItem
{
	GENERATED_BODY()
	
public:
	UMaterialItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Properties")
		uint8 stackLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Properties")
		uint8 quantity;

};
