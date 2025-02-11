// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BowHUD.generated.h"

class UBowUserWidget;
class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayWidgetController;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API ABowHUD : public AHUD
{
	GENERATED_BODY()

public:
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

	UPROPERTY()
	TObjectPtr<UBowUserWidget> OverlayWidget;

protected:
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UBowUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;	
};
