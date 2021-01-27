// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "Engine/DataAsset.h"
#include "CanaryItem.generated.h"

UENUM(BlueprintType)
enum class FItemRarity : uint8
{	// Mythic is reserved for only the final weapons/armour		// border colours
	enum_Common UMETA(DisplayName = "Common"),					// grey
	enum_Uncommon UMETA(DisplayName = "Uncommon"),				// bronze
	enum_Rare UMETA(DisplaytName = "Rare"),						// silver
	enum_Legendary UMETA(DisplayName = "Legendary"),			// gold
	enum_Mythic UMETA(DisplayName = "Mythic")					// glowing white
};


UCLASS()
class CANARY_API UCanaryItem : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UCanaryItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | GUI", meta = (AllowPrivateAccess = "true"))
		UTexture2D* ItemIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | GUI", meta = (AllowPrivateAccess = "true"))
		FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | GUI", meta = (AllowPrivateAccess = "true"))
		FString ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties", meta = (AllowPrivateAccess = "true"))
		FItemRarity ItemRarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties", meta = (AllowPrivateAccess = "true"))
		int32 ItemGoldValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties", meta = (AllowPrivateAccess = "true"))
		uint8 StackMaximum;

};