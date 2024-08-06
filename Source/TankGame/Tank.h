// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 *
 */
UCLASS()
class TANKGAME_API ATank : public ABasePawn
{
	GENERATED_BODY()


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/**
	 * Components for Tank Pawn
	*/
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UCameraComponent* Camera;

	/**
	 * Components for HUD MiniMap
	*/
	UPROPERTY(VisibleAnywhere, Category = "Components")
		USpringArmComponent* MiniMapSpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USceneCaptureComponent2D* MiniMapCamera;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MiniMapArrow;

	/**
	 * @Values for Movement configuration
	*/
	UPROPERTY(EditAnywhere, Category = "Movement")
		float Speed = 900.f;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float TurnRate = 120.f;

	UPROPERTY(EditAnywhere, Category = "")
		APlayerController* TankPlayerController;

	/**
	 * @Move function
	 * @param Value  = how fast is Tank going to move
	*/
	void Move(float Value);

	/**
	 * @Function that allow tank to turn
	 * @param Value = How fast is turning gonna take place
	*/
	void Turn(float Value);

	void RotateTurret();
public:
	/**
	 * Tank Class Constructor Declaration
	*/
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void HandleDestruction();

	//Getter for TankPlayerController variable
	APlayerController* GetTankPlayerController() const;

	bool bAlive = true;
};
