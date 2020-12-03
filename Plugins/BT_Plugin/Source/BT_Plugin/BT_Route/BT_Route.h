// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParseXML/Public/WayPoint.h"

/**
 * Route class takes in TArray<AWaypoint>
 */
class BT_PLUGIN_API BT_Route
{
private:
	TArray<AWayPoint*> Route;
	AWayPoint* CurrentWayPoint;
public:
	BT_Route(TArray<AWayPoint*> _Route);
	~BT_Route();

	FVector NextLocationOnRoute(
		float const& LookAheadDistance,
		FVector const& VehicleWorldLocation);

	AWayPoint* GetCurrentWayPoint();
	void SetCurrentWayPoint(AWayPoint* WayPoint);
};
