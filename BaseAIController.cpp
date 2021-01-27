// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseAIController.h"
#include "Engine.h"

ABaseAIController::ABaseAIController()
{
	bAttachToPawn = true;
	DetectionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionRadius"));
	DetectionRadius->SetupAttachment(RootComponent, TEXT(""));
	DetectionRadius->SetSphereRadius(600.0, false);
	DetectionRadius->SetCollisionResponseToAllChannels(ECR_Ignore);
	DetectionRadius->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
}

void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Begin")));
}