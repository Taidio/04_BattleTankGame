// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	

	if(GetAITank())
	{
		auto AITank = GetAITank();
		UE_LOG(LogTemp, Warning, TEXT("I'm AI controller: %s!"),*AITank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("I am not existing"))
	}
}


ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}
