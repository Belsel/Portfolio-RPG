// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPortfolioRPG, Log, All);

UENUM(BlueprintType)
enum class EPortfolioRPGAbilityInput : uint8
{
	None,
	Confirm,
	Cancel,
	Punch
};