// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleController.h"
#include <Runtime\AIModule\Classes\BehaviorTree\BehaviorTree.h>

AVehicleController::AVehicleController()
{
	PrimaryActorTick.bCanEverTick = true;
	PrintLog("Inside controller constructor");

	//Creating subobject 
	//BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>("VehicleBehaviorTree");
	//BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>("VehicleBlackBoard");
}

void AVehicleController::BeginPlay()
{
	Super::BeginPlay();
	PrintLog("Inside controller beginplay");
}

void AVehicleController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//PrintLog("Inside  tick ");
	
}

UBehaviorTree* AVehicleController::LoadBehaviorTree(FString BehaviorTreePath)
{
	UBehaviorTree* BehaviorTreeAsset = LoadObjFromPath<UBehaviorTree>(FName(*BehaviorTreePath));
	if (BehaviorTreeAsset != NULL)
	{ 
		PrintLog(" asset name ");
		return BehaviorTreeAsset;
	}
	else return nullptr;
}

bool AVehicleController::InitializeBlackBoard(UBehaviorTree* BehaviorTree)
{
	if (BehaviorTree != NULL)
	{
		BlackboardComponent->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
		BlackboardComponent->SetValueAsFloat("BrakeValue", 0.0);
		BlackboardComponent->SetValueAsFloat("SteerValue", 0.0);
		BlackboardComponent->SetValueAsFloat("ThrottleValue", 0.5);
		//BlackboardComponent->SetValueAsFloat("ThreshWaypointDeviation", 10.0);
		//BlackboardComponent->SetValueAsFloat("ThreshStopAtStopSignDistance", 800);
		PrintLog("Behavior tree and blackboard init");
		return true;
	}
	return false;
}

bool AVehicleController::SetWayPoint(AWayPoint* WP)
{
	PrintLog("Setting Waypoint ");
	if (WP != NULL)
	{
		WayPoint = WP;
		if (WP->StopSignLocation != FVector::ZeroVector)
		{
			PrintLog("Not zero vector" + WP->StopSignLocation.ToString());
			if (BlackboardComponent == NULL)
			{
				PrintLog("Null Blackboard");
			}
			else
			{
				PrintLog("BlackBoard ");
				BlackboardComponent->SetValueAsBool("IsStopSignAhead", true);
			}
			
		}
		else
		{
			BlackboardComponent->SetValueAsBool("IsStopSignAhead", false);
		}
		return true;
	}
	return false;
}

void AVehicleController::StartBehaviorTree(UBehaviorTree* BehaviorTree)
{
	BehaviorTreeComponent->StartTree(*BehaviorTree);
}



bool AVehicleController::InitializeVehicleController(FString BehaviorTreePath, AWayPoint* WP)
{
	UBehaviorTree* BehaviorTree = LoadBehaviorTree(BehaviorTreePath);
	bool IsSetWayPoint = SetWayPoint(WP);
	PrintLog("Initialize vehicle controller");
	if (BehaviorTree != NULL && IsSetWayPoint)
	{
		InitializeBlackBoard(BehaviorTree);
		StartBehaviorTree(BehaviorTree);
		return true;
	}
	return false;
}









