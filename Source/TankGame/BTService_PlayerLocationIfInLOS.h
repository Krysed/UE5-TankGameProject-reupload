// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PlayerLocationIfInLOS.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API UBTService_PlayerLocationIfInLOS : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTService_PlayerLocationIfInLOS();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};
