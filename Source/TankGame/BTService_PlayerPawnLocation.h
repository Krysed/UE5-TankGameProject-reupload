// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PlayerPawnLocation.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API UBTService_PlayerPawnLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTService_PlayerPawnLocation();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};
