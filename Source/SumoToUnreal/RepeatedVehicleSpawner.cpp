// Fill out your copyright notice in the Description page of Project Settings.


#include "RepeatedVehicleSpawner.h"

// Sets default values
ARepeatedVehicleSpawner::ARepeatedVehicleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARepeatedVehicleSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (FVehicleSpecificationR Vehicle : VehicleList)
	{
		AWheeledVehicleObject* temp = SpawnVehicle(Vehicle);
		SpawnedVehicleList.Add(temp);
	}
}

// Called every frame
void ARepeatedVehicleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	time = time + DeltaTime;

	if (time > 7.0)
	{
		time = 0.0f;
		for (FVehicleSpecificationR Vehicle : VehicleList)
		{
			AWheeledVehicleObject* temp = SpawnVehicle(Vehicle);
			SpawnedVehicleList.Add(temp);
		}
	}
}

AWheeledVehicleObject* ARepeatedVehicleSpawner::SpawnVehicle(FVehicleSpecificationR VehicleSpec)
{
	UWorld* World = GetWorld();
	FVector LocationVector = VehicleSpec.WayPoint->GetActorLocation();
	PrintLog(LocationVector.ToString());
	FVector SpawnPoint = FVector(LocationVector.X, LocationVector.Y, 10.0f);
	FActorSpawnParameters SpawnParam;
	SpawnParam.Owner = this;
	FRotator Rotator = FRotator(0, 0, 0);
	AWheeledVehicleObject* temp = World->SpawnActor<AWheeledVehicleObject>(VehicleSpec.VehicleAsset, SpawnPoint, Rotator, SpawnParam);
	temp->InitializeWheeledVehicle(VehicleSpec.BT_Path, VehicleSpec.WayPoint);
	temp->InitializeBlackBoardValues();
	return temp;
}

