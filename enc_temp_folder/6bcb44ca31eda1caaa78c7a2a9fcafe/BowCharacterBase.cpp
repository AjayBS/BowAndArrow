// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BowCharacterBase.h"

ABowCharacterBase::ABowCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ABowCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

