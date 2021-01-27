// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CanaryItem.h"
#include "ArmourActor.h"
#include "ArmourItem.generated.h"

UENUM(BlueprintType)
enum class EArmourQuality : uint8
{
	enum_Rusty UMETA(DisplayName = "Rusty"),	// Later, make an arm armour called a Shackleford, that only comes in 'Rusty'
	enum_Lousy UMETA(DisplayName = "Lousy"),
	enum_Normal UMETA(DisplayName = "Normal"),
	enum_Fine UMETA(DisplayName = "Fine"),
	enum_Flawless UMETA(DisplayName = "Flawless")
};

UENUM(BlueprintType)
enum class EArmourSlot : uint8
{
	enum_Head UMETA(DisplayName = "Head"),	// Later, make an arm armour called a Shackleford, that only comes in 'Rusty'
	enum_Body UMETA(DisplayName = "Body"),
	enum_Hands UMETA(DisplayName = "Hands"),
	enum_Legs UMETA(DisplayName = "Legs"),
	enum_Feed UMETA(DisplayName = "Feet")
};

UCLASS()
class CANARY_API UArmourItem : public UCanaryItem
{
	GENERATED_BODY()
	
public:
	UArmourItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AArmourActor> ArmourBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties", meta = (AllowPrivateAccess = "true"))
		EArmourQuality ArmourQuality;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data | Properties", meta = (AllowPrivateAccess = "true"))
		EArmourSlot ArmourSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TSubclassOf<class UGameplayAbility> LightAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TSubclassOf<class UGameplayAbility> HeavyAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TSubclassOf<class UGameplayAbility> Block;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TSubclassOf<class UGameplayAbility> Parry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TArray<TSubclassOf<class UGameplayAbility>> AddedEffects;


protected:

private:
	
	
};
