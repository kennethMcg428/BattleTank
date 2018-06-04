// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank * ControlledTank = nullptr;
	ATank * GetControlledTank()const;
	virtual void Tick(float DeltaTime)override;
	virtual void BeginPlay() override;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector &HitLocation)const;
};
