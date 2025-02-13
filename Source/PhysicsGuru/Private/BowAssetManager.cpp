// Copyright ConfusedMinds Ltd.


#include "BowAssetManager.h"
#include "BowGameplayTags.h"

UBowAssetManager& UBowAssetManager::Get()
{
	check(GEngine);

	UBowAssetManager* BowAssetManager = Cast<UBowAssetManager>(GEngine->AssetManager);
	return *BowAssetManager;
}

void UBowAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FBowGameplayTags::InitializeNativeGameplayTags();
}
