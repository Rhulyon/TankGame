// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; 
class UTankAimingComponent;
class UTankTurret;
class AProjectile;
/*
*
*/
UCLASS()
class TANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	UFUNCTION(BlueprintCallable,Category=Setup)
	void SetBarrelReference(UTankBarrel * BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret * TurretToSet);

	UFUNCTION(BlueprintCallable,Category = Fire)
	void Fire();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void AimAt(FVector hitLocation);

protected:
	UTankAimingComponent * tankAimingComponent = nullptr;

private:
	UTankBarrel * barrel;
	UPROPERTY(EditDefaultsOnly,Category= Firing)
	float LaunchSpeed = 10000;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> projectile;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	double ReloadTimeInSeconds = 3;

	double NextFireTime;
};
