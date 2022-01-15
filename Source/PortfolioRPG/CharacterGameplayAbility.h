// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "Abilities/GameplayAbility.h"
#include "PortfolioRPG.h"
#include "CharacterGameplayAbility.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FAbilityData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	UTexture2D* Icon;


};

UCLASS()
class PORTFOLIORPG_API UCharacterGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

	
public:

	UCharacterGameplayAbility();

	// Abilities with this set will automatically activate when the input is pressed
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	EPortfolioRPGAbilityInputID AbilityInputID = EPortfolioRPGAbilityInputID::None;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
	FAbilityData AbilityData;

};
