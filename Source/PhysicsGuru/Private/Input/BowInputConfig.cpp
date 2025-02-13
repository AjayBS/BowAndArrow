// Copyright ConfusedMinds Ltd.


#include "Input/BowInputConfig.h"
#include "InputAction.h"

const UInputAction* UBowInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FBowInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cant find ability input action for InputTag [%s], on InputConfig [%s]"), 
			*InputTag.ToString(), *GetNameSafe(this))
	}

	return nullptr;
}
