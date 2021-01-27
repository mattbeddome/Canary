// Fill out your copyright notice in the Description page of Project Settings.

#include "CanaryController.h"
#include "Canary.h"
#include "Components/InputComponent.h"
#include "Interactive.h"
#include "Blueprint/UserWidget.h"

ACanaryController::ACanaryController()
{
	bAttachToPawn = true;
	this->SetControllerContext(EControllerContext::enum_Pawn);
	MainMenuWidget = CreateDefaultSubobject<UUserWidget>(TEXT("MainMenuWidget"));
	GameMenuWidget = CreateDefaultSubobject<UUserWidget>(TEXT("GameMenuWidget"));
	CharacterStatusWidget = CreateDefaultSubobject<UUserWidget>(TEXT("CharacterStatusWidget"));
}

void ACanaryController::BeginPlay()
{
	Super::BeginPlay();
	MyPlayerCharacter = Cast<ACanaryCharacter>(this->GetCharacter());
	if (MyPlayerCharacter)
	{
		SetupWidgets();
	}
}

void ACanaryController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACanaryController::SetupWidgets()
{
	if (MyPlayerCharacter != nullptr)
	{
		if (MyPlayerCharacter->CharacterStatusWidgetClass != nullptr)
		{
			CharacterStatusWidget = CreateWidget<UUserWidget>(GetWorld(), MyPlayerCharacter->CharacterStatusWidgetClass);
			if (CharacterStatusWidget)
			{
				CharacterStatusWidget->AddToViewport();
			}
		}
		if (MyPlayerCharacter->MainMenuWidgetClass != nullptr)
		{
			MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), MyPlayerCharacter->MainMenuWidgetClass);
			if (MainMenuWidget)
			{
				MainMenuWidget->AddToViewport();
				MainMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
			}
		}
		if (MyPlayerCharacter->GameMenuWidgetClass != nullptr)
		{
			GameMenuWidget = CreateWidget<UUserWidget>(GetWorld(), MyPlayerCharacter->GameMenuWidgetClass);
			if (GameMenuWidget)
			{
				GameMenuWidget->AddToViewport();
				GameMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
			}
		}
	}
}

EControllerContext ACanaryController::GetControllerContext()
{
	return this->ControllerContext;
}

void ACanaryController::SetControllerContext(EControllerContext NewContext)
{
	this->ControllerContext = NewContext;
}

void ACanaryController::SetMyCharacter(ACanaryCharacter* NewCharacter)
{
	MyPlayerCharacter = NewCharacter;
}

ACanaryCharacter* ACanaryController::GetMyCharacter()
{
	return MyPlayerCharacter;
}


// Need to handle what happens if the other menu is visible...
// Can probably just have one menu... tabs could be:
// INVENTORY / CHARACTER / QUESTS / SETTINGS

void ACanaryController::ToggleMainMenu()
{
	if (MainMenuWidget->GetVisibility() == ESlateVisibility::Collapsed)
	{
		MainMenuWidget->SetVisibility(ESlateVisibility::Visible);
		MyPlayerCharacter->DisableInput(this);
		this->SetControllerContext(EControllerContext::enum_Widget);
	}
	else
	{
		MainMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
		if (InteractionWidget == nullptr)
		{
			MyPlayerCharacter->EnableInput(this);
			this->SetControllerContext(EControllerContext::enum_Pawn);
		}
	}
}

void ACanaryController::ToggleGameMenu()
{
	if(GameMenuWidget->GetVisibility() == ESlateVisibility::Collapsed)
	{
		GameMenuWidget->SetVisibility(ESlateVisibility::Visible);
		MyPlayerCharacter->DisableInput(this);
		this->SetControllerContext(EControllerContext::enum_Widget);
	}
	else
	{
		GameMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
		if (InteractionWidget == nullptr)
		{
			FInputModeUIOnly GameMenuFocus;
			MyPlayerCharacter->EnableInput(this);
			this->SetControllerContext(EControllerContext::enum_Pawn);
		}
	}
}

void ACanaryController::OpenInteractionWidget(UUserWidget * InWidget)
{
	if (InWidget != nullptr)
	{
		InteractionWidget = InWidget;
		InteractionWidget->AddToViewport();
		InteractionWidget->SetVisibility(ESlateVisibility::Visible);
		MyPlayerCharacter->DisableInput(this);
		this->SetControllerContext(EControllerContext::enum_Widget);
	}
}

void ACanaryController::CloseInteractionWidget()
{
	if (InteractionWidget != nullptr)
	{
		InteractionWidget->RemoveFromViewport();
		InteractionWidget = nullptr;

		// These are temporary until MainMenuWidget and GameMenuWidget are handled properly
		MyPlayerCharacter->EnableInput(this);
		this->SetControllerContext(EControllerContext::enum_Pawn);

		if (GameMenuWidget->GetVisibility() == ESlateVisibility::Collapsed && MainMenuWidget->GetVisibility() == ESlateVisibility::Collapsed)
		{
			MyPlayerCharacter->EnableInput(this);
			this->SetControllerContext(EControllerContext::enum_Pawn);
		}
		
	}
	// Else close gameMenu/mainMenu?
}
void ACanaryController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("CTRL_ToggleGameMenu", IE_Pressed, this, &ACanaryController::ToggleGameMenu);
	InputComponent->BindAction("CTRL_CloseMenu", IE_Pressed, this, &ACanaryController::CloseInteractionWidget);
}

UUserWidget* ACanaryController::GetCharacterStatusHUD()
{
	return this->CharacterStatusWidget;
}