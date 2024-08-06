// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupItem.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API AHealthPickup : public APickupItem
{
	GENERATED_BODY()
	
public:
	//Constructor
	AHealthPickup();

	//Setting up static mesh for HealthPickup
	UPROPERTY(EditAnywhere, Category = "Components")
		class UStaticMeshComponent* HeartBar1;

	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* HeartBar2;
	
	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* HeartCircle;

};
