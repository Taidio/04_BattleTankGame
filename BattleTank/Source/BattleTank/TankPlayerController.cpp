// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank())
	{
		auto PossessedTank = GetControlledTank();
		UE_LOG(LogTemp, Warning, TEXT("You are possessing %s"),*PossessedTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("You are possessing nothing"))
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}



ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair()
{
	return;
}