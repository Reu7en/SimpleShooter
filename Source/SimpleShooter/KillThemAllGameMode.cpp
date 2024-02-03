// Fill out your copyright notice in the Description page of Project Settings.


#include "KillThemAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"

void AKillThemAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	APlayerController* PlayerController =  Cast<APlayerController>(PawnKilled->GetController());

	if (PlayerController)
	{
		EndGame(false);
	}
}

void AKillThemAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = (Controller->IsPlayerController() == bIsPlayerWinner);

		Controller->GameHasEnded(Controller->GetPawn(), bIsPlayerWinner);
	}
}