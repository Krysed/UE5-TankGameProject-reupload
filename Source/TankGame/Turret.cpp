// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (InFireRangeWithTank())
	{
		TurretRotation(Tank->GetActorLocation());
	}
}
void ATurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

//Called upon start of the game
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	/**
	 * @brief Setting a function to a timer
	*/
	GetWorldTimerManager().SetTimer(
		FireRateTimerHandle,
		this,
		&ATurret::CheckFireCondition,
		FireRate,
		true
	);
}

/**
 * @brief if Target is within FireRange call Fire()
*/
void ATurret::CheckFireCondition()
{
	if (Tank)
	{
		if (InFireRangeWithTank() && Tank->bAlive)
		{
			Fire();
		}
	}
}

/**
 * @brief Check distance between actor and a tank
 * @return
*/
bool ATurret::InFireRangeWithTank()
{
	if (Tank)
	{
		//Distance (vector) between Turret and Tank
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		if (Distance <= FireRange)
		{
			return true;
		}
	}
	//when out of range or target is not valid
	return false;
}