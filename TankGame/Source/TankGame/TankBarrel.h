// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent),hideCategories="Collision")
class TANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
		void Elevate(float RelativeSpeed);
private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesBySecond=5;
	UPROPERTY(EditAnywhere)
		float MaxInclination=40;
	UPROPERTY(EditAnywhere)
		float MinInclination=0;
};
