// Copyright Epic Games, Inc. All Rights Reserved.

#include "PortfolioRPGGameMode.h"
#include "PortfolioRPGPlayerController.h"
#include "PortfolioRPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

APortfolioRPGGameMode::APortfolioRPGGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = APortfolioRPGPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}