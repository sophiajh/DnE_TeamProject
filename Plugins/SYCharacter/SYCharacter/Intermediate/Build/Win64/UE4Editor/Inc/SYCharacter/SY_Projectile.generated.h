// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef SYCHARACTER_SY_Projectile_generated_h
#error "SY_Projectile.generated.h already included, missing '#pragma once' in SY_Projectile.h"
#endif
#define SYCHARACTER_SY_Projectile_generated_h

#define Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASY_Projectile(); \
	friend struct Z_Construct_UClass_ASY_Projectile_Statics; \
public: \
	DECLARE_CLASS(ASY_Projectile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SYCharacter"), NO_API) \
	DECLARE_SERIALIZER(ASY_Projectile)


#define Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_INCLASS \
private: \
	static void StaticRegisterNativesASY_Projectile(); \
	friend struct Z_Construct_UClass_ASY_Projectile_Statics; \
public: \
	DECLARE_CLASS(ASY_Projectile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SYCharacter"), NO_API) \
	DECLARE_SERIALIZER(ASY_Projectile)


#define Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASY_Projectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASY_Projectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASY_Projectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASY_Projectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASY_Projectile(ASY_Projectile&&); \
	NO_API ASY_Projectile(const ASY_Projectile&); \
public:


#define Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASY_Projectile(ASY_Projectile&&); \
	NO_API ASY_Projectile(const ASY_Projectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASY_Projectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASY_Projectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASY_Projectile)


#define Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh_Arrow() { return STRUCT_OFFSET(ASY_Projectile, Mesh_Arrow); } \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(ASY_Projectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(ASY_Projectile, ProjectileMovement); }


#define Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_9_PROLOG
#define Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_RPC_WRAPPERS \
	Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_INCLASS \
	Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_INCLASS_NO_PURE_DECLS \
	Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SYCHARACTER_API UClass* StaticClass<class ASY_Projectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Map_0130_Plugins_SYCharacter_SYCharacter_Source_SYCharacter_Public_SY_Projectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
