// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SYCHARACTER_PlayerCharacter_generated_h
#error "PlayerCharacter.generated.h already included, missing '#pragma once' in PlayerCharacter.h"
#endif
#define SYCHARACTER_PlayerCharacter_generated_h

#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_16_DELEGATE \
static inline void FONHPChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& ONHPChangedDelegate) \
{ \
	ONHPChangedDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_15_DELEGATE \
static inline void FOnHPIsZeroDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnHPIsZeroDelegate) \
{ \
	OnHPIsZeroDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_14_DELEGATE \
static inline void FShootDelegate_DelegateWrapper(const FMulticastScriptDelegate& ShootDelegate) \
{ \
	ShootDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_13_DELEGATE \
static inline void FTargetingDelegate_DelegateWrapper(const FMulticastScriptDelegate& TargetingDelegate) \
{ \
	TargetingDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_12_DELEGATE \
static inline void FPutOffDelegate_DelegateWrapper(const FMulticastScriptDelegate& PutOffDelegate) \
{ \
	PutOffDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_11_DELEGATE \
static inline void FRollOnDelegate_DelegateWrapper(const FMulticastScriptDelegate& RollOnDelegate) \
{ \
	RollOnDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_10_DELEGATE \
static inline void FPutONDelegate_DelegateWrapper(const FMulticastScriptDelegate& PutONDelegate) \
{ \
	PutONDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_9_DELEGATE \
static inline void FAttackOnDelegate_DelegateWrapper(const FMulticastScriptDelegate& AttackOnDelegate) \
{ \
	AttackOnDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAttackCheck) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AttackCheck(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Attack(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBomb) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBomb(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBow) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBow(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSword) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetSword(); \
		P_NATIVE_END; \
	}


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAttackCheck) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AttackCheck(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Attack(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBomb) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBomb(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBow) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBow(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSword) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetSword(); \
		P_NATIVE_END; \
	}


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend struct Z_Construct_UClass_APlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SYCharacter"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter)


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend struct Z_Construct_UClass_APlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SYCharacter"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter)


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerCharacter(APlayerCharacter&&); \
	NO_API APlayerCharacter(const APlayerCharacter&); \
public:


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerCharacter(APlayerCharacter&&); \
	NO_API APlayerCharacter(const APlayerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerCharacter)


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__AttackRange() { return STRUCT_OFFSET(APlayerCharacter, AttackRange); } \
	FORCEINLINE static uint32 __PPO__AttackRadius() { return STRUCT_OFFSET(APlayerCharacter, AttackRadius); } \
	FORCEINLINE static uint32 __PPO__CurrentState() { return STRUCT_OFFSET(APlayerCharacter, CurrentState); }


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_18_PROLOG
#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_RPC_WRAPPERS \
	Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_INCLASS \
	Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_INCLASS_NO_PURE_DECLS \
	Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SYCHARACTER_API UClass* StaticClass<class APlayerCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Users_kgca3670_Desktop_pack_SYCharacter_SYCharacter_HostProject_Plugins_SYCharacter_Source_SYCharacter_Public_PlayerCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
