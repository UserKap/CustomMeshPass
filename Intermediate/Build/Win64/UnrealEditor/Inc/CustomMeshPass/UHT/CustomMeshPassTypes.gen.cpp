// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomMeshPass/Public/CustomMeshPassTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomMeshPassTypes() {}

// Begin Cross Module References
CUSTOMMESHPASS_API UEnum* Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath();
UPackage* Z_Construct_UPackage__Script_CustomMeshPass();
// End Cross Module References

// Begin Enum ECustomMeshPassLightingPath
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECustomMeshPassLightingPath;
static UEnum* ECustomMeshPassLightingPath_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECustomMeshPassLightingPath.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECustomMeshPassLightingPath.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath, (UObject*)Z_Construct_UPackage__Script_CustomMeshPass(), TEXT("ECustomMeshPassLightingPath"));
	}
	return Z_Registration_Info_UEnum_ECustomMeshPassLightingPath.OuterSingleton;
}
template<> CUSTOMMESHPASS_API UEnum* StaticEnum<ECustomMeshPassLightingPath>()
{
	return ECustomMeshPassLightingPath_StaticEnum();
}
struct Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
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
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CustomMeshPass,
	nullptr,
	"ECustomMeshPassLightingPath",
	"ECustomMeshPassLightingPath",
	Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath()
{
	if (!Z_Registration_Info_UEnum_ECustomMeshPassLightingPath.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECustomMeshPassLightingPath.InnerSingleton, Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECustomMeshPassLightingPath.InnerSingleton;
}
// End Enum ECustomMeshPassLightingPath

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassTypes_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ECustomMeshPassLightingPath_StaticEnum, TEXT("ECustomMeshPassLightingPath"), &Z_Registration_Info_UEnum_ECustomMeshPassLightingPath, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 187488240U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassTypes_h_2492173192(TEXT("/Script/CustomMeshPass"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassTypes_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
