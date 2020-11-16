// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskStartFromStopSign.h"
#include "BT_Controller/VehicleController.h"


EBTNodeResult::Type UTaskStartFromStopSign::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBehaviorTreeComponent& MyComp = OwnerComp;
	AVehicleController* VehicleController = &MyComp ? Cast<AVehicleController>(MyComp.GetOwner()) : NULL;

	PrintLog("Task start from stop sign ");

	VehicleController->BlackboardComponent->SetValueAsInt("VelocityStatus", 1);
	VehicleController->BlackboardComponent->SetValueAsBool("IsStopSignAhead", false);
	VehicleController->BlackboardComponent->SetValueAsFloat("BrakeValue", 0.0);
	VehicleController->BlackboardComponent->SetValueAsFloat("ThrottleValue", 0.5);
	return EBTNodeResult::Succeeded;
}
