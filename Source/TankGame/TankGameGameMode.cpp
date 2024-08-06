// Fill out your copyright notice in the Description page of Project Settings.

#include "Mine.h"
#include "Tank.h"
#include "Turret.h"
#include "EnemyTank.h"
#include "TankGamePlayerController.h"
#include "TankGameGameMode.h"
#include "Kismet/GameplayStatics.h"


void ATankGameGameMode::ActorDead(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();

		if (TankGamePlayerController)
		{
			TankGamePlayerController->SetPlayerEnabledState(false);
		}
		GameOver(false);
	}
	else if (ATurret* DestroyedTurret = Cast<ATurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();
		TargetTurrets--;
		if (TargetTurrets == 0)
		{
			GameOver(true);
		}
	}
	else if (AEnemyTank* DestroyedEnemyTank = Cast<AEnemyTank>(DeadActor))
	{
		DestroyedEnemyTank->HandleDestruction();
	}
}

/**
 * @brief Binding Start game function to timer delegate
*/
void ATankGameGameMode::HandleGameStart()
{
	//Set Number of Turrets to Destroy
	TargetTurrets = GetTargetTurretCount();

	//Get PlayerPawn
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	//Set player controller pointer
	TankGamePlayerController = Cast<ATankGamePlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();

	//if TankGamePlayerControlleris valid at begining of the game disabling input
	if (TankGamePlayerController)
	{
		TankGamePlayerController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(TankGamePlayerController, 
																				&ATankGamePlayerController::SetPlayerEnabledState, 
																				true
		);
		
		//Setting up Delay before player can control the pawn
		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, 
										PlayerEnableTimerDelegate, 
										StartGameDelay, 
										false
		);
	}
}

//Called upon Game start
void ATankGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}

/**
 * @brief returns all actors of Turret class
 * @return number of placer Turrets
*/
int32 ATankGameGameMode::GetTargetTurretCount()
{
	TArray<AActor*> Turrets;

	UGameplayStatics::GetAllActorsOfClass(this, ATurret::StaticClass(),Turrets);
	return Turrets.Num();
}