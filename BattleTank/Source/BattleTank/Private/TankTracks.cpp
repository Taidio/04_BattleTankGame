// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"




void UTankTracks::SetThrottle(float Throttle)
{
	Throttle = FMath::Clamp<float>(Throttle, -1, 1);
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	//aplying force at TankRoot primitive component
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}