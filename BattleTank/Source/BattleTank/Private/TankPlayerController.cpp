// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#define OUT

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	FString TankName = ControlledTank->GetName();
	
	//UE_LOG(LogTemp, Warning, TEXT("PlayerControler Begin Play"));
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No Tank is being Controlled"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is possessing %s"),*GetName(), *TankName);
	}

}


ATank * ATankPlayerController::GetControlledTank()const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // OUT perameter
	if (GetSightRayHitLocation(HitLocation))//will cast ray
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
			// if hit landscape
				// TODO tell tank to aim at this location

	}
	
}
// get world location from line trace through crosshair - true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector OUT&HitLocation)const
{ 
	int32 VeiwportSizeX, VeiwportSizeY;
	GetViewportSize(VeiwportSizeX, VeiwportSizeY);

	FVector2D ScreenLocation(CrosshairXLocation*VeiwportSizeX,
		CrosshairYLocation*VeiwportSizeY);

	//DeprojectScreenPositionToWorld(CrosshairXLocation, CrosshairYLocation, HitLocation);

	//find crosshair position
	// "deproject" screen position of crosshair into world direction
	//line trace along look direction, see what is hit(up to max range)
	return true;
}