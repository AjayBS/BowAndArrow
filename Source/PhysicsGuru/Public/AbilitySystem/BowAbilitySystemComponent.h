// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "BowAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API UBowAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);
	void AbilityInputTagHeld(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);

	UFUNCTION(BlueprintCallable, Category = "Bow|Ability")
	bool TryActivateAbilityByTag(FGameplayTag AbilityTagToActivate);
};
