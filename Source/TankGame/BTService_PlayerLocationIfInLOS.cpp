// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfInLOS.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"

UBTService_PlayerLocationIfInLOS::UBTService_PlayerLocationIfInLOS()
{
	NodeName = TEXT("UpdatePlayerLocationIfInLineOfSight");
}

void UBTService_PlayerLocationIfInLOS::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	//Safty check 1
	if (PlayerPawn == nullptr)
	{
		return;
	}
	//Safty check 2
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}
	//If Player in line of sight update player location
	if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
	}
	//clear player location
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}