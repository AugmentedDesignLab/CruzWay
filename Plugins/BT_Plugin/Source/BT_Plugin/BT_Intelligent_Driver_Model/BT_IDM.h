// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


/**
 *	Intelligent driver model class for Behavior tree Vehicle
	
 */
class BT_PLUGIN_API BT_IDM
{

private:
	float DesiredVelocity;
	float SafetyGap;
	float JamDistance;
	float MaximumAcceleration;
	float DesiredDeceleration;
	int AccelerationExponent;

	
	
public:
	BT_IDM();
	~BT_IDM();

	
	void InitIDM(
		float const& DesiredVelocity,
		float const& SafetyGap,
		float const& JamDistance,
		float const& MaximumAcceleration,
		float const& DesiredDeceleration,
		int const& AccelerationExponent
	);

	float BrakingDeceleration(
		float const& NetDistanceGap,
		float const& ActualVelocity,
		float const& VelocityDifference
	);

	float CalculateIDMAcceleration(
		float const& NetDistanceGap,
		float const& ActualVelocity,
		float const& VelocityDifference
	);
	
	
	FString IDM_value_string();

};
