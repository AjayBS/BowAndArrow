// ConfusedMinds Ltd.


#include "Character/BowCharacter.h"

#include "AbilitySystem/BowAbilitySystemComponent.h"
#include "GameFramework/PlayerState.h"
#include "Player/BowPlayerController.h"
#include "UI/HUD/BowHUD.h"

void ABowCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerState* AuraPlayerState = GetPlayerState<APlayerState>();

	if (ABowPlayerController* BowPlayerController = Cast<ABowPlayerController>(GetController()))
	{
		if (ABowHUD* BowHUD = Cast<ABowHUD>(BowPlayerController->GetHUD()))
		{
			BowHUD->InitOverlay(BowPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}

	InitializeDefaultAttributes();
	AddCharacterAbilities();
}

void ABowCharacter::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ABowCharacter::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
}
