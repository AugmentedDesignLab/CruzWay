// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BT_Plugin.h"
#include "BT_PluginEdMode.h"

#define LOCTEXT_NAMESPACE "FBT_PluginModule"

void FBT_PluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	//UE_LOG(LogTemp, Warning, TEXT("BT plugin module start "));
	FEditorModeRegistry::Get().RegisterMode<FBT_PluginEdMode>(FBT_PluginEdMode::EM_BT_PluginEdModeId, LOCTEXT("BT_PluginEdModeName", "BT_PluginEdMode"), FSlateIcon(), true);

}

void FBT_PluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FBT_PluginEdMode::EM_BT_PluginEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBT_PluginModule, BT_Plugin)