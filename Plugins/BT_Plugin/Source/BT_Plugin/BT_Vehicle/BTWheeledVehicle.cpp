// Fill out your copyright notice in the Description page of Project Settings.

/*
	class inherited wheeled vehicle
*/
#include "BTWheeledVehicle.h"

#include "BT_Intelligent_Driver_Model/BT_IDM.h"

ABTWheeledVehicle::ABTWheeledVehicle()
{
	PrimaryActorTick.bCanEverTick = true;
	BT_IDM testIDM = BT_IDM();
	testIDM.InitIDM(6, 9, 8, 10, 98, 8);
	print(testIDM.IDM_value_string());
	
}

void ABTWheeledVehicle::BeginPlay()
{
	Super::BeginPlay();

}

FVector ABTWheeledVehicle:: GetVelocity() const
{
	return Super::GetVelocity();
}

void ABTWheeledVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
