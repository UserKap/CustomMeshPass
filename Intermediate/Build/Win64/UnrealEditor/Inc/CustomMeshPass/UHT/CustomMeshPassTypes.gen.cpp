// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomMeshPassTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeCustomMeshPassTypes() {}

// ********** Begin Cross Module References ********************************************************
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_CustomMeshPass(ETypeConstructPhase);
CUSTOMMESHPASS_API UEnum* Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum ECustomMeshPassLightingPath ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath_Statics
template<> CUSTOMMESHPASS_NON_ATTRIBUTED_API UEnum* StaticEnum<ECustomMeshPassLightingPath>()
{
	return Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x85\x89\xe7\x85\xa7\xe8\xb7\xaf\xe5\xbe\x84\xef\xbc\x8c\xe6\x95\xb0\xe5\x80\xbc\xe4\xb8\x8e r.CustomMeshPass.LightingPath \xe4\xb8\x80\xe4\xb8\x80\xe5\xaf\xb9\xe5\xba\x94 */" },
#endif
		{ "DeferredLumen.Comment", "/** \xe5\x86\x99 GBuffer\xef\xbc\x8c\xe7\x94\xb1\xe5\xbc\x95\xe6\x93\x8e Deferred + Lumen \xe7\x85\xa7\xe4\xba\xae\xef\xbc\x9b\xe5\xb9\xb3\xe5\x8f\xb0\xe6\x97\xa0\xe7\xbb\x8f\xe5\x85\xb8 GBuffer\xef\xbc\x88\xe5\xa6\x82 Substrate\xef\xbc\x89\xe6\x97\xb6\xe8\x87\xaa\xe5\x8a\xa8\xe5\x9b\x9e\xe9\x80\x80\xe5\x89\x8d\xe5\x90\x91 */" },
		{ "DeferredLumen.DisplayName", "Deferred + Lumen (GBuffer)" },
		{ "DeferredLumen.Name", "ECustomMeshPassLightingPath::DeferredLumen" },
		{ "DeferredLumen.ToolTip", "\xe5\x86\x99 GBuffer\xef\xbc\x8c\xe7\x94\xb1\xe5\xbc\x95\xe6\x93\x8e Deferred + Lumen \xe7\x85\xa7\xe4\xba\xae\xef\xbc\x9b\xe5\xb9\xb3\xe5\x8f\xb0\xe6\x97\xa0\xe7\xbb\x8f\xe5\x85\xb8 GBuffer\xef\xbc\x88\xe5\xa6\x82 Substrate\xef\xbc\x89\xe6\x97\xb6\xe8\x87\xaa\xe5\x8a\xa8\xe5\x9b\x9e\xe9\x80\x80\xe5\x89\x8d\xe5\x90\x91" },
		{ "ForwardCustom.Comment", "/** \xe8\x87\xaa\xe5\x86\x99 BRDF\xef\xbc\x8c\xe5\x9c\xa8 PrePostProcess \xe7\x9b\xb4\xe6\x8e\xa5\xe7\x94\xbb\xe8\xbf\x9b SceneColor\xef\xbc\x88\xe4\xb8\x8d\xe6\x8e\xa5\xe6\x94\xb6\xe9\x98\xb4\xe5\xbd\xb1\xef\xbc\x89 */" },
		{ "ForwardCustom.DisplayName", "Forward (Custom BRDF)" },
		{ "ForwardCustom.Name", "ECustomMeshPassLightingPath::ForwardCustom" },
		{ "ForwardCustom.ToolTip", "\xe8\x87\xaa\xe5\x86\x99 BRDF\xef\xbc\x8c\xe5\x9c\xa8 PrePostProcess \xe7\x9b\xb4\xe6\x8e\xa5\xe7\x94\xbb\xe8\xbf\x9b SceneColor\xef\xbc\x88\xe4\xb8\x8d\xe6\x8e\xa5\xe6\x94\xb6\xe9\x98\xb4\xe5\xbd\xb1\xef\xbc\x89" },
		{ "ModuleRelativePath", "Public/CustomMeshPassTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x85\x89\xe7\x85\xa7\xe8\xb7\xaf\xe5\xbe\x84\xef\xbc\x8c\xe6\x95\xb0\xe5\x80\xbc\xe4\xb8\x8e r.CustomMeshPass.LightingPath \xe4\xb8\x80\xe4\xb8\x80\xe5\xaf\xb9\xe5\xba\x94" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECustomMeshPassLightingPath::ForwardCustom", (int64)ECustomMeshPassLightingPath::ForwardCustom },
		{ "ECustomMeshPassLightingPath::DeferredLumen", (int64)ECustomMeshPassLightingPath::DeferredLumen },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_CustomMeshPass,
	nullptr,
	"ECustomMeshPassLightingPath",
	"ECustomMeshPassLightingPath",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_ECustomMeshPassLightingPath;
UEnum* Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_ECustomMeshPassLightingPath.OuterSingleton)
		{
			ZRIE_ECustomMeshPassLightingPath.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath, (UObject*)Z_Construct_UPackage__Script_CustomMeshPass(ETypeConstructPhase::Outer), TEXT("ECustomMeshPassLightingPath"));
		}
		return ZRIE_ECustomMeshPassLightingPath.OuterSingleton;
	}
	if (!ZRIE_ECustomMeshPassLightingPath.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_ECustomMeshPassLightingPath.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_ECustomMeshPassLightingPath.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum ECustomMeshPassLightingPath *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassTypes_h__Script_CustomMeshPass_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath, TEXT("ECustomMeshPassLightingPath"), &ZRIE_ECustomMeshPassLightingPath, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 463374955U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassTypes_h__Script_CustomMeshPass_088966d23bb9a8103d5931f403580d22cc62e9ee{
	TEXT("/Script/CustomMeshPass"),
	nullptr, 0,
	nullptr, 0,
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
