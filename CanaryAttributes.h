// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CanaryAttributes.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

#define DECLARE_ATTRIBUTE_FUNCTION(PropertyName) static FGameplayAttribute PropertyName##Attribute();

#define DEFINE_ATTRIBUTE_FUNCTION(PropertyName, ClassName) 																								\
FGameplayAttribute ClassName##::PropertyName##Attribute()																								\
{																																						\
	static UProperty* Property = FindFieldChecked<UProperty>(ClassName##::StaticClass(), GET_MEMBER_NAME_CHECKED(ClassName, PropertyName));				\
	return FGameplayAttribute(Property);																												\
}

UCLASS()
class CANARY_API UCanaryAttributes : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UCanaryAttributes();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, MaxHealth)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, Health)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Mana")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, MaxMana)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Mana")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, Mana)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Stamina")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, MaxStamina)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Stamina")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, Stamina)


	/*               Primary Attributes                      */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Primary")
	FGameplayAttributeData Strength;	// Damage with STR weapons, Block Effectiveness, Push/Bash effectiveness
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, Strength)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Primary")
	FGameplayAttributeData Vitality;	// MaxHealth, MaxStamina, Defense
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, Vitality)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Primary")
	FGameplayAttributeData Dexterity;	// Damage with DEX weapons, Critical Hit rate, Parry Chance
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, Dexterity)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Primary")
	FGameplayAttributeData Agility;		// Critial Hit Damage, Ranged Attack Damage
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, Agility)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Primary")
	FGameplayAttributeData Intelligence;	// Max Mana, Magic Defense, Buff/Debuff Length
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, Intelligence)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Primary")
	FGameplayAttributeData Spirit;		// Magic Damage, Health/Mana/Stamina Regen
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, Spirit)


	/*            Secondary Attributes                        */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Secondary")
	FGameplayAttributeData StaggerThreshold;		// Actions add to stagger, degrades over time. If current > max, stagger();
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, StaggerThreshold)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Secondary")
	FGameplayAttributeData StaggerValue;		// Actions add to stagger, degrades over time. If current > max, stagger();
	ATTRIBUTE_ACCESSORS(UCanaryAttributes, StaggerValue)

	DECLARE_ATTRIBUTE_FUNCTION(MaxHealth);
	DECLARE_ATTRIBUTE_FUNCTION(Health);
	DECLARE_ATTRIBUTE_FUNCTION(MaxMana);
	DECLARE_ATTRIBUTE_FUNCTION(Mana);
	DECLARE_ATTRIBUTE_FUNCTION(MaxStamina);
	DECLARE_ATTRIBUTE_FUNCTION(Stamina);

	DECLARE_ATTRIBUTE_FUNCTION(Strength);
	DECLARE_ATTRIBUTE_FUNCTION(Vitality);
	DECLARE_ATTRIBUTE_FUNCTION(Dexterity);
	DECLARE_ATTRIBUTE_FUNCTION(Agility);
	DECLARE_ATTRIBUTE_FUNCTION(Intelligence);
	DECLARE_ATTRIBUTE_FUNCTION(Spirit);

	DECLARE_ATTRIBUTE_FUNCTION(StaggerThreshold);
	DECLARE_ATTRIBUTE_FUNCTION(StaggerValue);

protected:
	/** Helper function to proportionally adjust the value of an attribute when it's associated max attribute changes. (i.e. When MaxHealth increases, Health increases by an amount that maintains the same percentage as before) */
	void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty);

};
