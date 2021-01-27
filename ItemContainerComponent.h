// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CanaryItem.h"
#include "WeaponItem.h"
#include "ArmourItem.h"
#include "ConsumableItem.h"
#include "MaterialItem.h"
#include "QuestItem.h"
#include "ItemContainerComponent.generated.h"

UCLASS()
class CANARY_API UItemContainerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UItemContainerComponent();

	/* Weapons */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Weapons | Pool", meta = (AllowPrivateAccess = "true"))
		TArray<TSubclassOf<UWeaponItem>> WeaponPool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Weapons | Quantity", meta = (ClampMin = "0.0", ClampMax = "10"))
		uint8 MinWeaponDrops;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Weapons | Quantity", meta = (ClampMin = "0.0", ClampMax = "10"))
		uint8 MaxWeaponDrops;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Weapons | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float CommonWeaponDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Weapons | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float UncommonWeaponDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Weapons | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float RareWeaponDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Weapons | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float LegendaryWeaponDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Weapons | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float MythicWeaponDropRate;

	/* Armour */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Armour | Pool", meta = (AllowPrivateAccess = "true"))
		TArray<TSubclassOf<UArmourItem>> ArmourPool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Armour | Quantity", meta = (ClampMin = "0.0", ClampMax = "10"))
		uint8 MinArmourDrops;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Armour | Quantity", meta = (ClampMin = "0.0", ClampMax = "10"))
		uint8 MaxArmourDrops;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Armour | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float CommonArmourDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Armour | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float UncommonArmourDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Armour | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float RareArmourDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Armour | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float LegendaryArmourDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Armour | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float MythicArmourDropRate;

	/* Consumables */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Consumables | Pool", meta = (AllowPrivateAccess = "true"))
		TArray<TSubclassOf<UConsumableItem>> ConsumablesPool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Consumables | Quantity", meta = (ClampMin = "0.0", ClampMax = "10"))
		uint8 MinConsumableDrops;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Consumables | Quantity", meta = (ClampMin = "0.0", ClampMax = "10"))
		uint8 MaxConsumableDrops;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Consumables | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float CommonConsumableDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Consumables | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float UncommonConsumableDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Consumables | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float RareConsumableDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Consumables | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float LegendaryConsumableDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Consumables | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float MythicConsumableDropRate;

	/* Materials */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Materials | Pool", meta = (AllowPrivateAccess = "true"))
		TArray<TSubclassOf<UMaterialItem>> MaterialsPool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Materials | Quantity", meta = (ClampMin = "0.0", ClampMax = "10"))
		uint8 MinMaterialDrops;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Materials | Quantity", meta = (ClampMin = "0.0", ClampMax = "10"))
		uint8 MaxMaterialDrops;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Materials | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float CommonMaterialDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Materials | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float UncommonMaterialDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Materials | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float RareMaterialDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Materials | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float LegendaryMaterialDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Materials | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float MythicMaterialDropRate;

	/* Quest Items */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Quest Items | Pool", meta = (AllowPrivateAccess = "true"))
		TArray<TSubclassOf<UQuestItem>> QuestItemPool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Quest Items | Quantity", meta = (ClampMin = "0.0", ClampMax = "10"))
		uint8 MinQuestDrops;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Quest Items | Quantity", meta = (ClampMin = "0.0", ClampMax = "10"))
		uint8 MaxQuestDrops;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Quest Items | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float CommonQuestDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Quest Items | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float UncommonQuestDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Quest Items | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float RareQuestDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Quest Items | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float LegendaryQuestDropRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot | Quest Items | Drop Rate", meta = (ClampMin = "0.0", ClampMax = "100"))
		float MythicQuestDropRate;
};
