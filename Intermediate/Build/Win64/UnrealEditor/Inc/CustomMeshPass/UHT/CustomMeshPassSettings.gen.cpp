// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomMeshPass/Public/CustomMeshPassSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomMeshPassSettings() {}

// Begin Cross Module References
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassSettings();
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassSettings_NoRegister();
CUSTOMMESHPASS_API UEnum* Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettingsBackedByCVars();
UPackage* Z_Construct_UPackage__Script_CustomMeshPass();
// End Cross Module References

// Begin Class UCustomMeshPassSettings
void UCustomMeshPassSettings::StaticRegisterNativesUCustomMeshPassSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCustomMeshPassSettings);
UClass* Z_Construct_UClass_UCustomMeshPassSettings_NoRegister()
{
	return UCustomMeshPassSettings::StaticClass();
}
struct Z_Construct_UClass_UCustomMeshPassSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae \xe2\x86\x92 \xe6\x8f\x92\xe4\xbb\xb6 \xe2\x86\x92 Custom Mesh Pass\n * \xe6\xaf\x8f\xe4\xb8\xaa\xe5\xb1\x9e\xe6\x80\xa7\xe9\x80\x9a\xe8\xbf\x87 meta=(ConsoleVariable) \xe4\xb8\x8e\xe5\x90\x8c\xe5\x90\x8d CVar \xe5\x8f\x8c\xe5\x90\x91\xe5\x90\x8c\xe6\xad\xa5\xef\xbc\x8c\xe4\xbf\x9d\xe5\xad\x98\xe5\x9c\xa8 DefaultEngine.ini\n * \xe6\xb3\xa8\xe6\x84\x8f\xef\xbc\x9a""ConsoleVariables.ini \xe4\xb8\x8e\xe6\x8e\xa7\xe5\x88\xb6\xe5\x8f\xb0\xe5\x91\xbd\xe4\xbb\xa4\xe7\x9a\x84\xe4\xbc\x98\xe5\x85\x88\xe7\xba\xa7\xe9\xab\x98\xe4\xba\x8e\xe8\xbf\x99\xe9\x87\x8c\n */" },
#endif
		{ "DisplayName", "Custom Mesh Pass" },
		{ "IncludePath", "CustomMeshPassSettings.h" },
		{ "ModuleRelativePath", "Public/CustomMeshPassSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae \xe2\x86\x92 \xe6\x8f\x92\xe4\xbb\xb6 \xe2\x86\x92 Custom Mesh Pass\n\xe6\xaf\x8f\xe4\xb8\xaa\xe5\xb1\x9e\xe6\x80\xa7\xe9\x80\x9a\xe8\xbf\x87 meta=(ConsoleVariable) \xe4\xb8\x8e\xe5\x90\x8c\xe5\x90\x8d CVar \xe5\x8f\x8c\xe5\x90\x91\xe5\x90\x8c\xe6\xad\xa5\xef\xbc\x8c\xe4\xbf\x9d\xe5\xad\x98\xe5\x9c\xa8 DefaultEngine.ini\n\xe6\xb3\xa8\xe6\x84\x8f\xef\xbc\x9a""ConsoleVariables.ini \xe4\xb8\x8e\xe6\x8e\xa7\xe5\x88\xb6\xe5\x8f\xb0\xe5\x91\xbd\xe4\xbb\xa4\xe7\x9a\x84\xe4\xbc\x98\xe5\x85\x88\xe7\xba\xa7\xe9\xab\x98\xe4\xba\x8e\xe8\xbf\x99\xe9\x87\x8c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Rendering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x80\xbb\xe5\xbc\x80\xe5\x85\xb3 */" },
#endif
		{ "ConsoleVariable", "r.CustomMeshPass" },
		{ "DisplayName", "Enabled" },
		{ "ModuleRelativePath", "Public/CustomMeshPassSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x80\xbb\xe5\xbc\x80\xe5\x85\xb3" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightingPath_MetaData[] = {
		{ "Category", "Rendering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x85\x89\xe7\x85\xa7\xe8\xb7\xaf\xe5\xbe\x84 */" },
#endif
		{ "ConsoleVariable", "r.CustomMeshPass.LightingPath" },
		{ "ModuleRelativePath", "Public/CustomMeshPassSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x85\x89\xe7\x85\xa7\xe8\xb7\xaf\xe5\xbe\x84" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LightingPath_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LightingPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomMeshPassSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UCustomMeshPassSettings_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((UCustomMeshPassSettings*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomMeshPassSettings_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCustomMeshPassSettings), &Z_Construct_UClass_UCustomMeshPassSettings_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCustomMeshPassSettings_Statics::NewProp_LightingPath_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCustomMeshPassSettings_Statics::NewProp_LightingPath = { "LightingPath", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassSettings, LightingPath), Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightingPath_MetaData), NewProp_LightingPath_MetaData) }; // 187488240
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCustomMeshPassSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMeshPassSettings_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMeshPassSettings_Statics::NewProp_LightingPath_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMeshPassSettings_Statics::NewProp_LightingPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMeshPassSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCustomMeshPassSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettingsBackedByCVars,
	(UObject* (*)())Z_Construct_UPackage__Script_CustomMeshPass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMeshPassSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCustomMeshPassSettings_Statics::ClassParams = {
	&UCustomMeshPassSettings::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCustomMeshPassSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMeshPassSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMeshPassSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UCustomMeshPassSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCustomMeshPassSettings()
{
	if (!Z_Registration_Info_UClass_UCustomMeshPassSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCustomMeshPassSettings.OuterSingleton, Z_Construct_UClass_UCustomMeshPassSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCustomMeshPassSettings.OuterSingleton;
}
template<> CUSTOMMESHPASS_API UClass* StaticClass<UCustomMeshPassSettings>()
{
	return UCustomMeshPassSettings::StaticClass();
}
UCustomMeshPassSettings::UCustomMeshPassSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomMeshPassSettings);
UCustomMeshPassSettings::~UCustomMeshPassSettings() {}
// End Class UCustomMeshPassSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCustomMeshPassSettings, UCustomMeshPassSettings::StaticClass, TEXT("UCustomMeshPassSettings"), &Z_Registration_Info_UClass_UCustomMeshPassSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomMeshPassSettings), 2708116137U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h_1427576247(TEXT("/Script/CustomMeshPass"),
	Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
