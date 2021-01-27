// Fill out your copyright notice in the Description page of Project Settings.

#include "CanaryCharacter.h"
#include "Canary.h"
#include "Components/CapsuleComponent.h"
#include "Animation/AnimInstance.h"
#include "AbilitySystemComponent.h"


// Sets default values
ACanaryCharacter::ACanaryCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
	Attributes = CreateDefaultSubobject<UCanaryAttributes>(TEXT("Attributes"));

	bIsAttacking = false;
	bIsBlocking = false;
	bIsCasting = false;
	bIsJumping = false;
	bIsHanging = false;
	bIsDisabled = false;
	bIsVulnerable = false;
	bIsDead = false;
	bComboWindowOpen = false;
	bDodgeWindowOpen = false;

	ComboIndex = 0;
}

// Called when the game starts or when spawned
void ACanaryCharacter::BeginPlay()
{
	Super::BeginPlay();
	TMap<uint8, FName> temp;
	// temp.Add(0, "FirstAttack");
	temp.Add(1, "SecondAttack");
	temp.Add(2, "ThirdAttack");
	temp.Add(3, "FourthAttack");
	this->SetComboSections(temp);
	if (AbilitySystem)
	{
		FGameplayAbilityActorInfo* actorInfo = new FGameplayAbilityActorInfo();
		actorInfo->InitFromActor(this, this, AbilitySystem);
		AbilitySystem->AbilityActorInfo = TSharedPtr<FGameplayAbilityActorInfo>(actorInfo);
		AbilitySystem->InitAbilityActorInfo(this, this);
		for (uint8 i = 0; i < this->AbilitySet.Num(); i++)
		{
			this->GiveNewAbility(AbilitySet[i], 1, 0);
		}

		if (LightAttack)
		{
			GiveNewAbility(LightAttack, 1, 0);
		}
		if (HeavyAttack)
		{
			GiveNewAbility(HeavyAttack, 1, 0);
		}
		if (Block)
		{
			GiveNewAbility(Block, 1, 0);
 		}
		if (Bash)
		{
			GiveNewAbility(Bash, 1, 0);
		}
		AbilitySystem->InitAbilityActorInfo(this, this);

		AbilitySystem->RefreshAbilityActorInfo();
	}
}

// Called every frame
void ACanaryCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACanaryCharacter::DoLightAttack()
{
	if (!bIsDead && !bIsDisabled && !bIsCasting && !bIsBlocking)
	{
		if (!bComboWindowOpen)
		{
			ComboIndex = 0;
			AbilitySystem->TryActivateAbilityByClass(LightAttack);
		}
		else
		{
			this->DoNextAttackInCombo();
		}
	}

}

void ACanaryCharacter::DoHeavyAttack()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Heavy Attack")));
}

void ACanaryCharacter::DoUseAbility()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Orange, FString::Printf(TEXT("Try Use Ability")));
	if (AbilitySet[0])
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, FString::Printf(TEXT("Do Use Ability")));
		AbilitySystem->TryActivateAbilityByClass(this->AbilitySet[0]);
	}
}

void ACanaryCharacter::DoBlock()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Do Block")));
}

void ACanaryCharacter::EndBlock()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("End Block")));
}

void ACanaryCharacter::DoBash()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Bash")));
}

void ACanaryCharacter::DoSprint()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Do Sprint")));
}

void ACanaryCharacter::EndSprint()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("End Sprint")));
}

void ACanaryCharacter::DoDodge()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Dodge")));
}

void ACanaryCharacter::GiveNewAbility(TSubclassOf<class UGameplayAbility> NewAbility, int32 level, int32 inputIndex)
{
	
	if (NewAbility)
	{
		AbilitySystem->GiveAbility(FGameplayAbilitySpec(NewAbility.GetDefaultObject(), level, inputIndex));
	}
	else
	{
	}

	AbilitySystem->RefreshAbilityActorInfo();

}

void ACanaryCharacter::StaggerCanaryCharacter()
{
	if (this->StaggerMontage != nullptr && !bIsDead)
	{
		this->GetCanaryAttributes()->SetStaggerValue(0.f);
		this->StopAnimMontage(this->GetCurrentMontage());
		this->PlayAnimMontage(this->StaggerMontage);
	}
}

void ACanaryCharacter::KillCanaryCharacter()
{
	bIsDead = true;

	if (DeathMontage != nullptr)
	{
		this->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		this->StopAnimMontage(this->GetCurrentMontage());
		this->PlayAnimMontage(this->DeathMontage);
	}
}

void ACanaryCharacter::DoNextAttackInCombo()
{

	if (this->bComboWindowOpen)
	{
		ComboIndex++;
		UAnimInstance* animInstance = this->GetMesh()->GetAnimInstance();
		FName currentMontageSection = animInstance->Montage_GetCurrentSection();
		animInstance->Montage_JumpToSection(ComboSectionsMap.FindRef(ComboIndex));
		if (ComboIndex >= ComboSectionsMap.Num())
		{
			ComboIndex = 0;
		}
	}
	else
	{

	}
}

void ACanaryCharacter::SetComboSections(TMap<uint8, FName> NewComboSectionsMap)
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Set Combo Sections Map")));
	ComboSectionsMap.Empty();
	for (auto& Elem : NewComboSectionsMap)
	{
		ComboSectionsMap.Add(Elem.Key, Elem.Value);
	}
}