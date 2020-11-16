// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Engine.h"
#include <ParseXML/Public/WayPoint.h>
#include "VehicleController.h"
#include "TaskLaneFollow.generated.h"

/**
 *
 */
UCLASS()
class BT_PLUGIN_API UTaskLaneFollow : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	float UpdatedSteeringValue(AVehicleController* VehicleController);
	float UpdatedThrottleValue(AVehicleController* VehicleController);

	AWayPoint* GetRandomWayPointFromConnectedSpline(AWayPoint* GivenWayPoint);
	void ChangeWayPointUpdateBlackBoard(AWayPoint* WayPoint, AVehicleController* VehicleController);
	
	void PrintLog(FString Text)
	{
		if (!GEngine) return;
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, *Text);
	}
};
