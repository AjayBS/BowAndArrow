// Copyright ConfusedMinds Ltd.


#include "BowGameplayTags.h"
#include "GameplayTagsManager.h"

FBowGameplayTags FBowGameplayTags::GameplayTags;

void FBowGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.LMB"),
		FString("Input tag for Left Mouse Button.")
	);
}
