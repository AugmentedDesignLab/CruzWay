// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Route.h"
#include "ParseXML/Public/WayPoint.h"


BT_Route::BT_Route(TArray<AWayPoint*> _Route)
{
	this->Route = _Route;
}

BT_Route::~BT_Route()
{
}

FVector BT_Route::NextLocationOnRoute(float const& LookAheadDistance, FVector const& VehicleWorldLocation)
{
	return FVector();
}

AWayPoint* BT_Route::GetCurrentWayPoint()
{
	return CurrentWayPoint;
}

void BT_Route::SetCurrentWayPoint(AWayPoint* WayPoint)
{
	if (this->Route.Contains(WayPoint))
	{
		CurrentWayPoint = WayPoint;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Setting WayPoint not possible, WayPoint not in the route"));
	}
}
