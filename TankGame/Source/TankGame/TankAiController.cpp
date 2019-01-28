// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
void ATankAiController::BeginPlay() {
	Super::BeginPlay();




}

void ATankAiController::Tick(float DeltaSeconds)
{

	ATank * PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto controlledTank = Cast<ATank>(GetPawn());
	if(PlayerTank){
		controlledTank->AimAt(PlayerTank->GetActorLocation());
		
		controlledTank->Fire(); //TODO limit FiringRate
	}

}




