// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStaticsTypes.h"
#include "Kismet/GameplayStatics.h"
#include "CollisionQueryParams.h"
#include "TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;// should this really tick?

	// ...
}

void UTankAimingComponent::setBarrelReference(UTankBarrel* barrelToSet)
{
	barrel = barrelToSet;
}
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//auto BarrelLocation = barrel->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *(GetOwner()->GetName()),*HitLocation.ToString(), *BarrelLocation.ToString());
	if (barrel == nullptr)
		return;

	auto StartLocation = barrel->GetSocketLocation(FName("Projectile"));
	FVector OutLaunchVelocity;
	if (UGameplayStatics::SuggestProjectileVelocity(this,
		OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0,
		ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("Firing at %s"), *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim direction solution found"), Time);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No aim direction solution"), Time);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// work out difference between current barrel rotation and aim direction
	//auto AimRotator = barrel->GetSocketRotation(FName("Projectile"));
	//UE_LOG(LogTemp, Warning, TEXT("Socket rotation: %s"), *AimRotator.ToString());
	auto barrelRotator = barrel->GetForwardVector().Rotation();
	//UE_LOG(LogTemp, Warning, TEXT("rotation: %s"), *barrelRotator.ToString());
	auto aimRotator = AimDirection.Rotation();
	auto deltaRotator = aimRotator - barrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *deltaRotator.ToString());
	barrel->ElevateBarrel(deltaRotator.Pitch);
	
}

