// ConfusedMinds Ltd.


#include "Character/BowEnemy.h"

#include "Components/WidgetComponent.h"
#include "AbilitySystem/BowAbilitySystemComponent.h"
#include "PhysicsGuru/AbilitySystem/BowAttributeSet.h"
#include "UI/Widget/BowUserWidget.h"

ABowEnemy::ABowEnemy()
{
	HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBar->SetupAttachment(GetRootComponent());
}

void ABowEnemy::BeginPlay()
{
	Super::BeginPlay();

	AddCharacterAbilities();
	InitializeDefaultAttributes();

	UBowUserWidget* BowUserWidget = Cast<UBowUserWidget>(HealthBar->GetUserWidgetObject());
	if (BowUserWidget)
	{
		BowUserWidget->SetWidgetController(this);
	}

	const UBowAttributeSet* BowAS = Cast<UBowAttributeSet>(AttributeSet);
	if (BowAS)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BowAS->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BowAS->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
		);

		OnHealthChanged.Broadcast(Health);
		OnMaxHealthChanged.Broadcast(MaxHealth);
	}
	
}
