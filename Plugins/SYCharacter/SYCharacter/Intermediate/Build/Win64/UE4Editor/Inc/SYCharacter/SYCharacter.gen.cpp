// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SYCharacter/Public/SYCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSYCharacter() {}
// Cross Module References
	SYCHARACTER_API UEnum* Z_Construct_UEnum_SYCharacter_ECharacterState();
	UPackage* Z_Construct_UPackage__Script_SYCharacter();
// End Cross Module References
	static UEnum* ECharacterState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_SYCharacter_ECharacterState, Z_Construct_UPackage__Script_SYCharacter(), TEXT("ECharacterState"));
		}
		return Singleton;
	}
	template<> SYCHARACTER_API UEnum* StaticEnum<ECharacterState>()
	{
		return ECharacterState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ECharacterState(ECharacterState_StaticEnum, TEXT("/Script/SYCharacter"), TEXT("ECharacterState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_SYCharacter_ECharacterState_Hash() { return 1722016839U; }
	UEnum* Z_Construct_UEnum_SYCharacter_ECharacterState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_SYCharacter();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ECharacterState"), 0, Get_Z_Construct_UEnum_SYCharacter_ECharacterState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ECharacterState::PREINIT", (int64)ECharacterState::PREINIT },
				{ "ECharacterState::LOADING", (int64)ECharacterState::LOADING },
				{ "ECharacterState::READY", (int64)ECharacterState::READY },
				{ "ECharacterState::DEAD", (int64)ECharacterState::DEAD },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "DEAD.Name", "ECharacterState::DEAD" },
				{ "LOADING.Name", "ECharacterState::LOADING" },
				{ "ModuleRelativePath", "Public/SYCharacter.h" },
				{ "PREINIT.Name", "ECharacterState::PREINIT" },
				{ "READY.Name", "ECharacterState::READY" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_SYCharacter,
				nullptr,
				"ECharacterState",
				"ECharacterState",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
