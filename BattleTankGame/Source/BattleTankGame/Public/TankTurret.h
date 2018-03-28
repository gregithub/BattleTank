// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankTurret.generated.h"

class UStaticMeshComponent;

UCLASS(meta = (BlueprintSpawnableComponent))//, hidecategories = ("Collision"))
class BATTLETANKGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Rotate(float RelativeSpeedRotation);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecondRotation = 20;
};
