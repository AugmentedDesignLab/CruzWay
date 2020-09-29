// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include <ParseXML/Public/WayPoint.h>
#include "VehicleController.h"
#include "WheeledVehicle.h"
#include "WheeledVehicleObject.generated.h"

/**
 * 
 */
UCLASS()
class BT_PLUGIN_API AWheeledVehicleObject : public AWheeledVehicle
{
	GENERATED_BODY()

private:
	// Sets default values for this actor's properties
	AWheeledVehicleObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:

	virtual void Tick(float DeltaTime) override;



	AVehicleController* VehicleController;
	FVector VehicleVelocity;

	UPROPERTY(EditAnywhere)
	AWayPoint* WayPoint;

	UPROPERTY(EditAnywhere)
	FString BehaviorTreePath;

	bool SelfDestroy();

	bool InitializeWheeledVehicle(FString BehaviorTreePath, AWayPoint* WayPoint);

	void ApplyControlValue(float Throttle, float Steering, float Brake);

	void InitializeBlackBoardValues();

	void UpdateControlValue();

	void UpdateBlackBoard(float Delta);

	void PrintLog(FString Text)
	{
		if (!GEngine) return;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, *Text);
	}
};
