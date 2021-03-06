// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"//			the order of these three includes 
#include "GameFramework/Pawn.h"//	is very important for
#include "Tank.generated.h"//		the structure of Unreal Engine

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	UTankAimingComponent *  GetAimingComponent();
	void AimAt(FVector HitLocation);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:
	UTankAimingComponent * TankAimingComponent = nullptr;

private:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000;

};
