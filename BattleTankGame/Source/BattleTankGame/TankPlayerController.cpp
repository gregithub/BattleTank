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
	if (!GetControlledTank()) { return; }
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
