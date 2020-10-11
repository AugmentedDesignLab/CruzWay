// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WheeledVehicleObject.h" 
#include "WayPoint.h"
#include "Engine.h"
#include "RepeatedVehicleSpawner.generated.h"


USTRUCT()
struct FVehicleSpecificationR
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AWheeledVehicleObject> VehicleAsset;

	UPROPERTY(EditAnywhere)
	AWayPoint* WayPoint;

	UPROPERTY(EditAnywhere)
	FString BT_Path;
};

UCLASS()
class SUMOTOUNREAL_API ARepeatedVehicleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARepeatedVehicleSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TArray<FVehicleSpecificationR> VehicleList;

	TArray<AWheeledVehicleObject*> SpawnedVehicleList;

	UPROPERTY(EditAnywhere)
	int NumberOfVehicles = 0;

	float time = 0.0f;

	AWheeledVehicleObject* SpawnVehicle(FVehicleSpecificationR VehicleSpec);


	void PrintLog(FString Text)
	{
		if (!GEngine) return;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, *Text);
	}

};
