// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevateChange = RelativeSpeed*MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevateChange;

	RawNewElevation = FMath::Clamp<float>(RawNewElevation, MinimumDegreesElevation, MaximumDegreesElevation);
	SetRelativeRotation(FRotator(RawNewElevation,0,0));
}
