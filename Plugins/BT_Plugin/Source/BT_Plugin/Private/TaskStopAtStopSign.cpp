// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskStopAtStopSign.h"
#include "VehicleController.h"
#include "Kismet/KismetMathLibrary.h"

#define DISTANCE_THRESHOLD 500
#define BRAKE_START_DISTANCE 2000
#define BRAKE_INC_RATE 0.01
#define THROTTLE_DEC_RATE 0.001
#define THROTTLE_UP_LIMIT 0.7
#define THROTTLE_DOWN_LIMIT 0.3

EBTNodeResult::Type UTaskStopAtStopSign::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBehaviorTreeComponent& MyComp = OwnerComp;
	AVehicleController* MyController = &MyComp ? Cast<AVehicleController>(MyComp.GetOwner()) : NULL;
	
	FVector VehicleLocation = MyController->BlackboardComponent->GetValueAsVector("VehicleWorldLocation");
	FVector VehicleLocationOnSpline = MyController->WayPoint->SplineComponent->FindLocationClosestToWorldLocation(VehicleLocation, ESplineCoordinateSpace::World);

	FVector StopSignLocation = MyController->WayPoint->StopSignLocation;
	FVector StopLocation;
	if (StopSignLocation == FVector::ZeroVector)
	{
		return EBTNodeResult::Failed;
	}
	else
	{
		StopLocation = MyController->WayPoint->SplineComponent->FindLocationClosestToWorldLocation(MyController->WayPoint->StopSignLocation, ESplineCoordinateSpace::World);
		UKismetSystemLibrary::DrawDebugArrow(this, StopSignLocation, StopLocation * 1, 100, FColor::Green, 0.1, 5);
		//PrintLog("Stop sign location " + StopSignLocation.ToString());
		//PrintLog("Stop location " + StopLocation.ToString());
		FVector DistanceVector_Vehicle_StopLocation = StopLocation - VehicleLocationOnSpline;
		if (DistanceVector_Vehicle_StopLocation.Size() > BRAKE_START_DISTANCE)
		{
			return EBTNodeResult::Failed;
		}
		else if (DistanceVector_Vehicle_StopLocation.Size() < BRAKE_START_DISTANCE && DistanceVector_Vehicle_StopLocation.Size() > DISTANCE_THRESHOLD)
		{
			MyController->BlackboardComponent->SetValueAsInt("VelocityStatus", -1);
			return EBTNodeResult::Failed;
		}
		else
		{
			//float BrakeValue = MyController->BlackboardComponent->GetValueAsFloat("BrakeValue");
			float ThrottleValue = MyController->BlackboardComponent->GetValueAsFloat("ThrottleValue");
			MyController->BlackboardComponent->SetValueAsFloat("BrakeValue", ThrottleValue);
			MyController->BlackboardComponent->SetValueAsFloat("ThrottleValue", 0);
			
			return EBTNodeResult::Succeeded;
		}
	}
}

