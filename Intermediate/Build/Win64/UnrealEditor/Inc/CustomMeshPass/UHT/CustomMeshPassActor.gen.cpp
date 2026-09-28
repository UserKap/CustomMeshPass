// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomMeshPass/Public/CustomMeshPassActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomMeshPassActor() {}

// Begin Cross Module References
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_ACustomMeshPassActor();
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_ACustomMeshPassActor_NoRegister();
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_CustomMeshPass();
// End Cross Module References

// Begin Class ACustomMeshPassActor
void ACustomMeshPassActor::StaticRegisterNativesACustomMeshPassActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACustomMeshPassActor);
UClass* Z_Construct_UClass_ACustomMeshPassActor_NoRegister()
{
	return ACustomMeshPassActor::StaticClass();
}
struct Z_Construct_UClass_ACustomMeshPassActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8b\x96\xe8\xbf\x9b\xe5\x85\xb3\xe5\x8d\xa1\xe5\x8d\xb3\xe5\x8f\xaf\xef\xbc\x9a\xe5\xb8\xa6\xe8\x87\xaa\xe5\xae\x9a\xe4\xb9\x89 Mesh Pass \xe7\x9a\x84 StaticMesh Actor */" },
#endif
		{ "IncludePath", "CustomMeshPassActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/CustomMeshPassActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8b\x96\xe8\xbf\x9b\xe5\x85\xb3\xe5\x8d\xa1\xe5\x8d\xb3\xe5\x8f\xaf\xef\xbc\x9a\xe5\xb8\xa6\xe8\x87\xaa\xe5\xae\x9a\xe4\xb9\x89 Mesh Pass \xe7\x9a\x84 StaticMesh Actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[] = {
		{ "Category", "CustomMeshPass" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CustomMeshPassActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACustomMeshPassActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACustomMeshPassActor_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACustomMeshPassActor, MeshComponent), Z_Construct_UClass_UCustomMeshPassComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshComponent_MetaData), NewProp_MeshComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACustomMeshPassActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACustomMeshPassActor_Statics::NewProp_MeshComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACustomMeshPassActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACustomMeshPassActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_CustomMeshPass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACustomMeshPassActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACustomMeshPassActor_Statics::ClassParams = {
	&ACustomMeshPassActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ACustomMeshPassActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ACustomMeshPassActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACustomMeshPassActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ACustomMeshPassActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACustomMeshPassActor()
{
	if (!Z_Registration_Info_UClass_ACustomMeshPassActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACustomMeshPassActor.OuterSingleton, Z_Construct_UClass_ACustomMeshPassActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACustomMeshPassActor.OuterSingleton;
}
template<> CUSTOMMESHPASS_API UClass* StaticClass<ACustomMeshPassActor>()
{
	return ACustomMeshPassActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACustomMeshPassActor);
ACustomMeshPassActor::~ACustomMeshPassActor() {}
// End Class ACustomMeshPassActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACustomMeshPassActor, ACustomMeshPassActor::StaticClass, TEXT("ACustomMeshPassActor"), &Z_Registration_Info_UClass_ACustomMeshPassActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACustomMeshPassActor), 2491001230U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassActor_h_1426869742(TEXT("/Script/CustomMeshPass"),
	Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
