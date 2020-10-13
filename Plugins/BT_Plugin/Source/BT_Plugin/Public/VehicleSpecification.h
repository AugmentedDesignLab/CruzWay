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


