// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BT_Plugin/Public/TaskLaneFollow.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTaskLaneFollow() {}
// Cross Module References
	BT_PLUGIN_API UClass* Z_Construct_UClass_UTaskLaneFollow_NoRegister();
	BT_PLUGIN_API UClass* Z_Construct_UClass_UTaskLaneFollow();
	AIMODULE_API UClass* Z_Construct_UClass_UBTTask_BlackboardBase();
	UPackage* Z_Construct_UPackage__Script_BT_Plugin();
// End Cross Module References
	void UTaskLaneFollow::StaticRegisterNativesUTaskLaneFollow()
	{
	}
	UClass* Z_Construct_UClass_UTaskLaneFollow_NoRegister()
	{
		return UTaskLaneFollow::StaticClass();
	}
	struct Z_Construct_UClass_UTaskLaneFollow_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTaskLaneFollow_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTask_BlackboardBase,
		(UObject* (*)())Z_Construct_UPackage__Script_BT_Plugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTaskLaneFollow_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "TaskLaneFollow.h" },
		{ "ModuleRelativePath", "Public/TaskLaneFollow.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTaskLaneFollow_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTaskLaneFollow>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UTaskLaneFollow_Statics::ClassParams = {
		&UTaskLaneFollow::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UTaskLaneFollow_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UTaskLaneFollow_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTaskLaneFollow()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UTaskLaneFollow_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UTaskLaneFollow, 4143650627);
	template<> BT_PLUGIN_API UClass* StaticClass<UTaskLaneFollow>()
	{
		return UTaskLaneFollow::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTaskLaneFollow(Z_Construct_UClass_UTaskLaneFollow, &UTaskLaneFollow::StaticClass, TEXT("/Script/BT_Plugin"), TEXT("UTaskLaneFollow"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTaskLaneFollow);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
