// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Ticking!"));
	AimTowardsCrossHair();
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
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *(HitLocation.ToString()));
		// TODO tell controlled tank to aim at this point
	}
}

// get world location of line trace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}


