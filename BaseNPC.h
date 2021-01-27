// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interactive.h"
#include "Blueprint/UserWidget.h"
#include "BaseNPC.generated.h"

UCLASS()
class CANARY_API ABaseNPC : public ACharacter, public IInteractive
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseNPC();

	virtual void BeginPlay() override;

	void InteractWithObject(class ACanaryCharacter* InteractingCharacter);
	virtual void InteractWithObject_Implementation(class ACanaryCharacter* InteractingCharacter) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USphereComponent* DetectionRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUI")
		FName CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUI")
		UTexture* Portrait;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUI")
		TArray<FText> Dialogs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUI")
		TSubclassOf<class UUserWidget> DialogWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUI")
		class UUserWidget* DialogWidget;
};
