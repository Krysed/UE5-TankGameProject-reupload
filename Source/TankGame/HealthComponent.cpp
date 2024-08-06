// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "GameFramework/Actor.h"
#include "TankGameGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "HealthPickup.h"
#include "Mine.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	//Binding Damage to actors
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakenDamage);

	TankGameGameMode = Cast<ATankGameGameMode>(UGameplayStatics::GetGameMode(this));
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent::TakenDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* Inducer, AActor* DamageCauser)
{
	if (Damage <= 0.f)
	{
		return;
	}
	Health -= Damage;

	UE_LOG(LogTemp, Warning, TEXT("Health: % f"), Health);
	
	if ((Health <= 0.f)&&(TankGameGameMode))
	{
		TankGameGameMode->ActorDead(DamagedActor);
	}
}

/**
 * @brief returns current health value
 * @return current health 
*/
float UHealthComponent::GetHealthPercent() const
{
	return Health / MaxHealth;
}

/**
* @brief Heal target when is within range, called in blueprints
*/
void  UHealthComponent::HealOnOverlap()
{
	if (Health < 100)
	{
		Health = MaxHealth;
	}
}
/**
* @brief Damage target when is within range, called in blueprints
*/
void UHealthComponent::DamageOnOverlap(float Damage)
{
	Health -= Damage;
}