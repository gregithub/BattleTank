// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include"Engine/World.h"
#include"Tank.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	
	GetControlledTank();
	GetPlayerTank();
}
ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());

}
ATank * ATankAIController::GetPlayerTank() const {
	auto PlayerTankController = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTankController) {
		UE_LOG(LogTemp, Warning, TEXT("AI_TankController coulnd't find PlayerTank"));
		return nullptr;
	}
	return Cast<ATank>(PlayerTankController);
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
	
}



