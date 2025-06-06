// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/CombatInterface.h"
#include "CharacterClassInfo.h"
#include "BowCharacterBase.generated.h"

class UAbilitySystemComponent;
class UBowAbilitySystemComponent;
class UBowAttributeSet;
class UGameplayAbility;
class UGameplayEffect;

UCLASS(Abstract)
class PHYSICSGURU_API ABowCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	ABowCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	/** Combat Interface */
	virtual FVector GetCombatSocketLocation_Implementation() override;
	virtual bool IsDead_Implementation() const override;
	virtual AActor* GetAvatar_Implementation() override;
	/** End Combat Interface */

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;
	UBowAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	virtual void BeginPlay() override;
	void AddCharacterAbilities();
	void InitializeDefaultAttributes() const;

	bool bDead = false;

	UPROPERTY(EditAnywhere, Category = "Combat")
	FName MeshSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	ECharacterClass CharacterClass = ECharacterClass::Player;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(EditAnywhere, Category= "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UBowAbilitySystemComponent> AbilitySystemComponent;

	TObjectPtr<UBowAttributeSet> AttributeSet;

private:
	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
};
