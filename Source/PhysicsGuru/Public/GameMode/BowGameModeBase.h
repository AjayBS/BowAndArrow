// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CharacterClassInfo.h"
#include "BowGameModeBase.generated.h"

class UCharacterClassInfo;

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API ABowGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Character Class Defaults")
	TSubclassOf<UCharacterClassInfo> CharacterClassInfo;
};
