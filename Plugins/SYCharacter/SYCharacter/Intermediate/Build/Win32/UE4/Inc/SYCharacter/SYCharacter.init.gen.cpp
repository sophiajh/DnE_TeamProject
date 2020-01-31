// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSYCharacter_init() {}
	SYCHARACTER_API UFunction* Z_Construct_UDelegateFunction_SYCharacter_AttackOnDelegate__DelegateSignature();
	SYCHARACTER_API UFunction* Z_Construct_UDelegateFunction_SYCharacter_PutONDelegate__DelegateSignature();
	SYCHARACTER_API UFunction* Z_Construct_UDelegateFunction_SYCharacter_RollOnDelegate__DelegateSignature();
	SYCHARACTER_API UFunction* Z_Construct_UDelegateFunction_SYCharacter_PutOffDelegate__DelegateSignature();
	SYCHARACTER_API UFunction* Z_Construct_UDelegateFunction_SYCharacter_TargetingDelegate__DelegateSignature();
	SYCHARACTER_API UFunction* Z_Construct_UDelegateFunction_SYCharacter_ShootDelegate__DelegateSignature();
	SYCHARACTER_API UFunction* Z_Construct_UDelegateFunction_SYCharacter_OnHPIsZeroDelegate__DelegateSignature();
	SYCHARACTER_API UFunction* Z_Construct_UDelegateFunction_SYCharacter_ONHPChangedDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SYCharacter()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SYCharacter_AttackOnDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SYCharacter_PutONDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SYCharacter_RollOnDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SYCharacter_PutOffDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SYCharacter_TargetingDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SYCharacter_ShootDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SYCharacter_OnHPIsZeroDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SYCharacter_ONHPChangedDelegate__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/SYCharacter",
				SingletonFuncArray,
				ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x9C658BEF,
				0x26EC57E0,
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
