// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "Interactive.h"
#include "ItemContainer.generated.h"

UCLASS()
class CANARY_API AItemContainer : public AActor, public IInteractive
{
	GENERATED_BODY()

public:
	
	AItemContainer(const FObjectInitializer& OI);

	virtual void BeginPlay() override;

	void InteractWithObject(class ACanaryCharacter* InteractingCharacter);
	virtual void InteractWithObject_Implementation(class ACanaryCharacter* InteractingCharacter) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Items")
		class UStaticMeshComponent* ItemContainerModel;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Items")
		class UItemContainerComponent* ItemContainerComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USphereComponent* DetectionRadius;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUI")
		TSubclassOf<class UUserWidget> ItemContainerWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUI")
		class UUserWidget* ItemContainerWidget;
};
