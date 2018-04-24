// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include"GameFramework/Pawn.h"
#include "CoreMinimal.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);


UCLASS()
class BATTLETANKGAME_API ATank : public APawn
{
	GENERATED_BODY()


public:
	//called by the enging when actor damage is dealt
	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser
	) override;

	FTankDelegate OnDeath;

	UFUNCTION(BlueprintPure,Category="Health")
		float GetHealthPercent() const;
private:
	ATank();
	 
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,Category="Setup")
		int32 StartingHealth = 100;
		
	UPROPERTY(VisibleAnywhere, Category = "Health")
		int32 CurrentHealth;
};
