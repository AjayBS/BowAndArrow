// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTS_OrientToTargetActor.generated.h"

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API UBTS_OrientToTargetActor : public UBTService
{
	GENERATED_BODY()

private:
	UBTS_OrientToTargetActor();

	// Begin UBTNode interface
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;
	virtual FString GetStaticDescription() const override;
	// End UBTNode interface

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = "Target")
	FBlackboardKeySelector InTargetActorKey;

	UPROPERTY(EditAnywhere, Category = "Target")
	float RotationInterpSpeed;
	
};
