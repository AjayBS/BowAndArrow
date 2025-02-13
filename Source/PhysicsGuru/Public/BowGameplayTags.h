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
protected:

private:
	static FBowGameplayTags GameplayTags;
};