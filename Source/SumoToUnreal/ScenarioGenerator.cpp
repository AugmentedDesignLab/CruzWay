// Fill out your copyright notice in the Description page of Project Settings.


#include "ScenarioGenerator.h"

// Sets default values
AScenarioGenerator::AScenarioGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PrintLog("Inside the SceneGen constructor");
	//PrintLog(VehicleRef);
	//AWheeledVehicleObject* Vehicle = LoadVehicleFromPluginAsset(VehicleList[0].VehicleAsset);

}

// Called when the game starts or when spawned
void AScenarioGenerator::BeginPlay()
{
	Super::BeginPlay();
	
	AWheeledVehicleObject* temp = SpawnVehicle(VehicleList[0]);
	SpawnedVehicleList.Add(temp);
	
	
}

// Called every frame
void AScenarioGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (AWheeledVehicleObject* VehicleObject : SpawnedVehicleList)
	{
		//VehicleObject->UpdateBlackBoard(DeltaTime);
		//VehicleObject->UpdateControlValue();
	}
}

AWheeledVehicleObject* AScenarioGenerator::LoadVehicleFromPluginAsset(FString Path)
{
	AWheeledVehicleObject* VehicleAsset = LoadObjFromPath<AWheeledVehicleObject>(*Path);
	if (VehicleAsset != NULL)
	{
		return VehicleAsset;
	}
	return nullptr;
}

AWheeledVehicleObject* AScenarioGenerator::SpawnVehicle(FVehicleSpecification VehicleSpec)
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

