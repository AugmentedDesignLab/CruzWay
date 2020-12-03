// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_ControllerCruise_CA.h"
#include <BT_Plugin.h>
#include <Runtime\AIModule\Classes\BehaviorTree\BehaviorTree.h>















UBehaviorTree* ABT_ControllerCruise_CA::LoadBehaviorTree(FString BehaviorTreePath)
{
	UBehaviorTree* BehaviorTreeAsset = LoadObjFromPath<UBehaviorTree>(FName(*BehaviorTreePath));
	if (BehaviorTreeAsset != NULL)
	{
		//PrintLog(" asset name ");
		return BehaviorTreeAsset;
	}
	else return nullptr;
}
