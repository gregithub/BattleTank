// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTracks;
//TODO prevent double speed from controler and keabord input
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveBackward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendTurnRight(float Throw);
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendTurnLeft(float Throw);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialise(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet);


private:
	UTankTracks *LeftTrack = nullptr;
	UTankTracks *RightTrack = nullptr;
};
