// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterAbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystemGlobals.h"



void UCharacterAbilitySystemComponent::InitAbilities()
{
	for (TSubclassOf<UCharacterGameplayAbility>& StartupAbility : DefaultAbilities)
	{
		if (StartupAbility != NULL)
		{
			LearnAbility(StartupAbility);
		}
	}
}

FGameplayAbilitySpecHandle UCharacterAbilitySystemComponent::LearnAbility(TSubclassOf<UCharacterGameplayAbility>& Ability)
{
	FGameplayAbilitySpecHandle AbilitySpecHandle = GiveAbility(FGameplayAbilitySpec(Ability, 1, static_cast<int32>(Ability.GetDefaultObject()->AbilityInputID), this));
	AbilitiesLearnt.Add(Ability, AbilitySpecHandle);
	return AbilitySpecHandle;
}

void UCharacterAbilitySystemComponent::ForgetAbility(TSubclassOf<UCharacterGameplayAbility>& Ability)
{
	FGameplayAbilitySpecHandle AbilitySpecHandle = *AbilitiesLearnt.Find(Ability);
	ClearAbility(AbilitySpecHandle);
}

void UCharacterAbilitySystemComponent::InitializeAttributes()
{
	
	FGameplayEffectContextHandle EffectContext = MakeEffectContext();
	EffectContext.AddSourceObject(GetOwnerActor());

	FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);

	if (SpecHandle.IsValid())
	{
		FActiveGameplayEffectHandle GEHanlde = ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}
