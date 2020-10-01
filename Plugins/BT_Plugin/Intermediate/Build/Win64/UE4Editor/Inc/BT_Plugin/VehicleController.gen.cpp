// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BT_Plugin/Public/VehicleController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVehicleController() {}
// Cross Module References
	BT_PLUGIN_API UClass* Z_Construct_UClass_AVehicleController_NoRegister();
	BT_PLUGIN_API UClass* Z_Construct_UClass_AVehicleController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_BT_Plugin();
// End Cross Module References
	void AVehicleController::StaticRegisterNativesAVehicleController()
	{
	}
	UClass* Z_Construct_UClass_AVehicleController_NoRegister()
	{
		return AVehicleController::StaticClass();
	}
	struct Z_Construct_UClass_AVehicleController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVehicleController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_BT_Plugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVehicleController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "VehicleController.h" },
		{ "ModuleRelativePath", "Public/VehicleController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVehicleController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVehicleController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVehicleController_Statics::ClassParams = {
		&AVehicleController::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A0u,
		METADATA_PARAMS(Z_Construct_UClass_AVehicleController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVehicleController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVehicleController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVehicleController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVehicleController, 582094120);
	template<> BT_PLUGIN_API UClass* StaticClass<AVehicleController>()
	{
		return AVehicleController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVehicleController(Z_Construct_UClass_AVehicleController, &AVehicleController::StaticClass, TEXT("/Script/BT_Plugin"), TEXT("AVehicleController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVehicleController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
