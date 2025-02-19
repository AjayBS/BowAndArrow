// Copyright ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "GenericTeamAgentInterface.h"
#include "BowPlayerController.generated.h"

class UInputMappingContext;
class UBowInputConfig;
class UBowAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API ABowPlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ABowPlayerController();

	// Begin IGenericTeamAgentInterface interface
	virtual FGenericTeamId GetGenericTeamId() const override;
	// End IGenericTeamAgentInterface interface

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	UBowAbilitySystemComponent* GetASC();

	FGenericTeamId HeroTeamId;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> BowContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UBowInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UBowAbilitySystemComponent> BowAbilitySystemComponent;
};
