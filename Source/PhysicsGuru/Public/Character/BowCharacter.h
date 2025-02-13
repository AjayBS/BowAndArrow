// ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Character/BowCharacterBase.h"
#include "BowCharacter.generated.h"

class UGameplayEffect;

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API ABowCharacter : public ABowCharacterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

protected:
	virtual void BeginPlay() override;
	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;
	void InitializeDefaultAttributes() const;
	
};
