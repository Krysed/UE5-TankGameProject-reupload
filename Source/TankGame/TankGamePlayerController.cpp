// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGamePlayerController.h"
#include "GameFramework/Pawn.h"

void ATankGamePlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
	//enabling input
	if (bPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	//disabling input
	else
	{
		GetPawn()->DisableInput(this);
	}
	bShowMouseCursor = bPlayerEnabled;
}