// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SYCHARACTER_SYCharacter_generated_h
#error "SYCharacter.generated.h already included, missing '#pragma once' in SYCharacter.h"
#endif
#define SYCHARACTER_SYCharacter_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_SYCharacter_h


#define FOREACH_ENUM_ECHARACTERSTATE(op) \
	op(ECharacterState::PREINIT) \
	op(ECharacterState::LOADING) \
	op(ECharacterState::READY) \
	op(ECharacterState::DEAD) 

enum class ECharacterState : uint8;
template<> SYCHARACTER_API UEnum* StaticEnum<ECharacterState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
