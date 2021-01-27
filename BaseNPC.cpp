// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNPC.h"
#include "CanaryCharacter.h"
#include "CanaryController.h"
#include "Components/SphereComponent.h"

// Sets default values
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
ABaseNPC::ABaseNPC()
{
	PrimaryActorTick.bCanEverTick = true;
	//DialogWidget = CreateDefaultSubobject<UUserWidget>(TEXT("DialogWidget"));
	this->SetRootComponent(this->GetCapsuleComponent());
	DetectionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionRadius"));
	DetectionRadius->SetupAttachment(RootComponent);
	DetectionRadius->SetSphereRadius(125.0, false);
	DetectionRadius->SetCollisionResponseToAllChannels(ECR_Ignore);
	DetectionRadius->SetCollisionProfileName("InteractiveObject");
}

void ABaseNPC::BeginPlay()
{
	Super::BeginPlay();

	if (DialogWidgetClass != nullptr)
	{
		DialogWidget = CreateWidget<UUserWidget>(GetWorld(), DialogWidgetClass);
	}
}

void ABaseNPC::InteractWithObject_Implementation(ACanaryCharacter* InteractingCharacter)
{
	Cast<ACanaryController>(InteractingCharacter->GetController())->OpenInteractionWidget(this->DialogWidget);
}

