// Fill out your copyright notice in the Description page of Project Settings.



#include "TaskLaneFollow.h"
#include "VehicleController.h"
#include "WheeledVehicleMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

#define LOOK_AHEAD 1.0
#define SPLINE_CHANGE_THRESHOLD 500
#define THROTTLE_INC_RATE 0.0001
#define THROTTLE_DEC_RATE 0.001
#define THROTTLE_UP_LIMIT 0.7
#define THROTTLE_DOWN_LIMIT 0.3
#define ANGLE_WEIGHT 1.0

EBTNodeResult::Type UTaskLaneFollow::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBehaviorTreeComponent& MyComp = OwnerComp;
	AVehicleController* MyController = &MyComp ? Cast<AVehicleController>(MyComp.GetOwner()) : NULL;
	UWheeledVehicleMovementComponent* VehicleMovementComponent = Cast<UWheeledVehicleMovementComponent>(MyController->BlackboardComponent->GetValueAsObject("WheeledVehicleMovementComponent"));

	float NewSteeringValue = UpdatedSteeringValue(MyController);
	float NewThrottleValue = UpdatedThrottleValue(MyController);
	MyController->BlackboardComponent->SetValueAsFloat("SteerValue", NewSteeringValue);
	MyController->BlackboardComponent->SetValueAsFloat("ThrottleValue", NewThrottleValue);
	//PrintLog("Forward speed  " + FString::SanitizeFloat(VehicleMovementComponent->GetForwardSpeed()));
	return EBTNodeResult::Succeeded;
}


float UTaskLaneFollow::UpdatedSteeringValue(AVehicleController* VehicleController)
{
	PrintLog("Steering Update");
	float SteerValue = 0.0;
	AWayPoint* WayPoint = VehicleController->WayPoint;
	FVector VehicleLocation = VehicleController->BlackboardComponent->GetValueAsVector("VehicleWorldLocation");
	float FrameDelta = VehicleController->BlackboardComponent->GetValueAsFloat("TimeDelta");
	float DistanceAlongWayPoint = WayPoint->GetDistanceAlongSpline(VehicleLocation);
	//PrintLog("Distance along spline " + FString::SanitizeFloat(DistanceAlongWayPoint) + " TotalDistance " + FString::SanitizeFloat(WayPoint->TotalDistance));

	FVector VehicleVelocity = VehicleController->BlackboardComponent->GetValueAsVector("VehicleVelocity");
	//FVector VehicleNextLocation = VehicleLocation + VehicleVelocity * LOOK_AHEAD;

	if ((WayPoint->TotalDistance - DistanceAlongWayPoint) < SPLINE_CHANGE_THRESHOLD)
	{
		PrintLog("Changing Spline");
		AWayPoint* ConnectedWayPoint = WayPoint->ConnectedSpline[0];
		VehicleController->SetWayPoint(ConnectedWayPoint);
	}

	FVector NearestSplinePoint = WayPoint->SplineComponent->FindLocationClosestToWorldLocation(VehicleLocation, ESplineCoordinateSpace::World);
	FVector NextSplinePoint = WayPoint->SplineComponent->GetLocationAtDistanceAlongSpline(DistanceAlongWayPoint + VehicleVelocity.Size() * LOOK_AHEAD, ESplineCoordinateSpace::World);

	FVector VehicleFrontVector = VehicleVelocity.GetSafeNormal();
	FVector DirectionVectorNextSplinePoint = NextSplinePoint - VehicleLocation;

	UKismetSystemLibrary::DrawDebugArrow(this, VehicleLocation, VehicleLocation + VehicleFrontVector * 1000, 100, FColor::Red, 0.1, 5);
	UKismetSystemLibrary::DrawDebugArrow(this, VehicleLocation, VehicleLocation + DirectionVectorNextSplinePoint * 1, 100, FColor::Blue, 0.1, 5);

	FVector CrossProduct = FVector::CrossProduct(VehicleFrontVector.GetSafeNormal(), DirectionVectorNextSplinePoint.GetSafeNormal());
	float DotProduct = FVector::DotProduct(VehicleFrontVector.GetSafeNormal(), DirectionVectorNextSplinePoint.GetSafeNormal());
	float InvCos = acosf(DotProduct);
	float Rad_Deg = FMath::RadiansToDegrees(InvCos);
	//PrintLog("Dot Product " + FString::SanitizeFloat(DotProduct) + " InvCos " + FString::SanitizeFloat(InvCos) + " Rad_Deg " + FString::SanitizeFloat(Rad_Deg));

	if (CrossProduct.Z >= 0)
	{
		SteerValue = UKismetMathLibrary::MapRangeClamped(Rad_Deg, 0, 90, 0, 1);
	}
	else
	{
		SteerValue = UKismetMathLibrary::MapRangeClamped(Rad_Deg, 0, 90, 0, -1);
	}

	return SteerValue;
}

float UTaskLaneFollow::UpdatedThrottleValue(AVehicleController* VehicleController)
{
	float ThrottleValue = VehicleController->BlackboardComponent->GetValueAsFloat("ThrottleValue");
	float SteerValue = VehicleController->BlackboardComponent->GetValueAsFloat("SteerValue");
	int VelocityStatus = VehicleController->BlackboardComponent->GetValueAsInt("VelocityStatus");
	float DesiredVelocity = VehicleController->BlackboardComponent->GetValueAsFloat("DesiredVelocity");
	AWayPoint* WayPoint = VehicleController->WayPoint;
	float AngleMagnitude = FMath::Abs(SteerValue);

	FVector VehicleVelocity = VehicleController->BlackboardComponent->GetValueAsVector("VehicleVelocity");

	if (((VehicleVelocity.Size() * 36 / 1000) > DesiredVelocity) || VelocityStatus == -1)
	{
		if (ThrottleValue > THROTTLE_DOWN_LIMIT)
		{
			ThrottleValue = ThrottleValue - THROTTLE_DEC_RATE;
		}

	}
	else if (VelocityStatus == 1)
	{
		if (ThrottleValue < THROTTLE_UP_LIMIT)
		{
			ThrottleValue = ThrottleValue + THROTTLE_INC_RATE;
		}

	}
	return ThrottleValue;
}
