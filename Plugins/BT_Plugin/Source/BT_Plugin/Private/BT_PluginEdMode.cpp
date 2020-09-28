// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BT_PluginEdMode.h"
#include "BT_PluginEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"

const FEditorModeID FBT_PluginEdMode::EM_BT_PluginEdModeId = TEXT("EM_BT_PluginEdMode");

FBT_PluginEdMode::FBT_PluginEdMode()
{

}

FBT_PluginEdMode::~FBT_PluginEdMode()
{

}

void FBT_PluginEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FBT_PluginEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FBT_PluginEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FBT_PluginEdMode::UsesToolkits() const
{
	return true;
}




