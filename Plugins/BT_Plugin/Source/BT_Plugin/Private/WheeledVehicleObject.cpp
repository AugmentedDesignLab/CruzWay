// Fill out your copyright notice in the Description page of Project Settings.


#include "WheeledVehicleObject.h"
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
	//PrintLog("Inside vehicle object beginplay");
	VehicleController = GetController<AVehicleController>();
	InitializeWheeledVehicle(BehaviorTreePath, WayPoint);
	InitializeBlackBoardValues();
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

bool AWheeledVehicleObject::InitializeWheeledVehicle(FString BehaviorTreePath, AWayPoint* WayPoint)
{
	//PrintLog("Initialize Wheeled Vehicle ");
	if (VehicleController != NULL)
	{
		VehicleController->InitializeVehicleController(BehaviorTreePath, WayPoint);
		return true;
	}
	
	return false;
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
		VehicleController->BlackboardComponent->SetValueAsVector("VehicleWorldLocation", this->GetActorLocation());
		VehicleController->BlackboardComponent->SetValueAsFloat("DesiredVelocity", this->WayPoint->SpeedLimit);
		VehicleController->BlackboardComponent->SetValueAsInt("VelocityStatus", 1);
		//VehicleController->BlackboardComponent->SetValueAsBool("IsStopSignAhead", true);
	}
}


