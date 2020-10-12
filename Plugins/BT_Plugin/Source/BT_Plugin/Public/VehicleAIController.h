// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine.h"
#include <ParseXML/Public/WayPoint.h>
#include <Runtime\AIModule\Classes\BehaviorTree\BehaviorTreeComponent.h>
#include <Runtime\AIModule\Classes\BehaviorTree\BlackboardComponent.h>
#include "VehicleAIController.generated.h"

/**
 * 
 */
UCLASS()
class BT_PLUGIN_API AVehicleAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AVehicleAIController();

protected:
	virtual void BeginPlay() override;

public:
	void Tick(float DeltaTime) override;



	UBlackboardComponent* BlackboardComponent;
	UBehaviorTreeComponent* BehaviorTreeComponent;
	AWayPoint* WayPoint;


	void PrintLog(FString Text)
	{
		if (!GEngine) return;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, *Text);
	}
};
