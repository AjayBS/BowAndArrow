// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "ArrowActor.generated.h"

class UGameplayEffect;

UCLASS()
class PHYSICSGURU_API AArrowActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrowActor();

	UFUNCTION(BlueprintCallable, Category = "Damage")
	void ApplyDamageToCharacter(AActor* OtherActor);

	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	FGameplayEffectSpecHandle DamageEffectSpecHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gameplay Effects")
	TSubclassOf<UGameplayEffect> DamageEffectClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
