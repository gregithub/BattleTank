// Fill out your copyright notice in the Description page of Project Settings.


#include"Tank.h"
#include"TankAimingComponent.h"
#include"Engine/World.h"
#include"TankBarrel.h"
#include"Projectile.h"




// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("YETI: Constructor C++ called."));
	//No need to protect pointers as added at contstuciton

}
void ATank::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("YETI: BeginPlay C++ called."));
}


void ATank::Fire() {
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded) {
		//Spawn Aa projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSoeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}

// Called to bind functionality to input

void ATank::AimAt(FVector HitLocation) {
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation,LaunchSoeed);
}