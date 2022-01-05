// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "PortfolioRPG.h"
#include "GameplayAbilitySpec.h"
#include <GameplayEffectTypes.h>
#include "Animation/AnimSequence.h"
#include "PortfolioRPGCharacter.generated.h"

UCLASS(Blueprintable)
class APortfolioRPGCharacter : public ACharacter, public IAbilitySystemInterface
{
 	GENERATED_BODY()

public:
	APortfolioRPGCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void InitializeAttributes();
	virtual void GiveAbilities();


	UFUNCTION(BlueprintCallable, Category = "Ability System")
	virtual FGameplayAbilitySpecHandle LearnAbility( UPARAM(ref) TSubclassOf<UCharacterGameplayAbility>& Ability);

	UFUNCTION(BlueprintCallable, Category = "Ability System")
	virtual void ForgetAbility(UPARAM(ref) TSubclassOf<UCharacterGameplayAbility>& Ability);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ability System")
	void HandleAbility(UAnimSequenceBase* Animation);

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	// Effect that initializes the default attributes
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	// Effect that initializes the default abilities
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS")
	TArray<TSubclassOf<class UCharacterGameplayAbility>> DefaultAbilities;

	UPROPERTY(VisibleAnywhere, Category = "GAS")
	TMap<TSubclassOf<UCharacterGameplayAbility>, FGameplayAbilitySpecHandle> AbilitiesLearnt;


protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AbilitySystem, meta = (AllowPrivateAccess = "true"))
	class UCharacterAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UCombatAttributeSet* Attributes;
};

