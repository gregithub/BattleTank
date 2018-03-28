// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include"TankBarrel.h"
#include "TankTurret.h"
#include"Kismet/GameplayStatics.h"
#include"Engine/StaticMesh.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UTankAimingComponent::SetBarrellRefference(UTankBarrel * BarrelToSet) {
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}
void UTankAimingComponent::SetTurretRefference(UTankTurret * TurretToSet) {
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation,float LaunchSoeed) {
	if (!Barrel) { return; }

	FVector OutLaunchVElocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVElocity,
		StartLocation,
		HitLocation,
		LaunchSoeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if(bHaveAimSolution){
		auto AimDirection = OutLaunchVElocity.GetSafeNormal();
		MoveBarrelAndTurretTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelAndTurretTowards(FVector AimDirection) {
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}