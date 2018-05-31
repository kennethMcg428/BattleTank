// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
}