// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BowCharacterBase.h"
#include "AbilitySystem/BowAbilitySystemComponent.h"
#include "PhysicsGuru/AbilitySystem/BowAttributeSet.h"
#include "AbilitySystem/BowBlueprintSystemLibrary.h"

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
	
	AbilitySystemComponent->InitStats(UBowAttributeSet::StaticClass(), nullptr);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void ABowCharacterBase::AddCharacterAbilities()
{
	UBowBlueprintSystemLibrary::GiveStartupAbilities(this, AbilitySystemComponent, CharacterClass);
}

void ABowCharacterBase::InitializeDefaultAttributes() const
{
	UBowBlueprintSystemLibrary::InitializeDefaultAttributes(this, Cast<UAbilitySystemComponent>(AbilitySystemComponent), CharacterClass, Level);
}

