// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;	//Forward declaration
class UTankAimingComponent;
UCLASS()
class BATTLETANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category=Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);
protected:
	UTankAimingComponent * TankAimingComponent = nullptr;

private:	
	virtual void BeginPlay() override;

	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSoeed = 10000;
	
};
