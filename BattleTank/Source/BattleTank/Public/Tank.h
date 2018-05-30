// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void setBarrelReference(UTankBarrel* barrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void setTurretReference(UTurret* turretToSet);	

	UFUNCTION(BlueprintCallable)
	void Fire();	

protected:
	UTankAimingComponent * tankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000; // 40 m/s	

	UPROPERTY(EditAnywhere, Category = Setup)
	//UClass* ProjectileBP;
	TSubclassOf<AProjectile> ProjectileBP;

	// Local reference to tank barrel
	UTankBarrel* barrel = nullptr;

	float ReloadTimeInSeconds = 3.0;

	double LastFireTime = 0;
};
