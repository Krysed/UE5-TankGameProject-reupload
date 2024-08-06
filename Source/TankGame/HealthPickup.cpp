// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPickup.h"
#include "Components/StaticMeshComponent.h"
#include "PickupItem.h"

//Health Pickup Constructor Implementation
AHealthPickup::AHealthPickup()
{
	//Seting up mesh
	
	HeartCircle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeartCircle"));
	HeartCircle->SetupAttachment(RootComponent);
	
	HeartBar1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeartBar1"));
	HeartBar1->SetupAttachment(HeartCircle);
	
	HeartBar2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeartBar2"));
	HeartBar2->SetupAttachment(HeartCircle);

}