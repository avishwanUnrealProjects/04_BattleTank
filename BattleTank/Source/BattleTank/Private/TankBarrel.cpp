// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	// move barrel the right amount this frame
	// given a max elevation speed and frame time
	//UE_LOG(LogTemp, Warning, TEXT("Elevating Barrel by %f"), RelativeSpeed);
	// clamp relative speed within limits
	// deltatimeseconds is frame rate so we calculate elevation change per frame time
	auto ElevationChange = FMath::Clamp<float>(RelativeSpeed, -1, 1) * MaxDegreesPerSecond * (GetWorld()->DeltaTimeSeconds);
	// update elevation based on change, clamp as well.
	auto newRawElevation = FMath::Clamp<float>(RelativeRotation.Pitch + ElevationChange, 
		MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(newRawElevation, 0.0, 0.0));
}


