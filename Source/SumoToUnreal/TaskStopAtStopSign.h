// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Engine.h"
#include "TaskStopAtStopSign.generated.h"

/**
 * 
 */
UCLASS()
class SUMOTOUNREAL_API UTaskStopAtStopSign : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	float StartTime = 0.0;

	void PrintLog(FString Text)
	{
		if (!GEngine) return;
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, *Text);
	}
};
