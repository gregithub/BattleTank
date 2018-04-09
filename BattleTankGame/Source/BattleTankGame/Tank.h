// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include"GameFramework/Pawn.h"
#include "CoreMinimal.h"
#include "Tank.generated.h"

class UTankBarrel;	//Forward declaration
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;
UCLASS()
class BATTLETANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	
	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();
protected:
	UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent * TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent * TankMovementComponent = nullptr;

private:	

	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSoeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	
	double LastFireTime = 0;

	UTankBarrel* Barrel = nullptr;
};
