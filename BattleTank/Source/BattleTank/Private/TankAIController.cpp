// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* atank = GetControlledTank();
	if (atank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessing AI tank %s"), *(atank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI possessed!"));
	}
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
