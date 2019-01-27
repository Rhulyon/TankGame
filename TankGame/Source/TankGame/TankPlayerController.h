// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#define RAYCAST_LENGHT 1000000.0f;
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ATank* GetControlledTank() const;
	//Move tank barrell towards the point where it is going to land the shot
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector & HitLocation) const;
public:

	//ATankPlayerController();

	void BeginPlay() override;
	void Tick(float ) override;

private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation=0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation=0.3333f;

};
