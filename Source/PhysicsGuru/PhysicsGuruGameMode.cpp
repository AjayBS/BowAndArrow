// Copyright Epic Games, Inc. All Rights Reserved.

#include "PhysicsGuruGameMode.h"
#include "PhysicsGuruCharacter.h"
#include "UObject/ConstructorHelpers.h"

APhysicsGuruGameMode::APhysicsGuruGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
