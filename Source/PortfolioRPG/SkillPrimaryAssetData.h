// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterGameplayAbility.h"
#include "SkillPrimaryAssetData.generated.h"

/**
 * 
 */
UCLASS()
class PORTFOLIORPG_API USkillPrimaryAssetData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UCharacterGameplayAbility> AbilityGranted;

};
