// Fill out your copyright notice in the Description page of Project Settings.


#include "WheeledVehicleObject.h"
#include "GameFramework/Pawn.h"
#include "WheeledVehicleMovementComponent.h"



//runs first Tick when simulate
AWheeledVehicleObject::AWheeledVehicleObject()
{
	PrimaryActorTick.bCanEverTick = true;
	//PrintLog("Inside vehicle object constructor ");
}

void AWheeledVehicleObject::BeginPlay()
{
	Super::BeginPlay();
	PrintLog("Inside vehicle object beginplay");
	VehicleController = GetController<AVehicleController>();
	//InitializeWheeledVehicle(BehaviorTreePath, WayPoint);
	//InitializeBlackBoardValues();
}

void AWheeledVehicleObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//PrintLog("Inside vehicle object tick");

	UpdateBlackBoard(DeltaTime);
	UpdateControlValue();
}

void AWheeledVehicleObject::UpdateControlValue()
{
	float Throttle = VehicleController->BlackboardComponent->GetValueAsFloat("ThrottleValue");
	float Brake = VehicleController->BlackboardComponent->GetValueAsFloat("BrakeValue");
	float Steer = VehicleController->BlackboardComponent->GetValueAsFloat("SteerValue");
	ApplyControlValue(Throttle, Steer, Brake);
}

void AWheeledVehicleObject::UpdateBlackBoard(float Delta)
{
	VehicleController->BlackboardComponent->SetValueAsVector("VehicleWorldLocation", this->GetActorLocation());
	VehicleController->BlackboardComponent->SetValueAsFloat("TimeDelta", Delta);
	VehicleController->BlackboardComponent->SetValueAsVector("VehicleVelocity", this->GetVelocity());
}

bool AWheeledVehicleObject::SelfDestroy()
{
	this->Destroy();
	return true;
}

FRotator AWheeledVehicleObject::CalculateRotation()
{
	if (WayPoint != NULL)
	{
		FVector Start = FVector(1, 0, 0);
		FVector End = WayPoint->SplineComponent->GetDirectionAtDistanceAlongSpline(WayPoint->SplineComponent->GetSplineLength() * 0.5f, ESplineCoordinateSpace::World);
		float Angle = acos(FVector::DotProduct(Start, End)) * 180 / 3.14159;
		float Del = Start.X * End.Y - End.X * Start.Y;
		if (Del < 0)
		{
			Angle = 360 - Angle;
		}
		return FRotator(0, Angle, 0);
	}
	else
	{
		PrintLog("Waypoint Null");
		return FRotator::ZeroRotator;
	}
}



bool AWheeledVehicleObject::InitializeWheeledVehicle(FString Path, AWayPoint* WP)
{
	
	PrintLog("Initialize Wheeled Vehicle ");
	BehaviorTreePath = Path;
	WayPoint = WP;
	if (VehicleController != NULL)
	{
		PrintLog("Vehicle Controller not NULL");
		VehicleController->InitializeVehicleController(BehaviorTreePath, WayPoint);
		this->SetActorRotation(CalculateRotation(), ETeleportType::TeleportPhysics);
		return true;
	}
	else
	{
		PrintLog("Vehicle Controller NULL");
		return false;
	}
}

void AWheeledVehicleObject::ApplyControlValue(float Throttle, float Steering, float Brake)
{
	this->GetVehicleMovement()->SetBrakeInput(Brake);
	this->GetVehicleMovement()->SetThrottleInput(Throttle);
	this->GetVehicleMovement()->SetSteeringInput(Steering);
}

void AWheeledVehicleObject::InitializeBlackBoardValues()
{
	
	if (VehicleController != NULL)
	{
		PrintLog("Inside Initialize Black Board ");
		VehicleController->BlackboardComponent->SetValueAsObject("WheeledVehicleMovementComponent", this->GetVehicleMovement());
		VehicleController->BlackboardComponent->SetValueAsObject("WayPoint", this->WayPoint);
		VehicleController->BlackboardComponent->SetValueAsBool("IsStopSignAhead", this->WayPoint->isStopSignConnected);
		VehicleController->BlackboardComponent->SetValueAsVector("VehicleWorldLocation", this->GetActorLocation());
		VehicleController->BlackboardComponent->SetValueAsFloat("DesiredVelocity", this->WayPoint->SpeedLimit);
		VehicleController->BlackboardComponent->SetValueAsInt("VelocityStatus", 1);
	}
}


