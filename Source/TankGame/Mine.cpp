// Fill out your copyright notice in the Description page of Project Settings.


#include "Mine.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AMine::AMine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/**
	 * @brief Seting up components for landmine
	*/
	LandMineBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LandMineBase"));
	RootComponent = LandMineBase;

	LandMineLamp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LandMineLight"));
	LandMineLamp->SetupAttachment(LandMineBase);

	LandMineCollision = CreateDefaultSubobject<USphereComponent>(TEXT("LandMineCollision"));
	LandMineCollision->SetupAttachment(LandMineBase);
}

// Called when the game starts or when spawned
void AMine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
