// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BowPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API ABowPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABowPlayerController();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> BowContext;
};
