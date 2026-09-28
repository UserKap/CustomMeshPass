// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomMeshPassSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeCustomMeshPassSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettingsBackedByCVars(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_CustomMeshPass(ETypeConstructPhase);
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassSettings(ETypeConstructPhase);
CUSTOMMESHPASS_API UEnum* Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath(ETypeConstructPhase);
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassSettings(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UCustomMeshPassSettings **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UCustomMeshPassSettings_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
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

// ********** Begin Class UCustomMeshPassSettings constinit property declarations ******************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((UCustomMeshPassSettings*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LightingPath_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LightingPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCustomMeshPassSettings constinit property declarations ********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomMeshPassSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UCustomMeshPassSettings Property Definitions *****************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UCustomMeshPassSettings), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_LightingPath_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_LightingPath = { "LightingPath", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassSettings, LightingPath), Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightingPath_MetaData), NewProp_LightingPath_MetaData) }; // 1b9e8a6bb7382aec31ea97c57ab448f524df9152
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LightingPath_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LightingPath,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UCustomMeshPassSettings Property Definitions *******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UDeveloperSettingsBackedByCVars,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_CustomMeshPass,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UCustomMeshPassSettings,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UCustomMeshPassSettings;
UClass* Z_Construct_UClass_UCustomMeshPassSettings(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UCustomMeshPassSettings;
		if (!Z_Registration_Info_UClass_UCustomMeshPassSettings.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("CustomMeshPassSettings"),
				Z_Registration_Info_UClass_UCustomMeshPassSettings.InnerSingleton,
				nullptr,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_UCustomMeshPassSettings.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UCustomMeshPassSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCustomMeshPassSettings.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UCustomMeshPassSettings.OuterSingleton;
}
#undef UHT_STATICS
UCustomMeshPassSettings::UCustomMeshPassSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCustomMeshPassSettings);
UCustomMeshPassSettings::~UCustomMeshPassSettings() {}
// ********** End Class UCustomMeshPassSettings ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h__Script_CustomMeshPass_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCustomMeshPassSettings, TEXT("UCustomMeshPassSettings"), &Z_Registration_Info_UClass_UCustomMeshPassSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomMeshPassSettings), 3234010172U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSettings_h__Script_CustomMeshPass_2100685182ecb87aec0320a2b88a8f04421621de{
	TEXT("/Script/CustomMeshPass"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
