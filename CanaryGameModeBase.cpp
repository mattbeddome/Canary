// Fill out your copyright notice in the Description page of Project Settings.

#include "CanaryGameModeBase.h"

ACanaryGameModeBase::ACanaryGameModeBase()
{
	//GameStateClass = ARPGGameStateBase::StaticClass();
	PlayerControllerClass = ACanaryController::StaticClass();
	DefaultPawnClass = nullptr;
}