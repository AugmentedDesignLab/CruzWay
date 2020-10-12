// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleAIController.h"


AVehicleAIController::AVehicleAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	//PrintLog("Inside AVehicleAIController constructor");

	//Creating subobject
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>("VehicleBehaviorTree");
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>("VehicleBlackBoard");
}
void AVehicleAIController::BeginPlay()
{
}

void AVehicleAIController::Tick(float DeltaTime)
{
}
