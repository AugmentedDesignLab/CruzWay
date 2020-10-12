// Fill out your copyright notice in the Description page of Project Settings.


#include "WheeledVehiclePawn.h"

AWheeledVehiclePawn::AWheeledVehiclePawn()
{
	PrimaryActorTick.bCanEverTick = true;
	//PrintLog("Inside vehicle object constructor ");
}

void AWheeledVehiclePawn::BeginPlay()
{
}

void AWheeledVehiclePawn::Tick(float DeltaTime)
{
}

bool AWheeledVehiclePawn::InitializeWheeledVehicle(FString BehaviorTreePath, AWayPoint* WayPoint)
{
	return false;
}

void AWheeledVehiclePawn::InitializeBlackBoardValues()
{
}
