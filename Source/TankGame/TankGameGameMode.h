// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:
	//forward declaring ATank variable;
	class ATank* Tank;

	//forward declaring ATankGamePlayerController variable
	class ATankGamePlayerController* TankGamePlayerController;

	//number of turrets variable to destroy in each level
	int32 TargetTurrets = 0;
	/**
	 * @brief get all turret places in level
	 * @return number of towers 
	*/
	int32 GetTargetTurretCount();

	float StartGameDelay = 3.f;

	void HandleGameStart();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
		void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
		void GameOver(bool bWonGame);

public:
	/**
	 * @brief Handling Death
	 * @param DeadActor = Actor that will be dead
	*/
	UFUNCTION(BlueprintCallable)
	void ActorDead(AActor* DeadActor);
};
