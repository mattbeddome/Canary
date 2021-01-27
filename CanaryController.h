// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CanaryCharacter.h"
#include "Components/CapsuleComponent.h"
#include "CanaryController.generated.h"

UENUM(BlueprintType)
enum class EControllerContext : uint8
{
	enum_Pawn UMETA(DisplayName = "Pawn"),
	enum_Widget UMETA(DisplayName = "Widget")
};

UCLASS()
class CANARY_API ACanaryController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controller State", meta = (AllowPrivateAccess = "true"))
		EControllerContext ControllerContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Controls")
		AActor* InteractiveObject;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Data", meta = (AllowPrivateAccess = "true"))
		ACanaryCharacter* MyPlayerCharacter;

	UPROPERTY(editAnywhere, BlueprintReadWrite, category = "Character Controls")
		UCapsuleComponent* InteractiveObjectDetection;

	UPROPERTY(EditAnywhere, Category = "GUI")
		TSubclassOf<class UUserWidget> MainMenuWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GUI")
		class UUserWidget* MainMenuWidget;

	UPROPERTY(EditAnywhere, Category = "GUI")
		TSubclassOf<class UUserWidget> GameMenuWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GUI")
		class UUserWidget* GameMenuWidget;

	// Widget Class is defined on the ALS_PlayerCharacter
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GUI")
		class UUserWidget* CharacterStatusWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GUI")
		class UUserWidget* InteractionWidget;	// Make this an array if I need to open multiple

public:

	ACanaryController();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void SetMyCharacter(ACanaryCharacter* NewCharacter);

	UFUNCTION(BlueprintCallable)
		ACanaryCharacter* GetMyCharacter();

	UFUNCTION(BlueprintCallable)
		void ToggleMainMenu();

	UFUNCTION(BlueprintCallable)
		void ToggleGameMenu();

	UFUNCTION(BlueprintCallable)
		void OpenInteractionWidget(class UUserWidget* InWidget);

	UFUNCTION(BlueprintCallable)
		void CloseInteractionWidget();

	UFUNCTION(BlueprintCallable)
		class UUserWidget* GetCharacterStatusHUD();
	
protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	void SetupWidgets();

	UFUNCTION()
		EControllerContext GetControllerContext();

	UFUNCTION()
		void SetControllerContext(EControllerContext NewContext);
private:
	
};
