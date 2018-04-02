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

	UFUNCTION(BlueprintCallable, Category=Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = Firing)
		void Fire();
protected:
	UTankAimingComponent * TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent * TankMovementComponent = nullptr;

private:	
	virtual void BeginPlay() override;

	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSoeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;
	
	//Local barrel reference
	UTankBarrel * Barrel = nullptr;

	double LastFireTime = 0;
};
