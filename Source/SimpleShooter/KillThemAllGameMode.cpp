// Fill out your copyright notice in the Description page of Project Settings.


#include "KillThemAllGameMode.h"

void AKillThemAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	APlayerController* PlayerController =  Cast<APlayerController>(PawnKilled->GetController());

	if (PlayerController)
	{
		PlayerController->GameHasEnded(nullptr, false);
	}
}