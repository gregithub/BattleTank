// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank * GetControlledTank() const;
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float Time) override;

	void AimTowardsCrosshair();

	bool GetSightRayHitocation(FVector &) const;

	UPROPERTY(EditAnywhere)
		float CrossHairLocationX = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairLocationY = 0.33333;

	bool GetLookDirection(FVector2D,FVector&) const;

	bool GetLookVectorHitLocation(FVector,FVector&) const;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
public:
	
};
