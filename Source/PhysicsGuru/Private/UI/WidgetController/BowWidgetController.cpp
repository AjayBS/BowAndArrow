// Copyright ConfusedMinds Ltd.


#include "UI/WidgetController/BowWidgetController.h"

void UBowWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UBowWidgetController::BroadcastInitialValues()
{
}
