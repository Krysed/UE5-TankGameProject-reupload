// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTank.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "BasePawn.h"
#include "GameFramework/FloatingPawnMovement.h"

/**
 * @brief Called every frame
*/
AEnemyTank::AEnemyTank()
{
	FloatingMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingMovementComponent"));
}
void AEnemyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (InRangeToLookAtTank())
	{
		BaseRotation(Tank->GetActorLocation());
		if (InFireRangeWithTank())
		{
			
			TurretRotation(Tank->GetActorLocation());
		}
	}
}
void AEnemyTank::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

//Called upon start of the game
void AEnemyTank::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	/**
	 * @brief Setting a function to a timer
	*/
	GetWorldTimerManager().SetTimer(
		FireRateTimerHandle,
		this,
		&AEnemyTank::CheckFireCondition,
		FireRate,
		true
	);
}

/**
 * @brief if Target is within FireRange call Fire()
*/
void AEnemyTank::CheckFireCondition()
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
bool AEnemyTank::InFireRangeWithTank()
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

//Rotate Base of tank if Player is in range
bool AEnemyTank::InRangeToLookAtTank()
{
	if (Tank)
	{
		//Distance (vector) between Turret and Tank
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		if (Distance <= BaseRotateRange)
		{
			return true;
		}
	}
	//when out of range or target is not valid
	return false;
}
void AEnemyTank::BaseRotation(FVector LookAtTarget)
{
	FVector ToTargetVector = LookAtTarget - BaseMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(
		0.f,							//Pitch
		ToTargetVector.Rotation().Yaw,	//Yaw
		0.f								//Roll	
	);

	//Rotating Base
	BaseMesh->SetWorldRotation(
		FMath::RInterpTo(
			BaseMesh->GetComponentRotation(),
			LookAtRotation,
			UGameplayStatics::GetWorldDeltaSeconds(this),
			2.f
		)
	);
}