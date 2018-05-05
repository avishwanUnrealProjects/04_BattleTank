// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Engine/World.h"

void UTurret::RotateTurret(float RelativeSpeed)
{
	auto YawChange = FMath::Clamp<float>(RelativeSpeed, -1, 1) * MaxDegreesPerSecond * (GetWorld()->DeltaTimeSeconds);
	// update elevation based on change, clamp as well.
	auto newRawYaw = RelativeRotation.Yaw + YawChange;

	//UE_LOG(LogTemp, Warning, TEXT("Yaw is %f"), newRawYaw);

	SetRelativeRotation(FRotator(0.0, newRawYaw, 0.0));
}


