// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "VehicleSpecification.h"
#include "Engine.h"
#include <ParseXML/Public/WayPoint.h>
#include "BTWheeledVehicle.generated.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)

/**
 * 
 */
UCLASS()
class BT_PLUGIN_API ABTWheeledVehicle : public AWheeledVehicle
{
	GENERATED_BODY()

private:
	ABTWheeledVehicle();
	int VehicleID;

protected:
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere)
	FString BT_Path;

	UPROPERTY(EditAnywhere)
	FDriverSpecificationBT DriverSpecification;

	UPROPERTY(EditAnywhere)
	TArray<AWayPoint*> Route;

	virtual void Tick(float DeltaTime) override;
	virtual FVector GetVelocity() const override;
	
	void SetVehicleID(int ID);
	int GetVehicleID();



};
