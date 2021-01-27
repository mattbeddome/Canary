// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CanaryItem.h"
#include "WeaponActor.h"
#include "WeaponItem.generated.h"

UENUM(BlueprintType)
enum class EWeaponQuality : uint8
{
	enum_Rusty UMETA(DisplayName = "Rusty"),	// Later, make an arm armour called a Shackleford, that only comes in 'Rusty'
	enum_Lousy UMETA(DisplayName = "Lousy"),
	enum_Normal UMETA(DisplayName = "Normal"),
	enum_Fine UMETA(DisplayName = "Fine"),
	enum_Flawless UMETA(DisplayName = "Flawless")
};

UCLASS()
class CANARY_API UWeaponItem : public UCanaryItem
{
	GENERATED_BODY()
	
public:
	UWeaponItem();
	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AWeaponActor> WeaponBlueprint;
	*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties", meta = (AllowPrivateAccess = "true"))
		EWeaponQuality WeaponQuality;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties", meta = (AllowPrivateAccess = "true"))
		int32 WeaponDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties", meta = (AllowPrivateAccess = "true"))
		float WeaponSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Abilities")
		TSubclassOf<class UGameplayAbility> LightAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Abilities")
		TSubclassOf<class UGameplayAbility> HeavyAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Abilities")
		TSubclassOf<class UGameplayAbility> Block;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Abilities")
		TSubclassOf<class UGameplayAbility> Parry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Abilities")
		TArray<TSubclassOf<class UGameplayAbility>> AddedEffects;

};
