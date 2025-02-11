// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BowCharacterBase.h"
#include "AbilitySystem/BowAbilitySystemComponent.h"
#include "PhysicsGuru/AbilitySystem/BowAttributeSet.h"

ABowCharacterBase::ABowCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	AbilitySystemComponent = CreateDefaultSubobject<UBowAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UBowAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ABowCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ABowCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

