// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Animations/BowBaseAnimInstance.h"
#include "BowCharacterAnimInstance.generated.h"

class ABowCharacterBase;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API UBowCharacterAnimInstance : public UBowBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	ABowCharacterBase* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float LocomotionDirection;
	
};
