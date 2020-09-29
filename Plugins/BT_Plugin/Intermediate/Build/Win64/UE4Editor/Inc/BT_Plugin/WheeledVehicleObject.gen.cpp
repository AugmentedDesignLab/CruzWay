// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BT_Plugin/Public/WheeledVehicleObject.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWheeledVehicleObject() {}
// Cross Module References
	BT_PLUGIN_API UClass* Z_Construct_UClass_AWheeledVehicleObject_NoRegister();
	BT_PLUGIN_API UClass* Z_Construct_UClass_AWheeledVehicleObject();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_AWheeledVehicle();
	UPackage* Z_Construct_UPackage__Script_BT_Plugin();
	PARSEXML_API UClass* Z_Construct_UClass_AWayPoint_NoRegister();
// End Cross Module References
	void AWheeledVehicleObject::StaticRegisterNativesAWheeledVehicleObject()
	{
	}
	UClass* Z_Construct_UClass_AWheeledVehicleObject_NoRegister()
	{
		return AWheeledVehicleObject::StaticClass();
	}
	struct Z_Construct_UClass_AWheeledVehicleObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BehaviorTreePath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_BehaviorTreePath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WayPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WayPoint;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWheeledVehicleObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AWheeledVehicle,
		(UObject* (*)())Z_Construct_UPackage__Script_BT_Plugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWheeledVehicleObject_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "WheeledVehicleObject.h" },
		{ "ModuleRelativePath", "Public/WheeledVehicleObject.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWheeledVehicleObject_Statics::NewProp_BehaviorTreePath_MetaData[] = {
		{ "Category", "WheeledVehicleObject" },
		{ "ModuleRelativePath", "Public/WheeledVehicleObject.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AWheeledVehicleObject_Statics::NewProp_BehaviorTreePath = { "BehaviorTreePath", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWheeledVehicleObject, BehaviorTreePath), METADATA_PARAMS(Z_Construct_UClass_AWheeledVehicleObject_Statics::NewProp_BehaviorTreePath_MetaData, ARRAY_COUNT(Z_Construct_UClass_AWheeledVehicleObject_Statics::NewProp_BehaviorTreePath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWheeledVehicleObject_Statics::NewProp_WayPoint_MetaData[] = {
		{ "Category", "WheeledVehicleObject" },
		{ "ModuleRelativePath", "Public/WheeledVehicleObject.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWheeledVehicleObject_Statics::NewProp_WayPoint = { "WayPoint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWheeledVehicleObject, WayPoint), Z_Construct_UClass_AWayPoint_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWheeledVehicleObject_Statics::NewProp_WayPoint_MetaData, ARRAY_COUNT(Z_Construct_UClass_AWheeledVehicleObject_Statics::NewProp_WayPoint_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWheeledVehicleObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWheeledVehicleObject_Statics::NewProp_BehaviorTreePath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWheeledVehicleObject_Statics::NewProp_WayPoint,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWheeledVehicleObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWheeledVehicleObject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWheeledVehicleObject_Statics::ClassParams = {
		&AWheeledVehicleObject::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AWheeledVehicleObject_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_AWheeledVehicleObject_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AWheeledVehicleObject_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AWheeledVehicleObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWheeledVehicleObject()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWheeledVehicleObject_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWheeledVehicleObject, 4284283935);
	template<> BT_PLUGIN_API UClass* StaticClass<AWheeledVehicleObject>()
	{
		return AWheeledVehicleObject::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWheeledVehicleObject(Z_Construct_UClass_AWheeledVehicleObject, &AWheeledVehicleObject::StaticClass, TEXT("/Script/BT_Plugin"), TEXT("AWheeledVehicleObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWheeledVehicleObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
