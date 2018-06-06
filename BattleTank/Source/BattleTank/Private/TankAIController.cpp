// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

void ATankAIController::BeginPlay()
{
	bDoesTick = false;
	bDidLog = false;
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();
	FString TankName = ControlledTank->GetName();
	FString PlayerName = PlayerTank->GetName();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp,Error,TEXT("TankAIController is not Possesing Tank"))
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("%s is possessing %s"),*GetName(), *TankName)
	}
	if (!PlayerTank)
	{
		UE_LOG(LogTemp,Error,TEXT("%s cannot find PlayerControlledTank"), *GetName())
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("%s successfully found PlayerControlledTank : %s"), *GetName(), *PlayerName)
	}

}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	if (!Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn())) { return nullptr; }
	else {return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());}
}