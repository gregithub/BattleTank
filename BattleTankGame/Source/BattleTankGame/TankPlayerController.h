// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	
	virtual void BeginPlay() override;
	
	virtual void Tick(float Time) override;

	virtual void SetPawn(APawn* InPawn) override;

	void AimTowardsCrosshair();

	bool GetSightRayHitocation(FVector &) const;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairLocationX = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float CrossHairLocationY = 0.33333;

	bool GetLookDirection(FVector2D,FVector&) const;
	bool GetLookVectorHitLocation(FVector,FVector&) const;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;

	UFUNCTION()
		void OnDeath();

	UTankAimingComponent *AimingComponent = nullptr;
public:

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent *AimCompRef);
};
