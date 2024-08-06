// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerPawnLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"

//constructor
UBTService_PlayerPawnLocation::UBTService_PlayerPawnLocation()
{
	NodeName = TEXT("UpdatePlayerPawnLocation");
}

/**
 * @brief Updating player location
*/
void UBTService_PlayerPawnLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
	}
}