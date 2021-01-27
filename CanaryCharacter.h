// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CanaryAttributes.h"
#include "CanaryItem.h"
#include "WeaponItem.h"
#include "ArmourItem.h"
#include "ConsumableItem.h"
#include "MaterialItem.h"
#include "QuestItem.h"
#include "Animation/AnimMontage.h"
#include "CanaryCharacter.generated.h"

UCLASS()
class CANARY_API ACanaryCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	/** Ability System **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
		class UAbilitySystemComponent* AbilitySystem;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Canary Attributes", meta = (AllowPrivateAccess = "true"))
		UCanaryAttributes* Attributes;

	/*      Refer to CanaryAttribtues to create getters and setters for these       */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		float runSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		float walkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		bool bIsAttacking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		bool bIsBlocking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		bool bIsCasting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		bool bIsJumping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		bool bIsHanging;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		bool bIsDisabled;	// General state for "cannot move, cast, attack, jump, etc"

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		bool bIsVulnerable;	// Set this in AnimMontages with a NotifyState, Enemies can RNG read the value and maybe sneak in a quick shield bash

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		bool bIsDead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		bool bComboWindowOpen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character States")
		bool bDodgeWindowOpen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
		UAnimMontage* TakeMeleeDamageMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
		UAnimMontage* TakeMagicDamageMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
		UAnimMontage* StaggerMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations") // Knock back or knock down, depending (I.E large ogre would be knocked back, not down)
		UAnimMontage* KnockBackMontage;									 // Trigger this if character is staggered and gets hit with a bash

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
		UAnimMontage* DeathMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TArray<TSubclassOf<class UGameplayAbility>> AbilitySet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TArray<TSubclassOf<class UConsumableItem>> ItemSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TSubclassOf<class UGameplayAbility> LightAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TSubclassOf<class UGameplayAbility> HeavyAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TSubclassOf<class UGameplayAbility> Block;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
		TSubclassOf<class UGameplayAbility> Bash;

	UPROPERTY(EditAnywhere, Category = "GUI")
		TSubclassOf<class UUserWidget> MainMenuWidgetClass;

	UPROPERTY(EditAnywhere, Category = "GUI")
		TSubclassOf<class UUserWidget> GameMenuWidgetClass;

	UPROPERTY(EditAnywhere, Category = "GUI")
		TSubclassOf<class UUserWidget> CharacterStatusWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Attack Combo")
		TMap<uint8, FName> ComboSectionsMap;

protected:
	UPROPERTY(EditAnywhere, Category = "Attack Combo")
		uint8 ComboIndex;
private:

public:	

	ACanaryCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Combat")
		virtual void DoLightAttack();

	UFUNCTION(BlueprintCallable, Category = "Combat")
		virtual void DoHeavyAttack();

	UFUNCTION(BlueprintCallable, Category = "Combat")
		virtual void DoUseAbility();

	UFUNCTION(BlueprintCallable, Category = "Combat")
		virtual void DoBlock();

	UFUNCTION(BlueprintCallable, Category = "Combat")
		virtual void EndBlock();

	UFUNCTION(BlueprintCallable, Category = "Combat")
		virtual void DoBash();

	UFUNCTION(BlueprintCallable, Category = "Combat")
		virtual void DoSprint();

	UFUNCTION(BlueprintCallable, Category = "Combat")
		virtual void EndSprint();

	UFUNCTION(BlueprintCallable, Category = "Combat")
		virtual void DoDodge();

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
		void BeginAttack();

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
		void EndAttack();

	UFUNCTION(BlueprintCallable)
		void GiveNewAbility(TSubclassOf<class UGameplayAbility> NewAbility, int32 level, int32 inputIndex);

	UFUNCTION(BlueprintCallable)
		void StaggerCanaryCharacter();

	UFUNCTION(BlueprintCallable)
		void KillCanaryCharacter();	// Have FName Parameter here for type? (Melee, fire, lightning, blunt, etc) for montage section

	UFUNCTION(BlueprintCallable)
		FORCEINLINE UCanaryAttributes* GetCanaryAttributes()	{ return Attributes; }

	UFUNCTION(BlueprintCallable)
		void SetComboSections(TMap<uint8, FName> NewComboSectionsMap);

	UAbilitySystemComponent* GetAbilitySystemComponent() const override //We add this function, overriding it from IAbilitySystemInterface.
	{
		return AbilitySystem;
	};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
		void DoNextAttackInCombo();

};


/*

	Move these to the inventory component C++ class when the time comes


UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory | Equipment | Weapons", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<UWeaponItem>> invWeapons;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory | Equipment | Weapons", meta = (AllowPrivateAccess = "true"))
	uint8 MaxWeaponSlots;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory | Equipment | Armour", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<UArmourItem>> invArmour;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory | Equipment | Armour", meta = (AllowPrivateAccess = "true"))
	uint8 MaxArmourSlots;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory | Equipment | Consumables", meta = (AllowPrivateAccess = "true"))
	TMap<TSubclassOf<UConsumableItem>, uint8> invConsumables;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory | Equipment | Consumables", meta = (AllowPrivateAccess = "true"))
	uint8 MaxConsumableSlots;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory | Equipment | Materials", meta = (AllowPrivateAccess = "true"))
	TMap<TSubclassOf<UMaterialItem>, uint8> invMaterials;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory | Equipment | Materials", meta = (AllowPrivateAccess = "true"))
	uint8 MaxMaterialsSlots;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory | Equipment | Quest", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<UQuestItem>> invQuest;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory | Equipment | Quest", meta = (AllowPrivateAccess = "true"))
	uint8 MaxQuestSlots;




UFUNCTION(BlueprintCallable)
	void AddWeaponToInventory(TSubclassOf<UWeaponItem> Weapon);

UFUNCTION(BlueprintCallable)
	void RemoveWeaponFromInventory(TSubclassOf<UWeaponItem> Weapon);

UFUNCTION(BlueprintCallable)
	void AddArmourToInventory(TSubclassOf<UArmourItem> Armour);

UFUNCTION(BlueprintCallable)
	void RemoveArmourFromInventory(TSubclassOf<UArmourItem> Armour);

UFUNCTION(BlueprintCallable)
	void AddConsumableToInventory(TSubclassOf<UConsumableItem> Item);

UFUNCTION(BlueprintCallable)
	void RemoveConsumableFromInventory(TSubclassOf<UConsumableItem> Item);

UFUNCTION(BlueprintCallable)
	void AddMaterialToInventory(TSubclassOf<UMaterialItem> Item);

UFUNCTION(BlueprintCallable)
	void RemoveMaterialFromInventory(TSubclassOf<UMaterialItem> Item);

UFUNCTION(BlueprintCallable)
	void AddQuestItemToInventory(TSubclassOf<UQuestItem> Item);

UFUNCTION(BlueprintCallable)
	void RemoveQuestFromInventory(TSubclassOf<UQuestItem> Item);




	void ACanaryCharacter::AddWeaponToInventory(TSubclassOf<UWeaponItem> Weapon)
{
	this->invWeapons.Add(Weapon);
}

void ACanaryCharacter::RemoveWeaponFromInventory(TSubclassOf<UWeaponItem> Weapon)
{

}

void ACanaryCharacter::AddArmourToInventory(TSubclassOf<UArmourItem> Armour)
{
	this->invArmour.Add(Armour);
}

void ACanaryCharacter::RemoveArmourFromInventory(TSubclassOf<UArmourItem> Armour)
{

}

void ACanaryCharacter::AddConsumableToInventory(TSubclassOf<UConsumableItem> Item)
{
	if (this->invConsumables.Contains(Item))
	{
		uint8* currentQty = this->invConsumables.Find(Item);
		//this->invConsumables.Emplace(Item, currentyQty + 1)
	}
	else
	{
		this->invConsumables.Add(Item, 1);
	}
}

void ACanaryCharacter::RemoveConsumableFromInventory(TSubclassOf<UConsumableItem> Item)
{

}

void ACanaryCharacter::AddMaterialToInventory(TSubclassOf<UMaterialItem> Item)
{

}

void ACanaryCharacter::RemoveMaterialFromInventory(TSubclassOf<UMaterialItem> Item)
{

}

void ACanaryCharacter::AddQuestItemToInventory(TSubclassOf<UQuestItem> Item)
{

}

void ACanaryCharacter::RemoveQuestFromInventory(TSubclassOf<UQuestItem> Item)
{

}


*/