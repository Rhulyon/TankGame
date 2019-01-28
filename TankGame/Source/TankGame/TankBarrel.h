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
	UPROPERTY(EditDefaultsOnly)
		float MaxDegreesBySecond=10;
	UPROPERTY(EditDefaultsOnly)
		float MaxInclination=45;
	UPROPERTY(EditDefaultsOnly)
		float MinInclination=0;

};
