// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"
#include "Engine/World.h"


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
	if (!GetControlledTank()) { return; }
	FVector HitLocation; //out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString())

	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	FHitResult Hit;
	if (GetWorld()->LineTraceSingleByChannel(
		Hit,
		GetControlledTank()->GetActorLocation(),
		GetControlledTank()->GetActorLocation() * 10000,
		ECollisionChannel::ECC_WorldStatic,
		FCollisionQueryParams(),
		FCollisionResponseParams(ECollisionResponse::ECR_Block))
		)
	{
		return true;
		OutHitLocation = Hit.Location;
	}
	else
	{
		return false;
	}
	
}


