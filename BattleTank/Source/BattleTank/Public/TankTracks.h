// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	//Max Force on Tracks in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000; // assuming 40t Tank and 1g acceleration

};
