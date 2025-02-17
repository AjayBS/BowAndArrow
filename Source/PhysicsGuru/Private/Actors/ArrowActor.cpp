// Copyright ConfusedMinds Ltd.


#include "Actors/ArrowActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "BowGameplayTags.h"
#include "Character/BowEnemy.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AArrowActor::AArrowActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AArrowActor::ApplyDamageToCharacter(AActor* OtherActor)
{	
	if (UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor))
	{
		FGameplayEffectContextHandle EffectContext = TargetASC->MakeEffectContext();
		EffectContext.AddSourceObject(this);
		const FGameplayEffectSpecHandle SpecHandle = TargetASC->MakeOutgoingSpec(DamageEffectClass, 1, EffectContext);

		TargetASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}	
}

// Called when the game starts or when spawned
void AArrowActor::BeginPlay()
{
	Super::BeginPlay();
	
}
