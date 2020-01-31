// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"
#include "Modules/ModuleManager.h"

//DECLARE_LOG_CATEGORY_EXTERN(DnE_AI, Log, All);
//
//#define ABLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
//#define ABLOG_S(Verbosity) UE_LOG(DnE_AI, Verbosity, TEXT("%s"), *ABLOG_CALLINFO)
//#define ABLOG(Verbosity, Format, ...) UE_LOG(DnE_AI, Verbosity, TEXT("%s %s"), *ABLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__)) 


class FDnE_AIModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
