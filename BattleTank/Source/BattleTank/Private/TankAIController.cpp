// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto myTank = Cast<ATank>(GetPawn());
	auto playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (myTank)
	{
		myTank->AimAt(playerTank->GetActorLocation());
		myTank->Fire(); //need to limit firing rate
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank not found!"));
	}
}