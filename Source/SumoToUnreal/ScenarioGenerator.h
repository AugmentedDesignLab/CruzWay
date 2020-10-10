// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WheeledVehicleObject.h"
#include "WayPoint.h"
#include "RoadMesh.h"
#include "PedestrianCharacter.h"
#include "Engine.h"
#include "ScenarioGenerator.generated.h"

USTRUCT()
struct FVehicleSpecification
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AWheeledVehicleObject> VehicleAsset;

	UPROPERTY(EditAnywhere)
	AWayPoint* WayPoint;

	UPROPERTY(EditAnywhere)
	FString BT_Path;
};

USTRUCT()
struct FPedestrianSpecification
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<class APedestrianCharacter> PedestrianAsset;

	UPROPERTY(EditAnywhere)
	ARoadMesh* RoadMesh;
};

UCLASS()
class SUMOTOUNREAL_API AScenarioGenerator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AScenarioGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TArray<FVehicleSpecification> VehicleList;

	UPROPERTY(EditAnywhere)
	TArray<FPedestrianSpecification> PedestrianList;
	
	TArray<AWheeledVehicleObject*> SpawnedVehicleList;
	
	TArray<APedestrianCharacter*> SpawnedPedestrianList;

	AWheeledVehicleObject* LoadVehicleFromPluginAsset(
		FString Path = "BehaviorTree'/BT_Plugin/BT/BehaviorTree.BehaviorTree'");

	AWheeledVehicleObject* SpawnVehicle(FVehicleSpecification VehicleSpec);

	APedestrianCharacter* SpawnPedestrian(FPedestrianSpecification PedestrianSpec);
	
	void PrintLog(FString Text)
	{
		if (!GEngine) return;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, *Text);
	}

	//Function to load object from content folder. Copy path from UE
	template <typename ObjClass>
	static FORCEINLINE ObjClass* LoadObjFromPath(const FName& Path)
	{
		if (Path == NAME_None) return nullptr;

		return Cast<ObjClass>(StaticLoadObject(ObjClass::StaticClass(), NULL, *Path.ToString()));
	}
};
