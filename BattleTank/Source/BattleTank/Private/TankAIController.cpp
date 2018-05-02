// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//ATank* atank = GetControlledTank();
	ATank* playertank = GetPlayerTank(); 
	if (playertank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found player tank %s"), *(playertank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No player tank found!"));
	}
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto myTank = GetControlledTank();
	if (myTank)
	{
		myTank->AimAt(GetPlayerTank()->GetActorLocation());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank not found!"));
	}
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}