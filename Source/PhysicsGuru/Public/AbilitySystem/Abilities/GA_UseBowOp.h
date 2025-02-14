// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/BowGameplayAbility.h"
#include "GA_UseBowOp.generated.h"

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API UGA_UseBowOp : public UBowGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;
	virtual void InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void BP_InputPressed();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_InputReleased();
};
