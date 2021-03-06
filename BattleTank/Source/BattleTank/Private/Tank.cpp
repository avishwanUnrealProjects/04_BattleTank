// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"
// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Tank Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
/*void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::setBarrelReference(UTankBarrel* barrelToSet)
{
	if (!barrelToSet) return;
	tankAimingComponent->setBarrelReference(barrelToSet);
	barrel = barrelToSet;
}

void ATank::setTurretReference(UTurret* turretToSet)
{
	if (!turretToSet) return;
	tankAimingComponent->setTurretReference(turretToSet);
}

void ATank::AimAt(FVector HitLocation)
{
	tankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool isreloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (barrel && ProjectileBP && isreloaded) {
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBP, barrel->GetSocketLocation(FName("Projectile")),
			barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

