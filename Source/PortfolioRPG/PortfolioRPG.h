// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPortfolioRPG, Log, All);

UENUM(BlueprintType)
enum class EPortfolioRPGAbilityInputID : uint8
{
	None,
	Confirm,
	Cancel,
	Skill1,
	Skill2,
	Skill3,
	Skill4,
	Skill5,
	Skill6,
	Roll
};