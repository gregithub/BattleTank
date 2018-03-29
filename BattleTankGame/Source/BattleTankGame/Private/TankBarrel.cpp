// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

#include"Engine/World.h"




void UTankBarrel::Elevate(float RelativeSpeed) {
	//if(aimdirection!=barreldirection)
	//move given max elevations peed and the frame time 
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevtion = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevtion, 0, 0));
	
}