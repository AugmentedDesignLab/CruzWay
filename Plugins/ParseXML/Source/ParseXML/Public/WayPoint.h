// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Classes/Components/SplineComponent.h"
#include "GameFramework/Actor.h"
#include "WayPoint.generated.h"

UCLASS()
class PARSEXML_API AWayPoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWayPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		USplineComponent* SplineComponent;
	UPROPERTY(EditAnywhere)
		FString splineID;
	UPROPERTY(EditAnywhere)
		TArray<AWayPoint*> ConnectedSpline;
	UPROPERTY(EditAnywhere)
		TArray<AWayPoint*> CutSpline;
	UPROPERTY(EditAnywhere)
		TArray<APawn*> VehiclePawnList;

	UPROPERTY(EditAnywhere)
		FString turnType;
	FVector directionOfSpline;

	//UPROPERTY(EditAnywhere)
	//TMap<FString, AWayPoint*> ConnectedSplineMap;
	UPROPERTY(EditAnywhere)
		float TotalDistance = 0.0;
	UPROPERTY(EditAnywhere)
		int SpeedLimit = 0;
	UPROPERTY(EditAnywhere)
		bool isStopSignConnected = false;

	//New Code
	UPROPERTY(EditAnywhere)
<<<<<<< HEAD
		FVector StopSignLocation;
=======
	bool isStopSignConnected = false;

	//New Code
	UPROPERTY(EditAnywhere)
	FVector StopSignLocation;
>>>>>>> cf15187e4f22eb9283c2ec1c5dc1c0fd3121a4fd

	int32 twoTimesTotalConnectedSplines = 0; //multiple of 2
	void calculateCurrentSplineTurnTypes();
	FString calculateDecalSelection();
	float GetDistanceAlongSpline(FVector WorldLocation);
};


