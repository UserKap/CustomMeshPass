// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CustomMeshPassSubsystem.h"

#ifdef CUSTOMMESHPASS_CustomMeshPassSubsystem_generated_h
#error "CustomMeshPassSubsystem.generated.h already included, missing '#pragma once' in CustomMeshPassSubsystem.h"
#endif
#define CUSTOMMESHPASS_CustomMeshPassSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECustomMeshPassLightingPath : uint8;

// ********** Begin Class UCustomMeshPassSubsystem *************************************************
#define FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetRegisteredComponentCount); \
	DECLARE_FUNCTION(execGetLightingPath); \
	DECLARE_FUNCTION(execSetLightingPath); \
	DECLARE_FUNCTION(execIsEnabled); \
	DECLARE_FUNCTION(execSetEnabled);


struct Z_Construct_UClass_UCustomMeshPassSubsystem_Statics;
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassSubsystem(ETypeConstructPhase);

#define FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UCustomMeshPassSubsystem_Statics; \
	friend CUSTOMMESHPASS_API UClass* ::Z_Construct_UClass_UCustomMeshPassSubsystem(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UCustomMeshPassSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CustomMeshPass"), Z_Construct_UClass_UCustomMeshPassSubsystem) \
	DECLARE_SERIALIZER(UCustomMeshPassSubsystem)


#define FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomMeshPassSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCustomMeshPassSubsystem(UCustomMeshPassSubsystem&&) = delete; \
	UCustomMeshPassSubsystem(const UCustomMeshPassSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomMeshPassSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomMeshPassSubsystem); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCustomMeshPassSubsystem) \
	NO_API virtual ~UCustomMeshPassSubsystem();


#define FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_18_PROLOG
#define FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_INCLASS_NO_PURE_DECLS \
	FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCustomMeshPassSubsystem;

// ********** End Class UCustomMeshPassSubsystem ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
