// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomMeshPassActor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeCustomMeshPassActor() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_CustomMeshPass(ETypeConstructPhase);
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_ACustomMeshPassActor(ETypeConstructPhase);
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_ACustomMeshPassActor(ETypeConstructPhase);
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassComponent(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class ACustomMeshPassActor *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ACustomMeshPassActor_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
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

// ********** Begin Class ACustomMeshPassActor constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ACustomMeshPassActor constinit property declarations ***********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACustomMeshPassActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ACustomMeshPassActor Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(ACustomMeshPassActor, MeshComponent), Z_Construct_UClass_UCustomMeshPassComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshComponent_MetaData), NewProp_MeshComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MeshComponent,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ACustomMeshPassActor Property Definitions **********************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_CustomMeshPass,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ACustomMeshPassActor,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_ACustomMeshPassActor;
UClass* Z_Construct_UClass_ACustomMeshPassActor(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ACustomMeshPassActor;
		if (!Z_Registration_Info_UClass_ACustomMeshPassActor.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("CustomMeshPassActor"),
				Z_Registration_Info_UClass_ACustomMeshPassActor.InnerSingleton,
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
		return Z_Registration_Info_UClass_ACustomMeshPassActor.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ACustomMeshPassActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACustomMeshPassActor.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ACustomMeshPassActor.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ACustomMeshPassActor);
ACustomMeshPassActor::~ACustomMeshPassActor() {}
// ********** End Class ACustomMeshPassActor *******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassActor_h__Script_CustomMeshPass_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACustomMeshPassActor, TEXT("ACustomMeshPassActor"), &Z_Registration_Info_UClass_ACustomMeshPassActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACustomMeshPassActor), 3222109288U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassActor_h__Script_CustomMeshPass_0d0da85eb9fc5a5990ee22bb8c9ececb7cdc9217{
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
