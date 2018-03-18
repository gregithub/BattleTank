// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	
	GetControlledTank();
	GetPlayerTank();
}

ATank* ATankAIController::GetControlledTank() const {
	auto ControlledTank = GetPawn();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI_TankController not possesing a tank"));
		return nullptr;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI_TankController possesing a tank: %s"), *ControlledTank->GetName());
	}
	return Cast<ATank>(ControlledTank);

}
ATank * ATankAIController::GetPlayerTank() const {
	auto PlayerTankController = GetWorld()->GetFirstPlayerController();
	if (!PlayerTankController) {
		UE_LOG(LogTemp, Warning, TEXT("AI_TankController coulnd't find PlayerTank"));
		return nullptr;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI_TankController found player tank: %s"),
			*PlayerTankController->GetName());
	}
	return Cast<ATank>(PlayerTankController);
}





