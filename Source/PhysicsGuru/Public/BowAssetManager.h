// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "BowAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API UBowAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UBowAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
	
};
