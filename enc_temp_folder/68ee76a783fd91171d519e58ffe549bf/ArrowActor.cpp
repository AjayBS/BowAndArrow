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
	if (ABowEnemy* BowEnemy = Cast<ABowEnemy>(OtherActor))
	{
		ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		if (UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor))
		{
			FGameplayEffectContextHandle EffectContext = TargetASC->MakeEffectContext();
			EffectContext.AddSourceObject(this);
			const FGameplayEffectSpecHandle SpecHandle = TargetASC->MakeOutgoingSpec(DamageEffectClass, 1, EffectContext);
			if (!SpecHandle.IsValid())
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to create a valid GameplayEffectSpec!"));
				return;
			}
			const FBowGameplayTags GameplayTags = FBowGameplayTags::Get();
			//UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Arrow_Damage, -25.f);
			//FActiveGameplayEffectHandle Handle = TargetASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), TargetASC);
			FActiveGameplayEffectHandle Handle = TargetASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());

			if (!Handle.IsValid())
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to apply Gameplay Effect"));
			}
		}
	}
	
}

// Called when the game starts or when spawned
void AArrowActor::BeginPlay()
{
	Super::BeginPlay();
	
}
