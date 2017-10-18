// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTracks;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable)
	void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable)
	void IntendTurnRight(float Throw);
	UFUNCTION(BlueprintCallable)
	void IntendTurnLeft(float Throw);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTracks *LeftTrackToSet, UTankTracks *RightTrackToSet);
	
private:
	UTankTracks *LeftTrack = nullptr;
	UTankTracks *RightTrack = nullptr;


	
};
