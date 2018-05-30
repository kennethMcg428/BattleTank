// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	FString TankName = ControlledTank->GetName();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp,Error,TEXT("TankAIController is not Possesing Tank"))
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("TankAIController is possessing %s"), *TankName)
	}

}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

