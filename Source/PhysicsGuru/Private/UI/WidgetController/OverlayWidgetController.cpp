// Copyright ConfusedMinds Ltd.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "PhysicsGuru/AbilitySystem/BowAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UBowAttributeSet* BowAttributeSet = CastChecked<UBowAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(BowAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(BowAttributeSet->GetMaxHealth());
}
