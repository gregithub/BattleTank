// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	GetControlledTank();
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	
}
void ATankPlayerController::AimTowardsCrosshair() {
	//if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitocation(HitLocation)) {//IS GOIN TO LINE TRACE
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		//TODO tell controlled tank ot aim at this point
	}
}

ATank* ATankPlayerController::GetControlledTank() const {
	auto ControlledTank = GetPawn();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
		return nullptr;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT
		("PlayerController possesing %s"), *ControlledTank->GetName());
	}
	return Cast<ATank>(ControlledTank);
}

bool ATankPlayerController::GetSightRayHitocation(FVector& OutHitLocation) const {

	//Find the crosshair popsition
	int32 ViewportsizeX, ViewportsizeY;
	GetViewportSize(ViewportsizeX, ViewportsizeY);
	auto ScreenLocation = FVector2D(ViewportsizeX*CrossHairLocationX, ViewportsizeY*CrossHairLocationY);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"),*ScreenLocation.ToString());
	//De-project screen position of the crosshair to a world direction
	//Line trace along that look directionand see what we hit(up to max range)

	return true;
}