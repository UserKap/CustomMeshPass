// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomMeshPass/Public/CustomMeshPassComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomMeshPassComponent() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassComponent();
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent();
UPackage* Z_Construct_UPackage__Script_CustomMeshPass();
// End Cross Module References

// Begin Class UCustomMeshPassComponent
void UCustomMeshPassComponent::StaticRegisterNativesUCustomMeshPassComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCustomMeshPassComponent);
UClass* Z_Construct_UClass_UCustomMeshPassComponent_NoRegister()
{
	return UCustomMeshPassComponent::StaticClass();
}
struct Z_Construct_UClass_UCustomMeshPassComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Rendering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xe7\x94\xb1 CustomMeshPass \xe7\xbb\x98\xe5\x88\xb6\xe7\x9a\x84 StaticMeshComponent\xe3\x80\x82\n * bRenderInMainPass=false\xef\xbc\x9a\xe4\xb8\x8d\xe8\xbf\x9b\xe9\xbb\x98\xe8\xae\xa4 Deferred \xe6\x9d\x90\xe8\xb4\xa8\xe5\x85\x89\xe7\x85\xa7\xe3\x80\x82\n * bRenderInDepthPass=true\xef\xbc\x9a\xe5\x86\x99\xe6\xb7\xb1\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\x87\xaa\xe5\xae\x9a\xe4\xb9\x89 Pass / GBuffer \xe5\x86\x99\xe5\x85\xa5\xe5\x81\x9a\xe6\xb7\xb1\xe5\xba\xa6\xe6\xb5\x8b\xe8\xaf\x95\xe3\x80\x82\n *\n * \xe5\x85\x89\xe7\x85\xa7\xe8\xb7\xaf\xe5\xbe\x84\xe5\x9c\xa8 \xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae \xe2\x86\x92 \xe6\x8f\x92\xe4\xbb\xb6 \xe2\x86\x92 Custom Mesh Pass \xe5\x88\x87\xe6\x8d\xa2\xef\xbc\x88\xe7\xad\x89\xe4\xbb\xb7\xe4\xba\x8e\xe6\x8e\xa7\xe5\x88\xb6\xe5\x8f\xb0 r.CustomMeshPass.LightingPath\xef\xbc\x89\xef\xbc\x9a\n * - ForwardCustom (0)\xef\xbc\x9aPrePostProcess \xe8\x87\xaa\xe5\x86\x99 BRDF\n * - DeferredLumen (1)\xef\xbc\x9a\xe5\x86\x99 GBuffer \xe2\x86\x92 Deferred + Lumen\n *\n * \xe6\x9d\x90\xe8\xb4\xa8\xe6\xa7\xbd\xe4\xbb\x8d\xe8\xa2\xab DepthPass / \xe9\x98\xb4\xe5\xbd\xb1 / \xe6\x8b\xbe\xe5\x8f\x96\xe4\xbd\xbf\xe7\x94\xa8\xef\xbc\x8c\xe8\xaf\xb7\xe4\xbf\x9d\xe6\x8c\x81\xe4\xb8\x8d\xe9\x80\x8f\xe6\x98\x8e\xe3\x80\x81\xe6\x97\xa0 WPO \xe7\x9a\x84\xe6\x9d\x90\xe8\xb4\xa8\xef\xbc\x8c\xe5\x90\xa6\xe5\x88\x99\xe6\xb7\xb1\xe5\xba\xa6\xe4\xbc\x9a\xe4\xb8\x8e\xe6\x9c\xac Pass \xe4\xb8\x8d\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82\n */" },
#endif
		{ "HideCategories", "Object Activation Components|Activation Trigger" },
		{ "IncludePath", "CustomMeshPassComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\x94\xb1 CustomMeshPass \xe7\xbb\x98\xe5\x88\xb6\xe7\x9a\x84 StaticMeshComponent\xe3\x80\x82\nbRenderInMainPass=false\xef\xbc\x9a\xe4\xb8\x8d\xe8\xbf\x9b\xe9\xbb\x98\xe8\xae\xa4 Deferred \xe6\x9d\x90\xe8\xb4\xa8\xe5\x85\x89\xe7\x85\xa7\xe3\x80\x82\nbRenderInDepthPass=true\xef\xbc\x9a\xe5\x86\x99\xe6\xb7\xb1\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\x87\xaa\xe5\xae\x9a\xe4\xb9\x89 Pass / GBuffer \xe5\x86\x99\xe5\x85\xa5\xe5\x81\x9a\xe6\xb7\xb1\xe5\xba\xa6\xe6\xb5\x8b\xe8\xaf\x95\xe3\x80\x82\n\n\xe5\x85\x89\xe7\x85\xa7\xe8\xb7\xaf\xe5\xbe\x84\xe5\x9c\xa8 \xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae \xe2\x86\x92 \xe6\x8f\x92\xe4\xbb\xb6 \xe2\x86\x92 Custom Mesh Pass \xe5\x88\x87\xe6\x8d\xa2\xef\xbc\x88\xe7\xad\x89\xe4\xbb\xb7\xe4\xba\x8e\xe6\x8e\xa7\xe5\x88\xb6\xe5\x8f\xb0 r.CustomMeshPass.LightingPath\xef\xbc\x89\xef\xbc\x9a\n- ForwardCustom (0)\xef\xbc\x9aPrePostProcess \xe8\x87\xaa\xe5\x86\x99 BRDF\n- DeferredLumen (1)\xef\xbc\x9a\xe5\x86\x99 GBuffer \xe2\x86\x92 Deferred + Lumen\n\n\xe6\x9d\x90\xe8\xb4\xa8\xe6\xa7\xbd\xe4\xbb\x8d\xe8\xa2\xab DepthPass / \xe9\x98\xb4\xe5\xbd\xb1 / \xe6\x8b\xbe\xe5\x8f\x96\xe4\xbd\xbf\xe7\x94\xa8\xef\xbc\x8c\xe8\xaf\xb7\xe4\xbf\x9d\xe6\x8c\x81\xe4\xb8\x8d\xe9\x80\x8f\xe6\x98\x8e\xe3\x80\x81\xe6\x97\xa0 WPO \xe7\x9a\x84\xe6\x9d\x90\xe8\xb4\xa8\xef\xbc\x8c\xe5\x90\xa6\xe5\x88\x99\xe6\xb7\xb1\xe5\xba\xa6\xe4\xbc\x9a\xe4\xb8\x8e\xe6\x9c\xac Pass \xe4\xb8\x8d\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseColor_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Metallic_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Roughness_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0.02" },
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_BaseColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Metallic;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Roughness;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomMeshPassComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCustomMeshPassComponent_Statics::NewProp_BaseColor = { "BaseColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, BaseColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseColor_MetaData), NewProp_BaseColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMeshPassComponent_Statics::NewProp_Metallic = { "Metallic", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, Metallic), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Metallic_MetaData), NewProp_Metallic_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMeshPassComponent_Statics::NewProp_Roughness = { "Roughness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, Roughness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Roughness_MetaData), NewProp_Roughness_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCustomMeshPassComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMeshPassComponent_Statics::NewProp_BaseColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMeshPassComponent_Statics::NewProp_Metallic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMeshPassComponent_Statics::NewProp_Roughness,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMeshPassComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCustomMeshPassComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStaticMeshComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_CustomMeshPass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMeshPassComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCustomMeshPassComponent_Statics::ClassParams = {
	&UCustomMeshPassComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCustomMeshPassComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMeshPassComponent_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMeshPassComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCustomMeshPassComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCustomMeshPassComponent()
{
	if (!Z_Registration_Info_UClass_UCustomMeshPassComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCustomMeshPassComponent.OuterSingleton, Z_Construct_UClass_UCustomMeshPassComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCustomMeshPassComponent.OuterSingleton;
}
template<> CUSTOMMESHPASS_API UClass* StaticClass<UCustomMeshPassComponent>()
{
	return UCustomMeshPassComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomMeshPassComponent);
UCustomMeshPassComponent::~UCustomMeshPassComponent() {}
// End Class UCustomMeshPassComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCustomMeshPassComponent, UCustomMeshPassComponent::StaticClass, TEXT("UCustomMeshPassComponent"), &Z_Registration_Info_UClass_UCustomMeshPassComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomMeshPassComponent), 2639854632U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassComponent_h_1865158468(TEXT("/Script/CustomMeshPass"),
	Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
