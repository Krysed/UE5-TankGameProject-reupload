// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePawn.h"
#include "EnemyTank.h"
#include "TankAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
		//get player pawn
		//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		//get location of Pawn and save it on blackboard
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}
void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}