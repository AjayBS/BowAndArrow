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

	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.1"),
		FString("Input tag for equipping bow.")
	);

	GameplayTags.Arrow_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Arrow.Damage"),
		FString("Used to include damage done by arrow.")
	);

	GameplayTags.Enemy_Status_Strafing = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Enemy.Status.Strafing"),
		FString("Used to strafe around in the world.")
	);
}
