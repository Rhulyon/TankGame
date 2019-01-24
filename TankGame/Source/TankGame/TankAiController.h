// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"
/**
 * 
 */
UCLASS()
class TANKGAME_API ATankAiController : public AAIController
{
	GENERATED_BODY()
private:


	ATank * GetControlledTank() const;

	ATank * GetPlayerTank() const;

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
};
