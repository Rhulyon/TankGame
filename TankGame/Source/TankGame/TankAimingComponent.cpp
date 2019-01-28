// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * barrelSet)
{
	
	barrel = barrelSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * turretSet)
{
	turret = turretSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector location, float LaunchSpeed)
{
	if (!barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = barrel->GetSocketLocation(FName("ShotPoint"));
	bool bHaveAimSolution= UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		location,
		LaunchSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	//calculate the out launch velocity

	if (bHaveAimSolution) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	//Check if barrel is inside movable angle
	//if so move it towards it a maximum ammount (or to the point if the point is closer than the maximum amount
	//if not move it to the border
	auto BarrrelRotation = barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto Deltarotation = AimAsRotator - BarrrelRotation;
	barrel->Elevate(Deltarotation.Pitch);
	turret->Rotate(Deltarotation.Yaw);
}

