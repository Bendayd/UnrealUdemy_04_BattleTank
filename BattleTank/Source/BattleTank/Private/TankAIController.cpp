// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	AActor *PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{

		UE_LOG(LogTemp, Warning, TEXT("AIController can't find the player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController : %s is the player tank"), *(PlayerTank->GetName()));
	}
}

ATank *ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

APawn *ATankAIController::GetPlayerTank() const
{
	APawn *PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return PlayerPawn;

}