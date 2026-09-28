// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomMeshPassSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeCustomMeshPassSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_CustomMeshPass(ETypeConstructPhase);
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassSubsystem(ETypeConstructPhase);
CUSTOMMESHPASS_API UEnum* Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath(ETypeConstructPhase);
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassSubsystem(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UCustomMeshPassSubsystem Function GetLightingPath ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics
struct UHT_STATICS
{
	struct CustomMeshPassSubsystem_eventGetLightingPath_Parms
	{
		ECustomMeshPassLightingPath ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "CustomMeshPass" },
		{ "ModuleRelativePath", "Public/CustomMeshPassSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetLightingPath constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLightingPath constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLightingPath Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMeshPassSubsystem_eventGetLightingPath_Parms, ReturnValue), Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath, METADATA_PARAMS(0, nullptr) }; // 1b9e8a6bb7382aec31ea97c57ab448f524df9152
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetLightingPath Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UCustomMeshPassSubsystem, nullptr, "GetLightingPath", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::CustomMeshPassSubsystem_eventGetLightingPath_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::CustomMeshPassSubsystem_eventGetLightingPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UCustomMeshPassSubsystem::execGetLightingPath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ECustomMeshPassLightingPath*)Z_Param__Result=P_THIS->GetLightingPath();
	P_NATIVE_END;
}
// ********** End Class UCustomMeshPassSubsystem Function GetLightingPath **************************

// ********** Begin Class UCustomMeshPassSubsystem Function GetRegisteredComponentCount ************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics
struct UHT_STATICS
{
	struct CustomMeshPassSubsystem_eventGetRegisteredComponentCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "CustomMeshPass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xbd\x93\xe5\x89\x8d World \xe6\xb3\xa8\xe5\x86\x8c\xe7\x9a\x84\xe7\xbb\x84\xe4\xbb\xb6\xe6\x95\xb0\xef\xbc\x88\xe5\x90\xab\xe9\x9a\x90\xe8\x97\x8f\xe7\x9a\x84\xef\xbc\x89 */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d World \xe6\xb3\xa8\xe5\x86\x8c\xe7\x9a\x84\xe7\xbb\x84\xe4\xbb\xb6\xe6\x95\xb0\xef\xbc\x88\xe5\x90\xab\xe9\x9a\x90\xe8\x97\x8f\xe7\x9a\x84\xef\xbc\x89" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetRegisteredComponentCount constinit property declarations ***********
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetRegisteredComponentCount constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetRegisteredComponentCount Property Definitions **********************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMeshPassSubsystem_eventGetRegisteredComponentCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetRegisteredComponentCount Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UCustomMeshPassSubsystem, nullptr, "GetRegisteredComponentCount", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::CustomMeshPassSubsystem_eventGetRegisteredComponentCount_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::CustomMeshPassSubsystem_eventGetRegisteredComponentCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UCustomMeshPassSubsystem::execGetRegisteredComponentCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetRegisteredComponentCount();
	P_NATIVE_END;
}
// ********** End Class UCustomMeshPassSubsystem Function GetRegisteredComponentCount **************

// ********** Begin Class UCustomMeshPassSubsystem Function IsEnabled ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics
struct UHT_STATICS
{
	struct CustomMeshPassSubsystem_eventIsEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "CustomMeshPass" },
		{ "ModuleRelativePath", "Public/CustomMeshPassSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsEnabled constinit property declarations *****************************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CustomMeshPassSubsystem_eventIsEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsEnabled constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsEnabled Property Definitions ****************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(CustomMeshPassSubsystem_eventIsEnabled_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsEnabled Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UCustomMeshPassSubsystem, nullptr, "IsEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::CustomMeshPassSubsystem_eventIsEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::CustomMeshPassSubsystem_eventIsEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UCustomMeshPassSubsystem::execIsEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsEnabled();
	P_NATIVE_END;
}
// ********** End Class UCustomMeshPassSubsystem Function IsEnabled ********************************

// ********** Begin Class UCustomMeshPassSubsystem Function SetEnabled *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics
struct UHT_STATICS
{
	struct CustomMeshPassSubsystem_eventSetEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "CustomMeshPass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x80\xbb\xe5\xbc\x80\xe5\x85\xb3\xef\xbc\x8c\xe7\xad\x89\xe4\xbb\xb7\xe4\xba\x8e r.CustomMeshPass\xef\xbc\x88\xe4\xbb\xa5 SetByCode \xe4\xbc\x98\xe5\x85\x88\xe7\xba\xa7\xe5\x86\x99\xe5\x85\xa5\xef\xbc\x8c\xe4\xbc\x9a\xe8\xa6\x86\xe7\x9b\x96\xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae\xef\xbc\x89 */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x80\xbb\xe5\xbc\x80\xe5\x85\xb3\xef\xbc\x8c\xe7\xad\x89\xe4\xbb\xb7\xe4\xba\x8e r.CustomMeshPass\xef\xbc\x88\xe4\xbb\xa5 SetByCode \xe4\xbc\x98\xe5\x85\x88\xe7\xba\xa7\xe5\x86\x99\xe5\x85\xa5\xef\xbc\x8c\xe4\xbc\x9a\xe8\xa6\x86\xe7\x9b\x96\xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae\xef\xbc\x89" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetEnabled constinit property declarations ****************************
	static void NewProp_bEnabled_SetBit(void* Obj)
	{
		((CustomMeshPassSubsystem_eventSetEnabled_Parms*)Obj)->bEnabled = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetEnabled constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetEnabled Property Definitions ***************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(CustomMeshPassSubsystem_eventSetEnabled_Parms), &UHT_STATICS::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetEnabled Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UCustomMeshPassSubsystem, nullptr, "SetEnabled", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::CustomMeshPassSubsystem_eventSetEnabled_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::CustomMeshPassSubsystem_eventSetEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UCustomMeshPassSubsystem::execSetEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UCustomMeshPassSubsystem Function SetEnabled *******************************

// ********** Begin Class UCustomMeshPassSubsystem Function SetLightingPath ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics
struct UHT_STATICS
{
	struct CustomMeshPassSubsystem_eventSetLightingPath_Parms
	{
		ECustomMeshPassLightingPath Path;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "CustomMeshPass" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x85\x89\xe7\x85\xa7\xe8\xb7\xaf\xe5\xbe\x84\xef\xbc\x8c\xe7\xad\x89\xe4\xbb\xb7\xe4\xba\x8e r.CustomMeshPass.LightingPath\xef\xbc\x88\xe4\xbb\xa5 SetByCode \xe4\xbc\x98\xe5\x85\x88\xe7\xba\xa7\xe5\x86\x99\xe5\x85\xa5\xef\xbc\x8c\xe4\xbc\x9a\xe8\xa6\x86\xe7\x9b\x96\xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae\xef\xbc\x89 */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x85\x89\xe7\x85\xa7\xe8\xb7\xaf\xe5\xbe\x84\xef\xbc\x8c\xe7\xad\x89\xe4\xbb\xb7\xe4\xba\x8e r.CustomMeshPass.LightingPath\xef\xbc\x88\xe4\xbb\xa5 SetByCode \xe4\xbc\x98\xe5\x85\x88\xe7\xba\xa7\xe5\x86\x99\xe5\x85\xa5\xef\xbc\x8c\xe4\xbc\x9a\xe8\xa6\x86\xe7\x9b\x96\xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae\xef\xbc\x89" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetLightingPath constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Path_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Path;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetLightingPath constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetLightingPath Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Path_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMeshPassSubsystem_eventSetLightingPath_Parms, Path), Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath, METADATA_PARAMS(0, nullptr) }; // 1b9e8a6bb7382aec31ea97c57ab448f524df9152
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Path_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Path,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetLightingPath Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UCustomMeshPassSubsystem, nullptr, "SetLightingPath", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::CustomMeshPassSubsystem_eventSetLightingPath_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::CustomMeshPassSubsystem_eventSetLightingPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UCustomMeshPassSubsystem::execSetLightingPath)
{
	P_GET_ENUM(ECustomMeshPassLightingPath,Z_Param_Path);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLightingPath(ECustomMeshPassLightingPath(Z_Param_Path));
	P_NATIVE_END;
}
// ********** End Class UCustomMeshPassSubsystem Function SetLightingPath **************************

// ********** Begin Class UCustomMeshPassSubsystem *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UCustomMeshPassSubsystem_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * CustomMeshPass \xe7\x9a\x84 WorldSubsystem\xe3\x80\x82\n * WorldSubsystem \xe6\x98\xafUE5\xe4\xb8\xad\xe6\x96\xb0\xe5\xa2\x9e\xe7\x9a\x84\xe7\xb3\xbb\xe7\xbb\x9f\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xae\xa1\xe7\x90\x86\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\xad\xe7\x9a\x84\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe3\x80\x82\n * \xe7\xae\xa1\xe7\x90\x86 CustomMeshPassComponent \xe5\x92\x8c FCustomMeshPassSceneViewExtension\xe3\x80\x82\n * \xe5\x8f\xa6\xe5\xa4\x96\xe5\x90\x91\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe5\xbc\x80\xe5\x85\xb3 / \xe5\x85\x89\xe7\x85\xa7\xe8\xb7\xaf\xe5\xbe\x84\xef\xbc\x88\xe5\xba\x95\xe5\xb1\x82\xe6\x98\xaf\xe5\x85\xa8\xe5\xb1\x80 CVar\xef\xbc\x8c\xe5\xaf\xb9\xe6\x89\x80\xe6\x9c\x89 World \xe7\x94\x9f\xe6\x95\x88\xef\xbc\x89\xe3\x80\x82\n */" },
#endif
		{ "IncludePath", "CustomMeshPassSubsystem.h" },
		{ "ModuleRelativePath", "Public/CustomMeshPassSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CustomMeshPass \xe7\x9a\x84 WorldSubsystem\xe3\x80\x82\nWorldSubsystem \xe6\x98\xafUE5\xe4\xb8\xad\xe6\x96\xb0\xe5\xa2\x9e\xe7\x9a\x84\xe7\xb3\xbb\xe7\xbb\x9f\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xae\xa1\xe7\x90\x86\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\xad\xe7\x9a\x84\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe3\x80\x82\n\xe7\xae\xa1\xe7\x90\x86 CustomMeshPassComponent \xe5\x92\x8c FCustomMeshPassSceneViewExtension\xe3\x80\x82\n\xe5\x8f\xa6\xe5\xa4\x96\xe5\x90\x91\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe5\xbc\x80\xe5\x85\xb3 / \xe5\x85\x89\xe7\x85\xa7\xe8\xb7\xaf\xe5\xbe\x84\xef\xbc\x88\xe5\xba\x95\xe5\xb1\x82\xe6\x98\xaf\xe5\x85\xa8\xe5\xb1\x80 CVar\xef\xbc\x8c\xe5\xaf\xb9\xe6\x89\x80\xe6\x9c\x89 World \xe7\x94\x9f\xe6\x95\x88\xef\xbc\x89\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UCustomMeshPassSubsystem constinit property declarations *****************
// ********** End Class UCustomMeshPassSubsystem constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetLightingPath"), .Pointer = &UCustomMeshPassSubsystem::execGetLightingPath },
		{ .NameUTF8 = UTF8TEXT("GetRegisteredComponentCount"), .Pointer = &UCustomMeshPassSubsystem::execGetRegisteredComponentCount },
		{ .NameUTF8 = UTF8TEXT("IsEnabled"), .Pointer = &UCustomMeshPassSubsystem::execIsEnabled },
		{ .NameUTF8 = UTF8TEXT("SetEnabled"), .Pointer = &UCustomMeshPassSubsystem::execSetEnabled },
		{ .NameUTF8 = UTF8TEXT("SetLightingPath"), .Pointer = &UCustomMeshPassSubsystem::execSetLightingPath },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath, "GetLightingPath" }, // 299ec0085853af0f5b905bc868ff5e0f65efe470
		{ &Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount, "GetRegisteredComponentCount" }, // f3c808c595c9c30c2e75d3f23e967b821fbd4911
		{ &Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled, "IsEnabled" }, // 91578c0fb95ad2492f79e3e7644b81004d4a6b70
		{ &Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled, "SetEnabled" }, // 94a98fc3b71eb6a46f01172f5f1fa1c830b6188e
		{ &Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath, "SetLightingPath" }, // 780bc7bf33ca6d1cbffaf9ed79ac465caed52d0f
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomMeshPassSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UWorldSubsystem,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_CustomMeshPass,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UCustomMeshPassSubsystem,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UCustomMeshPassSubsystem_StaticRegisterNativesUCustomMeshPassSubsystem()
{
	UClass* Class = UCustomMeshPassSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCustomMeshPassSubsystem;
UClass* Z_Construct_UClass_UCustomMeshPassSubsystem(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UCustomMeshPassSubsystem;
		if (!Z_Registration_Info_UClass_UCustomMeshPassSubsystem.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("CustomMeshPassSubsystem"),
				Z_Registration_Info_UClass_UCustomMeshPassSubsystem.InnerSingleton,
				UCustomMeshPassSubsystem_StaticRegisterNativesUCustomMeshPassSubsystem,
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
		return Z_Registration_Info_UClass_UCustomMeshPassSubsystem.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UCustomMeshPassSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCustomMeshPassSubsystem.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UCustomMeshPassSubsystem.OuterSingleton;
}
#undef UHT_STATICS
UCustomMeshPassSubsystem::UCustomMeshPassSubsystem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCustomMeshPassSubsystem);
UCustomMeshPassSubsystem::~UCustomMeshPassSubsystem() {}
// ********** End Class UCustomMeshPassSubsystem ***************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h__Script_CustomMeshPass_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCustomMeshPassSubsystem, TEXT("UCustomMeshPassSubsystem"), &Z_Registration_Info_UClass_UCustomMeshPassSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomMeshPassSubsystem), 206154290U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h__Script_CustomMeshPass_f17b1114080892d3749926954be4ba7dbf9c6fcd{
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
