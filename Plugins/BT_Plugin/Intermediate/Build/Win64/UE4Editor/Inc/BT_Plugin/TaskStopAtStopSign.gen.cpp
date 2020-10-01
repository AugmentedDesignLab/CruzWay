// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BT_Plugin/Public/TaskStopAtStopSign.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTaskStopAtStopSign() {}
// Cross Module References
	BT_PLUGIN_API UClass* Z_Construct_UClass_UTaskStopAtStopSign_NoRegister();
	BT_PLUGIN_API UClass* Z_Construct_UClass_UTaskStopAtStopSign();
	AIMODULE_API UClass* Z_Construct_UClass_UBTTask_BlackboardBase();
	UPackage* Z_Construct_UPackage__Script_BT_Plugin();
// End Cross Module References
	void UTaskStopAtStopSign::StaticRegisterNativesUTaskStopAtStopSign()
	{
	}
	UClass* Z_Construct_UClass_UTaskStopAtStopSign_NoRegister()
	{
		return UTaskStopAtStopSign::StaticClass();
	}
	struct Z_Construct_UClass_UTaskStopAtStopSign_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTaskStopAtStopSign_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTask_BlackboardBase,
		(UObject* (*)())Z_Construct_UPackage__Script_BT_Plugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTaskStopAtStopSign_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "TaskStopAtStopSign.h" },
		{ "ModuleRelativePath", "Public/TaskStopAtStopSign.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTaskStopAtStopSign_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTaskStopAtStopSign>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UTaskStopAtStopSign_Statics::ClassParams = {
		&UTaskStopAtStopSign::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UTaskStopAtStopSign_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UTaskStopAtStopSign_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTaskStopAtStopSign()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UTaskStopAtStopSign_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UTaskStopAtStopSign, 1218600979);
	template<> BT_PLUGIN_API UClass* StaticClass<UTaskStopAtStopSign>()
	{
		return UTaskStopAtStopSign::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTaskStopAtStopSign(Z_Construct_UClass_UTaskStopAtStopSign, &UTaskStopAtStopSign::StaticClass, TEXT("/Script/BT_Plugin"), TEXT("UTaskStopAtStopSign"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTaskStopAtStopSign);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
