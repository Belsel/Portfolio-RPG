// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterGameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "CharacterAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class PORTFOLIORPG_API UCharacterAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, Category = "GAS")
	TMap<TSubclassOf<UCharacterGameplayAbility>, FGameplayAbilitySpecHandle> AbilitiesLearnt;
	
	// Effect that initializes the default abilities
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS")
	TArray<TSubclassOf<class UCharacterGameplayAbility>> DefaultAbilities;

	// Effect that initializes the default attributes
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	virtual void InitAbilities();

	virtual void InitializeAttributes();

	UFUNCTION(BlueprintCallable, Category = "Ability System")
	virtual FGameplayAbilitySpecHandle LearnAbility(UPARAM(ref) TSubclassOf<UCharacterGameplayAbility>& Ability);

	UFUNCTION(BlueprintCallable, Category = "Ability System")
	virtual void ForgetAbility(UPARAM(ref) TSubclassOf<UCharacterGameplayAbility>& Ability);

};
