// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elavate(float DegreesPerSecond);
	
private:

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDgreesElevation = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegreesElevation = 0;
};