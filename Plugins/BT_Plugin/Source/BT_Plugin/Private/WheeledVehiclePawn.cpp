// Fill out your copyright notice in the Description page of Project Settings.


#include "WheeledVehiclePawn.h"
#include "WheeledVehicleMovementComponent.h"

AWheeledVehiclePawn::AWheeledVehiclePawn()
{
	PrimaryActorTick.bCanEverTick = true;
	//PrintLog("Inside vehicle object constructor ");
}

void AWheeledVehiclePawn::BeginPlay()
{
	Super::BeginPlay();
	PrintLog("Inside vehicle pawn beginplay");
	VehicleController = GetController<AVehicleAIController>();
}

void AWheeledVehiclePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//PrintLog("Inside vehicle pawn tick");
	this->GetVehicleMovement()->SetThrottleInput(0.5);
}

bool AWheeledVehiclePawn::InitializeWheeledVehicle(FVehicleAISpecification VehicleSpec)
{
	VehicleSpecification = VehicleSpec;
	return true;
}

void AWheeledVehiclePawn::InitializeBlackBoardValues()
{
}
