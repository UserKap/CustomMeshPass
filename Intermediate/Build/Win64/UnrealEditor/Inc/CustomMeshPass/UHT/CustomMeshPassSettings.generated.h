// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CustomMeshPassSettings.h"

#ifdef CUSTOMMESHPASS_CustomMeshPassSettings_generated_h
#error "CustomMeshPassSettings.generated.h already included, missing '#pragma once' in CustomMeshPassSettings.h"
#endif
#define CUSTOMMESHPASS_CustomMeshPassSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UCustomMeshPassSettings **************************************************
struct Z_Construct_UClass_UCustomMeshPassSettings_Statics;
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassSettings(ETypeConstructPhase);

#define FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h_16_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UCustomMeshPassSettings_Statics; \
	friend CUSTOMMESHPASS_API UClass* ::Z_Construct_UClass_UCustomMeshPassSettings(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UCustomMeshPassSettings, UDeveloperSettingsBackedByCVars, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/CustomMeshPass"), Z_Construct_UClass_UCustomMeshPassSettings) \
	DECLARE_SERIALIZER(UCustomMeshPassSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomMeshPassSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCustomMeshPassSettings(UCustomMeshPassSettings&&) = delete; \
	UCustomMeshPassSettings(const UCustomMeshPassSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomMeshPassSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomMeshPassSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCustomMeshPassSettings) \
	NO_API virtual ~UCustomMeshPassSettings();


#define FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h_13_PROLOG
#define FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h_16_INCLASS_NO_PURE_DECLS \
	FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCustomMeshPassSettings;

// ********** End Class UCustomMeshPassSettings ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
