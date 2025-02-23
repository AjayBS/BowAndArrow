// ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Character/BowCharacterBase.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "Interfaces/EnemyInterface.h"
#include "BowEnemy.generated.h"

class UWidgetComponent;

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API ABowEnemy : public ABowCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Gameplay Attributes")
	float Health;

	UPROPERTY(EditAnywhere, Category = "Gameplay Attributes")
	float MaxHealth;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	TObjectPtr<AActor> CombatTarget;

	ABowEnemy();
	virtual void BeginPlay() override;

	/** Enemy Interface */
	virtual void SetCombatTarget_Implementation(AActor* InCombatTarget) override;
	virtual AActor* GetCombatTarget_Implementation() const override;
	/** End Enemy Interface */

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;
	
};
