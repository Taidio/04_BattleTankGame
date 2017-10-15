// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank) { return; }
	auto ControllerTank = Cast<ATank>(GetPawn());
	if (!ControllerTank) { return; }

	ControllerTank->AimAt(PlayerTank->GetActorLocation());
	ControllerTank->Fire();
}
