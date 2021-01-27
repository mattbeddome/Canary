// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemContainer.h"
#include "Engine.h"
#include "ItemContainerComponent.h"
#include "PlayerCharacter.h"
#include "CanaryController.h"
#include "Components/SphereComponent.h"

// Sets default values
AItemContainer::AItemContainer(const FObjectInitializer& OI) : Super(OI)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemContainerComponent = CreateDefaultSubobject<UItemContainerComponent>(TEXT("ItemContainerComponent"));
	ItemContainerWidget = CreateDefaultSubobject<UUserWidget>(TEXT("ItemContainerWidget"));
	DetectionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionRadius"));
	this->SetRootComponent(DetectionRadius);
	DetectionRadius->SetupAttachment(RootComponent);
	DetectionRadius->SetSphereRadius(125.0, false);
	DetectionRadius->SetCollisionResponseToAllChannels(ECR_Ignore);
	DetectionRadius->SetCollisionProfileName("InteractiveObject");
}

void AItemContainer::BeginPlay()
{
	Super::BeginPlay();

	if (ItemContainerWidgetClass != nullptr)
	{
		ItemContainerWidget = CreateWidget<UUserWidget>(GetWorld(), ItemContainerWidgetClass);
	}
}

void AItemContainer::InteractWithObject_Implementation(ACanaryCharacter* InteractingCharacter)
{
	Cast<ACanaryController>(InteractingCharacter->GetController())->OpenInteractionWidget(this->ItemContainerWidget);
}
