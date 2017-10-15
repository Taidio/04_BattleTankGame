// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Azimuth(float RelativeSpeed)
{

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto AzimuthChange = RelativeSpeed*MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewAzimuth = RelativeRotation.Yaw + AzimuthChange;
	
	RawNewAzimuth = FMath::Clamp<float>(RawNewAzimuth, MinimumDegreesAzimuth, MaximumDegreesAzimuth);
	SetRelativeRotation(FRotator(0, RawNewAzimuth,0));
	UE_LOG(LogTemp, Warning, TEXT("TurretAzimuth: %f"),RawNewAzimuth)
}




