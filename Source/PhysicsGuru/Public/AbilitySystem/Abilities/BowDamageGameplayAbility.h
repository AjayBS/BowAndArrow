// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/BowGameplayAbility.h"
#include "BowDamageGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API UBowDamageGameplayAbility : public UBowGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void CauseDamage(AActor* TargetActor);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Damage")
	FScalableFloat Damage;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	TMap<FGameplayTag, FScalableFloat> DamageTypes;
};
