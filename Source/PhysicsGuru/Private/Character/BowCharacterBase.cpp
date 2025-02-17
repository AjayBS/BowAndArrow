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
	
	AbilitySystemComponent->InitStats(UBowAttributeSet::StaticClass(), nullptr);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void ABowCharacterBase::AddCharacterAbilities()
{
	UBowAbilitySystemComponent* BowASC = CastChecked<UBowAbilitySystemComponent>(AbilitySystemComponent);
	BowASC->AddCharacterAbilities(StartupAbilities);
}

void ABowCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	FActiveGameplayEffectHandle Handle = GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
	if (!Handle.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to apply Gameplay Effect"));
	}
}

void ABowCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
}

