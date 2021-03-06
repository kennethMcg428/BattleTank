// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Classes/Components/StaticMeshComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// No need to protect pointers at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	GetAimingComponent()->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	GetAimingComponent()->SetTurretReference(TurretToSet);
}
// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	GetAimingComponent()->AimAt(HitLocation , LaunchSpeed);
}

UTankAimingComponent * ATank::GetAimingComponent()
{
	return TankAimingComponent;
}
