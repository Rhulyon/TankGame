// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
		void Elevate(float RelativeSpeed);
private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesBySecond=10;
	UPROPERTY(EditAnywhere)
		float MaxInclination=45;
	UPROPERTY(EditAnywhere)
		float MinInclination=0;

};
