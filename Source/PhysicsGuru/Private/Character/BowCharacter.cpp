// ConfusedMinds Ltd.


#include "Character/BowCharacter.h"
#include "GameFramework/PlayerState.h"
#include "Player/BowPlayerController.h"
#include "UI/HUD/BowHUD.h"

void ABowCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerState* AuraPlayerState = GetPlayerState<APlayerState>();

	if (ABowPlayerController* BowPlayerController = Cast<ABowPlayerController>(GetController()))
	{
		if (ABowHUD* BowHUD = Cast<ABowHUD>(BowPlayerController->GetHUD()))
		{
			BowHUD->InitOverlay(BowPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}
