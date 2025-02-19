// Copyright ConfusedMinds Ltd.

#include "Player/BowPlayerController.h"

#include "AbilitySystem/BowAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "Input/BowInputComponent.h"

ABowPlayerController::ABowPlayerController()
{
	HeroTeamId = FGenericTeamId(0);
}

FGenericTeamId ABowPlayerController::GetGenericTeamId() const
{
	return HeroTeamId;
}

void ABowPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(BowContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(BowContext, 1);
	}	
}

void ABowPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UBowInputComponent* BowInputComponent = CastChecked<UBowInputComponent>(InputComponent);

	BowInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, 
		&ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void ABowPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	
}

void ABowPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (GetASC() == nullptr)
	{
		return;
	}

	GetASC()->AbilityInputTagReleased(InputTag);
}

void ABowPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	if (GetASC() == nullptr)
	{
		return;
	}

	GetASC()->AbilityInputTagHeld(InputTag);
}

UBowAbilitySystemComponent* ABowPlayerController::GetASC()
{
	if (BowAbilitySystemComponent == nullptr)
	{
		BowAbilitySystemComponent = Cast<UBowAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}

	return BowAbilitySystemComponent;
}
