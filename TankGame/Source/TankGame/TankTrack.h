// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to set maximum drive force, and apply forces to the tank
 */
UCLASS(ClassGroup=( Custom) ,Meta=(BlueprintSpawnableComponent))
class TANKGAME_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Sets a throttle betwenn -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float throttle);
};
