// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Engine/World.h"
/*ATankPlayerController::ATankPlayerController() {
	
}*/


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayController not possesing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"),*(ControlledTank->GetName()));
	}
}


void ATankPlayerController::Tick(float Deltatime) {
	Super::Tick(Deltatime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		GetControlledTank()->AimAt(HitLocation);

	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const{
	//find the crosshair position
	int32 ViewportX, ViewportY;
	GetViewportSize(ViewportX, ViewportY);
	FVector2D ScreenLocation(ViewportX *  CrossHairXLocation, ViewportY * CrossHairYLocation);
	
	//De-project the screen position of the crosshair to a world direction
	FVector CameraWorldLocation;
	FVector WorldDirection;
	if(DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection)) {
		//UE_LOG(LogTemp, Warning, TEXT("Camera: %s ,  Camera : %s"), *(CameraWorldLocation.ToString()),*(PlayerCameraManager->GetCameraLocation().ToString()));
		auto StartLocation = CameraWorldLocation;
		auto EndLocation = StartLocation+WorldDirection*RAYCAST_LENGHT;
		FHitResult HitResult;

		if (GetWorld()->LineTraceSingleByChannel(
			HitResult, StartLocation, EndLocation, ECC_Visibility
		))
			HitLocation = HitResult.Location;
			return true;
		//auto StartLocation =  Player
	}
	//line-trace along that look direction and see what we hit (up to max range)
	HitLocation = FVector::ZeroVector;
	return false;
}