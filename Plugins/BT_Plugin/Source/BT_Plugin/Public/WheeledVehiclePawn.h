// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "Engine.h"
#include <ParseXML/Public/WayPoint.h>
#include "VehicleAIController.h"
#include "VehicleSpecification.h"
#include "WheeledVehiclePawn.generated.h"

/**
 * 
 */

UCLASS()
class BT_PLUGIN_API AWheeledVehiclePawn : public AWheeledVehicle
{
	GENERATED_BODY()
	
private:
	// Sets default values for this actor's properties
	AWheeledVehiclePawn();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	bool InitializeWheeledVehicle(FVehicleAISpecification VehicleSpec);
	void InitializeBlackBoardValues();




	AVehicleAIController* VehicleController;
	
	UPROPERTY(EditAnywhere)
	FVehicleAISpecification VehicleSpecification;

	void PrintLog(FString Text)
	{
		if (!GEngine) return;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, *Text);
	}
};
