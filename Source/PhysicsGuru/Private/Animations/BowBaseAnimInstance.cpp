// Copyright ConfusedMinds Ltd.


#include "Animations/BowBaseAnimInstance.h"
#include "AbilitySystem/BowBlueprintSystemLibrary.h"

bool UBowBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
	if (APawn* OwningPawn = TryGetPawnOwner())
	{
		return UBowBlueprintSystemLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);
	}

	return false;
}
