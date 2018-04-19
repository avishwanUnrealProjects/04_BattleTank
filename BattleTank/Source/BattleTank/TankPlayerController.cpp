// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Ticking!"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto possessed = GetControlledTank();
	if (possessed)
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessing %s"), *(possessed->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Pawn!"));
	}
}

void ATankPlayerController::AimTowardsCrossHair()
{

}


