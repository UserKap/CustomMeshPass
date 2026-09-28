// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CustomMeshPassSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECustomMeshPassLightingPath : uint8;
#ifdef CUSTOMMESHPASS_CustomMeshPassSubsystem_generated_h
#error "CustomMeshPassSubsystem.generated.h already included, missing '#pragma once' in CustomMeshPassSubsystem.h"
#endif
#define CUSTOMMESHPASS_CustomMeshPassSubsystem_generated_h

#define FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetRegisteredComponentCount); \
	DECLARE_FUNCTION(execGetLightingPath); \
	DECLARE_FUNCTION(execSetLightingPath); \
	DECLARE_FUNCTION(execIsEnabled); \
	DECLARE_FUNCTION(execSetEnabled);


#define FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCustomMeshPassSubsystem(); \
	friend struct Z_Construct_UClass_UCustomMeshPassSubsystem_Statics; \
public: \
	DECLARE_CLASS(UCustomMeshPassSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CustomMeshPass"), NO_API) \
	DECLARE_SERIALIZER(UCustomMeshPassSubsystem)


#define FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomMeshPassSubsystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCustomMeshPassSubsystem(UCustomMeshPassSubsystem&&); \
	UCustomMeshPassSubsystem(const UCustomMeshPassSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomMeshPassSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomMeshPassSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCustomMeshPassSubsystem) \
	NO_API virtual ~UCustomMeshPassSubsystem();


#define FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_18_PROLOG
#define FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_INCLASS_NO_PURE_DECLS \
	FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CUSTOMMESHPASS_API UClass* StaticClass<class UCustomMeshPassSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
