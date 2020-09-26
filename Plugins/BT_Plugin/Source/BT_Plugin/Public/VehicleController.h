// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine.h"
#include "WayPoint.h"
#include <Runtime\AIModule\Classes\BehaviorTree\BehaviorTreeComponent.h>
#include <Runtime\AIModule\Classes\BehaviorTree\BlackboardComponent.h>
#include "VehicleController.generated.h"

/**
 * 
 */
UCLASS()
class BT_PLUGIN_API AVehicleController : public AAIController
{
	GENERATED_BODY()
	
public:
	AVehicleController();

protected:
	virtual void BeginPlay() override;

public:
	void Tick(float DeltaTime) override;

	UBlackboardComponent* BlackboardComponent;
	UBehaviorTreeComponent* BehaviorTreeComponent;
	AWayPoint* WayPoint;

	UBehaviorTree* LoadBehaviorTree(FString BehaviorTreePath);
	bool InitializeBlackBoard(UBehaviorTree* BehaviorTree);
	bool SetWayPoint(AWayPoint* WP);
	void StartBehaviorTree(UBehaviorTree* BehaviorTree);
	bool InitializeVehicleController(FString BehaviorTreePath, AWayPoint* WP);


	void PrintLog(FString Text)
	{
		if (!GEngine) return;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, *Text);
	}

	//Function to load object from content folder. Copy path from UE
	template <typename ObjClass>
	static FORCEINLINE ObjClass* LoadObjFromPath(const FName& Path)
	{
		if (Path == NAME_None) return NULL;

		return Cast<ObjClass>(StaticLoadObject(ObjClass::StaticClass(), NULL, *Path.ToString()));

	}
};
