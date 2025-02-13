// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BowGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API UBowGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	FGameplayTag StartupInputTag;
};
