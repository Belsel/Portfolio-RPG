// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "PortfolioRPG.h"
#include "CharacterGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class PORTFOLIORPG_API UCharacterGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:

	UCharacterGameplayAbility();

	// Abilities with this set will automatically activate when the input is pressed
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	EPortfolioRPGAbilityInputID AbilityInputID = EPortfolioRPGAbilityInputID::None;
};
