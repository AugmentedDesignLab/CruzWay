// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BT_Plugin/Public/TaskStartFromStopSign.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTaskStartFromStopSign() {}
// Cross Module References
	BT_PLUGIN_API UClass* Z_Construct_UClass_UTaskStartFromStopSign_NoRegister();
	BT_PLUGIN_API UClass* Z_Construct_UClass_UTaskStartFromStopSign();
	AIMODULE_API UClass* Z_Construct_UClass_UBTTask_BlackboardBase();
	UPackage* Z_Construct_UPackage__Script_BT_Plugin();
// End Cross Module References
	void UTaskStartFromStopSign::StaticRegisterNativesUTaskStartFromStopSign()
	{
	}
	UClass* Z_Construct_UClass_UTaskStartFromStopSign_NoRegister()
	{
		return UTaskStartFromStopSign::StaticClass();
	}
	struct Z_Construct_UClass_UTaskStartFromStopSign_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTaskStartFromStopSign_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTask_BlackboardBase,
		(UObject* (*)())Z_Construct_UPackage__Script_BT_Plugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTaskStartFromStopSign_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "TaskStartFromStopSign.h" },
		{ "ModuleRelativePath", "Public/TaskStartFromStopSign.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTaskStartFromStopSign_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTaskStartFromStopSign>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UTaskStartFromStopSign_Statics::ClassParams = {
		&UTaskStartFromStopSign::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UTaskStartFromStopSign_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UTaskStartFromStopSign_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTaskStartFromStopSign()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UTaskStartFromStopSign_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UTaskStartFromStopSign, 1128666793);
	template<> BT_PLUGIN_API UClass* StaticClass<UTaskStartFromStopSign>()
	{
		return UTaskStartFromStopSign::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTaskStartFromStopSign(Z_Construct_UClass_UTaskStartFromStopSign, &UTaskStartFromStopSign::StaticClass, TEXT("/Script/BT_Plugin"), TEXT("UTaskStartFromStopSign"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTaskStartFromStopSign);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
