// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"
//#include"Runtime/Engine/Classes/GameFramework/Actor.h"
UTankTracks::UTankTracks() {
	PrimaryComponentTick.bCanEverTick = false;
}
void UTankTracks::BeginPlay() {
	OnComponentHit.AddDynamic(this, &UTankTracks::OnHit);

}

void UTankTracks::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit) {
	//Drive the tracks
	DriveTrack();
	ApplySidwaysForce();
	CurrentThrottle = 0;
}

void UTankTracks::ApplySidwaysForce()
{
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	//calculate and apply sideways for(F=m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;//Divided bcs of 2 tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTracks::DriveTrack() {

	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UTankTracks::SetThrottle(float Throttle) {
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
}

