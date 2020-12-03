// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <Runtime\AIModule\Classes\BehaviorTree\BehaviorTreeComponent.h>
#include <Runtime\AIModule\Classes\BehaviorTree\BlackboardComponent.h>
#include "BT_ControllerCruise_CA.generated.h"

/**
 * 
 */
UCLASS()
class BT_PLUGIN_API ABT_ControllerCruise_CA : public AAIController
{
	GENERATED_BODY()
	
public:
	UBlackboardComponent* BlackboardComponent;
	UBehaviorTreeComponent* BehaviorTreeComponent;


	UBehaviorTree* LoadBehaviorTree(FString BehaviorTreePath);

	//Function to load object from content folder. Copy path from UE
	template <typename ObjClass>
	static FORCEINLINE ObjClass* LoadObjFromPath(const FName& Path)
	{
		if (Path == NAME_None) return NULL;

		return Cast<ObjClass>(StaticLoadObject(ObjClass::StaticClass(), NULL, *Path.ToString()));

	}
};
