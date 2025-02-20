// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * BowGameplayTags
 * Singleton containing native gameplay tags
 */

struct FBowGameplayTags
{
public:
	static const FBowGameplayTags& Get() {	return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_1;

	FGameplayTag Arrow_Damage;
	FGameplayTag Enemy_Status_Strafing;
	FGameplayTag Enemy_Ability_Melee;
protected:

private:
	static FBowGameplayTags GameplayTags;
};