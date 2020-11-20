#pragma once

#include <ParseXML/Public/WayPoint.h>
#include "VehicleSpecification.generated.h"

USTRUCT(BlueprintType)
struct FVehicleAISpecification
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    TArray<AWayPoint*> Route;

    UPROPERTY(EditAnywhere)
    TSubclassOf<class UBehaviorTree> BehaviorTree;

};

USTRUCT(BlueprintType)
struct FVehicleSpecificationBT
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    FString Name;


};


/*
    Collision Avoidance struct
    variables are
        AccelarationMax:
        P: brake increase rate
*/

/*
    Adaptive cruise control struct
    "Study on the Driving Style Adaptive Vehicle Longitudinal Control Strategy" - paper
    the coefficients k1 and k2 of the transfer function that represent the driving behavioural
    characteristics of different styles of drivers (Table 3)
*/

USTRUCT(BlueprintType)
struct FDriverSpecificationBT
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    float AdaptiveCruiseControlSpecification_K1;

    UPROPERTY(EditAnywhere)
    float AdaptiveCruiseControlSpecification_K2;

    UPROPERTY(EditAnywhere)
    float AccelarationMax;

    UPROPERTY(EditAnywhere)
    float P;

};





