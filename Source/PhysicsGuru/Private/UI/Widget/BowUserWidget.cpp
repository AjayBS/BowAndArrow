// Copyright ConfusedMinds Ltd.


#include "UI/Widget/BowUserWidget.h"

void UBowUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
