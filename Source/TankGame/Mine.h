// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mine.generated.h"

UCLASS()
class TANKGAME_API AMine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMine();

	/**
	 * @brief setting landmine Components
	*/
	UPROPERTY(EditAnywhere, Category = "Componentes")
		class UStaticMeshComponent* LandMineBase;
	UPROPERTY(EditAnywhere, Category = "Componentes")
		UStaticMeshComponent* LandMineLamp;
	UPROPERTY(EditAnywhere, Category = "Componentes")
		class USphereComponent* LandMineCollision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
