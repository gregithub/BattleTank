// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Components/StaticMeshComponent.h"

void UTankTurret::Rotate(float RelativeSpeetRotation) {
	RelativeSpeetRotation = FMath::Clamp<float>(RelativeSpeetRotation, -1, +1);
	auto RotationChange = RelativeSpeetRotation * MaxDegreesPerSecondRotation *GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}


