// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto ElevationChange = FMath::Clamp<float>(RelativeSpeed,-1.0f,1.0f) * MaxDegreesBySecond* GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	SetRelativeRotation(FRotator(
		FMath::Clamp<float>(RawNewElevation,MinInclination,MaxInclination)
		, 0, 0));
}
