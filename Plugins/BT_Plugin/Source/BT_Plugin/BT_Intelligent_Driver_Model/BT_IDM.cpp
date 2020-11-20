// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_IDM.h"
#include "Engine.h"
#include "string"
#include "GenericPlatform/GenericPlatformMath.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue,text)

BT_IDM::BT_IDM()
{
}

BT_IDM::~BT_IDM()
{
}

void BT_IDM::InitIDM(float const& _DesiredVelocity, float const& _SafetyGap, float const& _JamDistance, float const& _MaximumAcceleration, float const& _DesiredDeceleration, int const& _AccelerationExponent)
{
	this->DesiredVelocity = _DesiredVelocity;
	this->SafetyGap = _SafetyGap;
	this->JamDistance = _JamDistance;
	this->MaximumAcceleration = _MaximumAcceleration;
	this->DesiredDeceleration = _DesiredDeceleration;
	this->AccelerationExponent = _AccelerationExponent;
}
/*
	A = v * dv / (2 * sqrt(a*b))
	B = v * T
	C = s0
*/
float BT_IDM::BrakingDeceleration(float const& NetDistanceGap, float const& ActualVelocity, float const& VelocityDifference)
{
	float A = ActualVelocity * VelocityDifference / (2 * FGenericPlatformMath::Sqrt(MaximumAcceleration * DesiredDeceleration)); // v * dv / (2 * sqrt(a*b))
	float B = ActualVelocity * SafetyGap; //  v * T
	float C = JamDistance; // s0
	return FGenericPlatformMath::Pow((A + B + C) / NetDistanceGap, 2);
}

float BT_IDM::CalculateIDMAcceleration(float const& NetDistanceGap, float const& ActualVelocity, float const& VelocityDifference)
{
	float _VelocityRatio = FGenericPlatformMath::Pow((ActualVelocity / DesiredVelocity), AccelerationExponent);
	float _BrakingDeceleration = BrakingDeceleration(NetDistanceGap, ActualVelocity, VelocityDifference);
	return MaximumAcceleration * (1 - _VelocityRatio - _BrakingDeceleration);
}



FString BT_IDM::IDM_value_string()
{
	FString r = "Desired Velocity " + FString::SanitizeFloat(DesiredVelocity)
		+ "Safety Gap " + FString::SanitizeFloat(SafetyGap)
		+ "JamDistance " + FString::SanitizeFloat(JamDistance)
		+ "MaximumAcceleration " + FString::SanitizeFloat(MaximumAcceleration)
		+ "DesiredDeceleration " + FString::SanitizeFloat(DesiredDeceleration);
		return r;
}


