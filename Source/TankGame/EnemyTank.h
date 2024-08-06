// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "EnemyTank.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API AEnemyTank : public ABasePawn
{
	GENERATED_BODY()
	

private:
	float FireRate = 2.5;
	FTimerHandle FireRateTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//Forward declaring tank to not include too many files in header
	class ATank* Tank;

	UPROPERTY(EditAnywhere, Category = "CombatSettings")
		float FireRange = 1500.f;
	UPROPERTY(EditAnywhere, Category = "CombatSettings")
		float BaseRotateRange = 4000.f;

	//Movement Component
	UPROPERTY(EditAnywhere, Category = "Movement")
		class UFloatingPawnMovement* FloatingMovementComponent;

	/**
	 * @brief Check if target is valid and call Fire() function if valid
	*/
	void CheckFireCondition();

	/**
	 * @brief check if target is in FireRange
	 * @return true or false
	*/
	bool InFireRangeWithTank();
	bool InRangeToLookAtTank();
	//set tank rotation
	void BaseRotation(FVector LookAtTarget);
public:
	//Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	//Constructor
	AEnemyTank();
};
