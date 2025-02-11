// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BowUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API UBowUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
