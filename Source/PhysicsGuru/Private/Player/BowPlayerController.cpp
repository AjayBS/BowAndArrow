// Copyright ConfusedMinds Ltd.

#include "Player/BowPlayerController.h"
#include "EnhancedInputSubsystems.h"

ABowPlayerController::ABowPlayerController()
{
}

void ABowPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(BowContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(BowContext, 1);
	}	
}
