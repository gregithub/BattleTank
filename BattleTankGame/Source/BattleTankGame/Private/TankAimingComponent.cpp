// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include"TankBarrel.h"
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
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation,float LaunchSoeed) {
	if (!Barrel) { return; }
	FVector OutLaunchVElocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculate the OutLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(
			this,
			OutLaunchVElocity,
			StartLocation,
			HitLocation,
			LaunchSoeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace)
		) {
		auto AimDirection = OutLaunchVElocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *DeltaRotator.ToString());
	
	Barrel->Elevate(5);


}