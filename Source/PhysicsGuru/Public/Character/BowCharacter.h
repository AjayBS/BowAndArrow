// ConfusedMinds Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Character/BowCharacterBase.h"
#include "BowCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PHYSICSGURU_API ABowCharacter : public ABowCharacterBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
};
