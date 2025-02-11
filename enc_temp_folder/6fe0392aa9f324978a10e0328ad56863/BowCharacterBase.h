// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BowCharacterBase.generated.h"

UCLASS(Abstract)
class PHYSICSGURU_API ABowCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ABowCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category= "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
