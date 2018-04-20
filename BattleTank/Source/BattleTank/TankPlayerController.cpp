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
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *(HitLocation.ToString()));
		// TODO tell controlled tank to aim at this point
	}
}

// get world location of line trace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//1. Find the crosshair position in pixel coordinates.
	int32 SizeX;
	int32 SizeY;
	// size of the view port
	GetViewportSize(SizeX, SizeY);
	// scale it by fraction of x and y  to get pixel location of cross hair.
	FVector2D ScreenLocation(SizeX*CrossHairXLocation, SizeY*CrossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("CrossHair Location %s"), *(ScreenLocation.ToString()));

	//2. De-project cross hair location to world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("LookDirection %s"), *LookDirection.ToString());
	}

	//3. Line-trace along that look direction and see what we hit.
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& lookdirection) const
{
	FVector CameraLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, lookdirection);	
}


