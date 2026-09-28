// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CustomMeshPassTypes.h"

#ifdef CUSTOMMESHPASS_CustomMeshPassTypes_generated_h
#error "CustomMeshPassTypes.generated.h already included, missing '#pragma once' in CustomMeshPassTypes.h"
#endif
#define CUSTOMMESHPASS_CustomMeshPassTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "Templates/NoDestroy.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassTypes_h

// ********** Begin Enum ECustomMeshPassLightingPath ***********************************************
#define FOREACH_ENUM_ECUSTOMMESHPASSLIGHTINGPATH(op) \
	op(ECustomMeshPassLightingPath::ForwardCustom) \
	op(ECustomMeshPassLightingPath::DeferredLumen) 

enum class ECustomMeshPassLightingPath : uint8;
template<> struct TIsUEnumClass<ECustomMeshPassLightingPath> { enum { Value = true }; };
template<> UE_NODEBUG CUSTOMMESHPASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECustomMeshPassLightingPath>();
// ********** End Enum ECustomMeshPassLightingPath *************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
