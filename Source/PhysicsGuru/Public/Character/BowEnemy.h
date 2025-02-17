// ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Character/BowCharacterBase.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "BowEnemy.generated.h"

class UWidgetComponent;

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API ABowEnemy : public ABowCharacterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Gameplay Attributes")
	float Health;

	UPROPERTY(EditAnywhere, Category = "Gameplay Attributes")
	float MaxHealth;

	ABowEnemy();
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;
	
};
