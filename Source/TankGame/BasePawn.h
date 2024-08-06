// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TANKGAME_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	//Calling it from the game mode so it needs to be in public section
	void HandleDestruction();

	/**
	 * @brief Setting SFX
	*/
	UPROPERTY(EditAnywhere, Category = "SFX")
		class UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category = "SFX")
		class USoundBase* DeathSound;
	
	UPROPERTY(EditAnywhere, Category = "SFX")
		TSubclassOf<class UCameraShakeBase> DeathCameraShake;

private:
	/**
	 * Setting Up Components trough C++ side
	*/
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UCapsuleComponent* CapsuleComp;


	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* TurretMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
		USceneComponent* ProjectileSpawnPoint;	

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
		TSubclassOf<class AProjectile> ProjectileClass;

protected:

	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* BaseMesh;
	
	void TurretRotation(FVector LookAtTarget);

	void Fire();
};
