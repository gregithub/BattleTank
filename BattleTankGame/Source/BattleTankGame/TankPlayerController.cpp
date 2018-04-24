// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include"TankAimingComponent.h"
#include"Engine/World.h"
#include"Tank.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) {return;}
	FoundAimingComponent(AimingComponent);
	
}
void ATankPlayerController::SetPawn(APawn* InPawn) {
	Super::SetPawn(InPawn);
	if (InPawn) {
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnDeath);
	}

}
void ATankPlayerController::OnDeath(){
	UE_LOG(LogTemp, Warning, TEXT("esese"));
	StartSpectatingOnly();
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}
void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetPawn()) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation;
	bool bGotHitLocation = GetSightRayHitocation(HitLocation);
	if (bGotHitLocation) {//IS GOIN TO LINE TRACE
		AimingComponent->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitocation(FVector& OutHitLocation) const {

	//Find the crosshair popsition
	int32 ViewportsizeX, ViewportsizeY;
	GetViewportSize(ViewportsizeX, ViewportsizeY);
	auto ScreenLocation = FVector2D(ViewportsizeX*CrossHairLocationX, ViewportsizeY*CrossHairLocationY);
	//De-project screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		return GetLookVectorHitLocation(LookDirection,OutHitLocation);
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector CameraWorldLocation; //to be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection,FVector& HitLocation) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)) {
		HitLocation=HitResult.Location;
		return true;
	}
	return false;
}
//void ATankPlayerController::FoundAimingComponent(UTankAimingComponent *AimCompRef) {}