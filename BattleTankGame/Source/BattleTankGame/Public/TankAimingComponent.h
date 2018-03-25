// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel; //Forward declaration

//Holds parameters properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKGAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();


	void AimAt(FVector HitLocation,float LaunchSoeed);

	void SetBarrellRefference(UTankBarrel * BarrelToSet);

	
private:
	UTankBarrel * Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
