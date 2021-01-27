// Fill out your copyright notice in the Description page of Project Settings.

#include "CanaryAttributes.h"
#include "Canary.h"
#include "AbilitySystemComponent.h"
#include "CanaryCharacter.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

DEFINE_ATTRIBUTE_FUNCTION(MaxHealth, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(Health, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(MaxMana, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(Mana, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(MaxStamina, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(Stamina, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(Strength, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(Vitality, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(Dexterity, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(Agility, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(Intelligence, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(Spirit, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(StaggerThreshold, UCanaryAttributes);
DEFINE_ATTRIBUTE_FUNCTION(StaggerValue, UCanaryAttributes);

UCanaryAttributes::UCanaryAttributes()
{
	MaxHealth.SetBaseValue(500.f);
	MaxHealth.SetCurrentValue(500.f);

	Health.SetBaseValue(500.f);
	Health.SetCurrentValue(500.f);

	MaxMana.SetBaseValue(200.f);
	MaxMana.SetCurrentValue(200.f);
	
	Mana.SetBaseValue(200.f);
	Mana.SetCurrentValue(200.f);

	MaxStamina.SetBaseValue(100.f);
	MaxStamina.SetCurrentValue(100.f);

	Stamina.SetBaseValue(100.f);
	Stamina.SetCurrentValue(100.f);

	Strength.SetBaseValue(11.f);
	Strength.SetCurrentValue(11.f);

	Vitality.SetBaseValue(12.f);
	Vitality.SetCurrentValue(12.f);

	Dexterity.SetBaseValue(9.f);
	Dexterity.SetCurrentValue(9.f);

	Agility.SetBaseValue(8.f);
	Agility.SetCurrentValue(8.f);

	Intelligence.SetBaseValue(9.f);
	Intelligence.SetCurrentValue(9.f);

	Spirit.SetBaseValue(11.f);
	Spirit.SetCurrentValue(11.f);

	StaggerThreshold.SetBaseValue(10.f);
	StaggerThreshold.SetCurrentValue(10.f);

	StaggerValue.SetBaseValue(0.f);
	StaggerValue.SetCurrentValue(0.f);

}


void UCanaryAttributes::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("AdjustAttributeForMaxChange")));
}

void UCanaryAttributes::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	
	if (Attribute == HealthAttribute())
	{
		Health = FMath::Clamp(NewValue, 0.f, MaxHealth.GetCurrentValue());
	}
	if (Attribute == ManaAttribute())
	{
		Mana = FMath::Clamp(NewValue, 0.f, MaxMana.GetCurrentValue());
	}
	if (Attribute == StaminaAttribute())
	{
		Stamina = FMath::Clamp(NewValue, 0.f, MaxStamina.GetCurrentValue());
	}	
	/*
		Do things like, for STR adjustments, adjust MaxHealth.CurrentValue(), which then must adjust the Health.CurrentValue accordingly, etc;
	*/
	


}

void UCanaryAttributes::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (StaggerValue.GetCurrentValue() >= StaggerThreshold.GetCurrentValue())
	{

		SetStaggerValue(0.f);
		Cast<ACanaryCharacter>(this->GetOwningActor())->StaggerCanaryCharacter();
	}
	// GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("PostGameplayEffectExecute")));
	if (Health.GetCurrentValue() <= 0)
	{
		Cast<ACanaryCharacter>(this->GetOwningActor())->KillCanaryCharacter();
	}
}