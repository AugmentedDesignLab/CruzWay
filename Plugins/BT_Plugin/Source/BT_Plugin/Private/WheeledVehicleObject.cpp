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
	if (VehicleController->ReInitialize == true)
	{
		PrintLog("Reinitialize ");
		ReInitializeWheeledVehicle();
		VehicleController->ReInitialize = false;
		//this->SelfDestroy();
	}
	else
	{
		UpdateBlackBoard(DeltaTime);
		UpdateControlValue();
	}
	if (GetActorLocation().Z > 100)
	{
		this->SelfDestroy();
	}
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

bool AWheeledVehicleObject::ReInitializeWheeledVehicle()
{
	TArray<AActor*> AllWayPointActor = FindAllWaypoint();
	TArray<AWayPoint*> WayPoints;
	TArray<AWayPoint*> WaypointStraight;
	AWayPoint* NearestWayPoint = NULL;
	for (int i = 0; i < AllWayPointActor.Num(); i++)
	{
		WayPoints.Add(static_cast<AWayPoint*>(AllWayPointActor[i]));
	}
	AWayPoint* CurWayPoint = Cast<AWayPoint>(VehicleController->BlackboardComponent->GetValueAsObject("WayPoint"));
	FVector CurWayPointLocation = CurWayPoint->GetActorLocation();
	float Distance = 10000.0;
	for (int i = 0; i < WayPoints.Num(); i++)
	{
		if (WayPoints[i]->turnType == "straight" && WayPoints[i]->TotalDistance > 3000)
		{
			//PrintLog("Straight road" + WayPoints[i]->directionOfSpline.ToString());
			FVector WayPointLocation = WayPoints[i]->GetActorLocation();
			float TempDistance = FVector::Distance(CurWayPointLocation, WayPointLocation);
			//PrintLog("temp Distance " + FString::SanitizeFloat(TempDistance));
			if (TempDistance < Distance && TempDistance > 350)
			{
				NearestWayPoint = WayPoints[i];
				Distance = TempDistance;
			}
			WaypointStraight.Add(WayPoints[i]);
		}
	}
	if (NearestWayPoint != NULL)
	{
		PrintLog("inside neartest way point " + NearestWayPoint->GetName());
		PrintLog("Vehicle Location " + this->GetActorLocation().ToString());
		PrintLog("Vehicle Rotation " + this->GetActorRotation().ToString());
		
		//this->GetVehicleMovementComponent()->StopMovementImmediately();
		//VehicleController->BehaviorTreeComponent->PauseLogic("");
		
		FVector ReLocation = NearestWayPoint->SplineComponent->GetLocationAtDistanceAlongSpline(0, ESplineCoordinateSpace::World);
		//ReLocation = FVector(ReLocation.X, ReLocation.Y, 40.0);

		GetVehicleMovementComponent()->StopMovementImmediately();
		WayPoint = NearestWayPoint;
		VehicleController->SetWayPoint(NearestWayPoint);
		this->SetActorLocationAndRotation(ReLocation, CalculateRotation(), false, 0, ETeleportType::TeleportPhysics);
		VehicleController->BlackboardComponent->SetValueAsObject("WayPoint", NearestWayPoint);
		VehicleController->BehaviorTreeComponent->RestartLogic();
	}
	else
	{
		PrintLog("Distance " + FString::SanitizeFloat(Distance));
	}
	

	return false;
}

TArray<AActor*> AWheeledVehicleObject::FindAllWaypoint()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWayPoint::StaticClass(), FoundActors);
	return FoundActors;
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


