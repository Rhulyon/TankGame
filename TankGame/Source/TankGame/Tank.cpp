// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	barrel = BarrelToSet;
	tankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	tankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Pew Pew"));
	if (barrel && (FPlatformTime::Seconds()) > NextFireTime) {
		FActorSpawnParameters actorSpawnParameters;
		/*actorSpawnParameters.Template =Cast<AActor> (projectile);
		actorSpawnParameters.Name = FName("Shot");*/
		auto shot = GetWorld()->SpawnActor<AProjectile>(projectile, barrel->GetSocketTransform(FName("ShotPoint")));
		shot->LaunchProjectile(LaunchSpeed);
		NextFireTime = FPlatformTime::Seconds() + ReloadTimeInSeconds;
	}
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{

	tankAimingComponent->AimAt(HitLocation,LaunchSpeed);
}

