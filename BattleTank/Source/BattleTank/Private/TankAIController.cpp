// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	
	if(GetPlayerTank())
	{
		auto PlayerTank = GetPlayerTank();
		UE_LOG(LogTemp, Warning, TEXT("I have found Player Tank: %s"),*PlayerTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("I have not found Player Tank"))
	}
}


ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
}