// Copyright ConfusedMinds Ltd.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "PhysicsGuru/AbilitySystem/BowAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UBowAttributeSet* BowAttributeSet = CastChecked<UBowAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(BowAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(BowAttributeSet->GetMaxHealth());
	OnStaminaChanged.Broadcast(BowAttributeSet->GetStamina());
	OnMaxStaminaChanged.Broadcast(BowAttributeSet->GetMaxStamina());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UBowAttributeSet* BowAttributeSet = CastChecked<UBowAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BowAttributeSet->GetHealthAttribute()).AddUObject(
		this,
		&UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BowAttributeSet->GetMaxHealthAttribute()).AddUObject(
		this,
		&UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BowAttributeSet->GetStaminaAttribute()).AddUObject(
		this,
		&UOverlayWidgetController::StaminaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BowAttributeSet->GetMaxStaminaAttribute()).AddUObject(
		this,
		&UOverlayWidgetController::MaxStaminaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::StaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnStaminaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxStaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxStaminaChanged.Broadcast(Data.NewValue);
}
