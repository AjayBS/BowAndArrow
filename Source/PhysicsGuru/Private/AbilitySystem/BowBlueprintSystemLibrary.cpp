// Copyright ConfusedMinds Ltd.


#include "AbilitySystem/BowBlueprintSystemLibrary.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/BowAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Engine/OverlapResult.h"
#include "GameMode/BowGameModeBase.h"
#include "Interfaces/CombatInterface.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogWarBlueprintLibrary, Warning, All);

UBowAbilitySystemComponent* UBowBlueprintSystemLibrary::NativeGetASCFromActor(AActor* InActor)
{
	check(InActor);

	return CastChecked<UBowAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UBowBlueprintSystemLibrary::GiveStartupAbilities(const UObject* WorldContextObject, UBowAbilitySystemComponent* ASC, ECharacterClass CharacterClass)
{
	UCharacterClassInfo* CharacterClassInfo = GetCharacterClassInfo(WorldContextObject);
	FCharacterClassDefaultInfo DefaultInfo = CharacterClassInfo->GetClassDefaultInfo(CharacterClass);

	ASC->AddCharacterAbilities(DefaultInfo.Abilities);
}

UCharacterClassInfo* UBowBlueprintSystemLibrary::GetCharacterClassInfo(const UObject* WorldContextObject)
{
	ABowGameModeBase* BowGameMode = Cast<ABowGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject));
	if (BowGameMode == nullptr)
	{
		UE_LOG(LogWarBlueprintLibrary, Warning, TEXT("Game mode is nullptr. Returning."));
		return nullptr;
	}
	return BowGameMode->CharacterClassInfo.GetDefaultObject();
}

void UBowBlueprintSystemLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject, UAbilitySystemComponent* ASC, ECharacterClass CharacterClass, float Level)
{
	UCharacterClassInfo* CharacterClassInfo = GetCharacterClassInfo(WorldContextObject);
	FCharacterClassDefaultInfo DefaultInfo = CharacterClassInfo->GetClassDefaultInfo(CharacterClass);

	const FGameplayEffectSpecHandle PrimaryAttributesSpecHandle = ASC->MakeOutgoingSpec(DefaultInfo.PrimaryAttributes, Level, ASC->MakeEffectContext());
	ASC->ApplyGameplayEffectSpecToSelf(*PrimaryAttributesSpecHandle.Data.Get());
}

void UBowBlueprintSystemLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UBowAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);

	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UBowBlueprintSystemLibrary::RemoveGameplayFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UBowAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);

	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UBowBlueprintSystemLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	if (InActor != nullptr)
	{
		UBowAbilitySystemComponent* ASC = NativeGetASCFromActor(InActor);
		return ASC->HasMatchingGameplayTag(TagToCheck);
	}

	return false;
}

void UBowBlueprintSystemLibrary::GetLivePlayersWithinRadius(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappingActors, 
	const TArray<AActor*>& ActorsToIgnore, float Radius, const FVector& SphereOrigin)
{
	FCollisionQueryParams SphereParams;
	SphereParams.AddIgnoredActors(ActorsToIgnore);

	TArray<FOverlapResult> Overlaps;
	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		World->OverlapMultiByObjectType(Overlaps, SphereOrigin, FQuat::Identity, FCollisionObjectQueryParams(FCollisionObjectQueryParams::InitType::AllDynamicObjects), FCollisionShape::MakeSphere(Radius), SphereParams);
		for (FOverlapResult& Overlap : Overlaps)
		{
			if (Overlap.GetActor()->Implements<UCombatInterface>() && !ICombatInterface::Execute_IsDead(Overlap.GetActor()))
			{
				OutOverlappingActors.AddUnique(ICombatInterface::Execute_GetAvatar(Overlap.GetActor()));
			}
		}
	}
}
