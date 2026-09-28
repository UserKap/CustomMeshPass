// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CustomMeshPassTypes.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CUSTOMMESHPASS_CustomMeshPassTypes_generated_h
#error "CustomMeshPassTypes.generated.h already included, missing '#pragma once' in CustomMeshPassTypes.h"
#endif
#define CUSTOMMESHPASS_CustomMeshPassTypes_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassTypes_h


#define FOREACH_ENUM_ECUSTOMMESHPASSLIGHTINGPATH(op) \
	op(ECustomMeshPassLightingPath::ForwardCustom) \
	op(ECustomMeshPassLightingPath::DeferredLumen) 

enum class ECustomMeshPassLightingPath : uint8;
template<> struct TIsUEnumClass<ECustomMeshPassLightingPath> { enum { Value = true }; };
template<> CUSTOMMESHPASS_API UEnum* StaticEnum<ECustomMeshPassLightingPath>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
