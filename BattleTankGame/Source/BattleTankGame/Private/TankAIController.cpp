// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include"Engine/World.h"
#include"TankAimingComponent.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto ControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadius);
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	
	//TODO fix firing
	AimingComponent->Fire();
}
//TODO delete? this
//void ATankAIController::FoundAimingComponent(UTankAimingComponent *AimCompRef) {}
	



