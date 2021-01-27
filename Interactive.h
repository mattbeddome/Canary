// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactive.generated.h"

/**
 *
 */
UINTERFACE(BlueprintType)
class CANARY_API UInteractive : public UInterface
{
	GENERATED_BODY()
};

class CANARY_API IInteractive
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactive Object Interface")
		void InteractWithObject(class ACanaryCharacter* InteractingCharacter);

	/*
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactive Object Interface")
		void SetIsFocusedObject();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactive Object Interface")
		void SetIsNotFocusedObject();
	*/

protected:

private:

};
