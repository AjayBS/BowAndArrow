// Copyright ConfusedMinds Ltd.


#include "AbilitySystem/Abilities/GA_UseBowOp.h"

void UGA_UseBowOp::InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	BP_InputPressed();
}

void UGA_UseBowOp::InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	BP_InputReleased();
}
