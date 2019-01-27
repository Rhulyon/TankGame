// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
void ATankAiController::BeginPlay() {
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AiController cannot find a player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}


}

void ATankAiController::Tick(float DeltaSeconds)
{
	ATank * PlayerTank = GetPlayerTank();
	if(PlayerTank){
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}

}


ATank * ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAiController::GetPlayerTank() const
{
	auto tank =GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!tank) {
		UE_LOG(LogTemp, Warning, TEXT("AiController %s was unable to find the player"), *(GetName()));
		return nullptr;
	}
	return  Cast<ATank>(tank);
}
