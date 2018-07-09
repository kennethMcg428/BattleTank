// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	auto Speed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = Speed * MaxDegreesRotationPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}
