// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomMeshPass/Public/CustomMeshPassSubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomMeshPassSubsystem() {}

// Begin Cross Module References
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassSubsystem();
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassSubsystem_NoRegister();
CUSTOMMESHPASS_API UEnum* Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
UPackage* Z_Construct_UPackage__Script_CustomMeshPass();
// End Cross Module References

// Begin Class UCustomMeshPassSubsystem Function GetLightingPath
struct Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics
{
	struct CustomMeshPassSubsystem_eventGetLightingPath_Parms
	{
		ECustomMeshPassLightingPath ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CustomMeshPass" },
		{ "ModuleRelativePath", "Public/CustomMeshPassSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMeshPassSubsystem_eventGetLightingPath_Parms, ReturnValue), Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath, METADATA_PARAMS(0, nullptr) }; // 187488240
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMeshPassSubsystem, nullptr, "GetLightingPath", nullptr, nullptr, Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::CustomMeshPassSubsystem_eventGetLightingPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::CustomMeshPassSubsystem_eventGetLightingPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMeshPassSubsystem::execGetLightingPath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ECustomMeshPassLightingPath*)Z_Param__Result=P_THIS->GetLightingPath();
	P_NATIVE_END;
}
// End Class UCustomMeshPassSubsystem Function GetLightingPath

// Begin Class UCustomMeshPassSubsystem Function GetRegisteredComponentCount
struct Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics
{
	struct CustomMeshPassSubsystem_eventGetRegisteredComponentCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMeshPassSubsystem_eventGetRegisteredComponentCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMeshPassSubsystem, nullptr, "GetRegisteredComponentCount", nullptr, nullptr, Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::CustomMeshPassSubsystem_eventGetRegisteredComponentCount_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::CustomMeshPassSubsystem_eventGetRegisteredComponentCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMeshPassSubsystem::execGetRegisteredComponentCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetRegisteredComponentCount();
	P_NATIVE_END;
}
// End Class UCustomMeshPassSubsystem Function GetRegisteredComponentCount

// Begin Class UCustomMeshPassSubsystem Function IsEnabled
struct Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics
{
	struct CustomMeshPassSubsystem_eventIsEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CustomMeshPass" },
		{ "ModuleRelativePath", "Public/CustomMeshPassSubsystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CustomMeshPassSubsystem_eventIsEnabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CustomMeshPassSubsystem_eventIsEnabled_Parms), &Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMeshPassSubsystem, nullptr, "IsEnabled", nullptr, nullptr, Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::CustomMeshPassSubsystem_eventIsEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::CustomMeshPassSubsystem_eventIsEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMeshPassSubsystem::execIsEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsEnabled();
	P_NATIVE_END;
}
// End Class UCustomMeshPassSubsystem Function IsEnabled

// Begin Class UCustomMeshPassSubsystem Function SetEnabled
struct Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics
{
	struct CustomMeshPassSubsystem_eventSetEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((CustomMeshPassSubsystem_eventSetEnabled_Parms*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CustomMeshPassSubsystem_eventSetEnabled_Parms), &Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMeshPassSubsystem, nullptr, "SetEnabled", nullptr, nullptr, Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::CustomMeshPassSubsystem_eventSetEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::CustomMeshPassSubsystem_eventSetEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMeshPassSubsystem::execSetEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// End Class UCustomMeshPassSubsystem Function SetEnabled

// Begin Class UCustomMeshPassSubsystem Function SetLightingPath
struct Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics
{
	struct CustomMeshPassSubsystem_eventSetLightingPath_Parms
	{
		ECustomMeshPassLightingPath Path;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FBytePropertyParams NewProp_Path_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Path;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::NewProp_Path_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMeshPassSubsystem_eventSetLightingPath_Parms, Path), Z_Construct_UEnum_CustomMeshPass_ECustomMeshPassLightingPath, METADATA_PARAMS(0, nullptr) }; // 187488240
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::NewProp_Path_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::NewProp_Path,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMeshPassSubsystem, nullptr, "SetLightingPath", nullptr, nullptr, Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::CustomMeshPassSubsystem_eventSetLightingPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::CustomMeshPassSubsystem_eventSetLightingPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCustomMeshPassSubsystem::execSetLightingPath)
{
	P_GET_ENUM(ECustomMeshPassLightingPath,Z_Param_Path);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLightingPath(ECustomMeshPassLightingPath(Z_Param_Path));
	P_NATIVE_END;
}
// End Class UCustomMeshPassSubsystem Function SetLightingPath

// Begin Class UCustomMeshPassSubsystem
void UCustomMeshPassSubsystem::StaticRegisterNativesUCustomMeshPassSubsystem()
{
	UClass* Class = UCustomMeshPassSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetLightingPath", &UCustomMeshPassSubsystem::execGetLightingPath },
		{ "GetRegisteredComponentCount", &UCustomMeshPassSubsystem::execGetRegisteredComponentCount },
		{ "IsEnabled", &UCustomMeshPassSubsystem::execIsEnabled },
		{ "SetEnabled", &UCustomMeshPassSubsystem::execSetEnabled },
		{ "SetLightingPath", &UCustomMeshPassSubsystem::execSetLightingPath },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCustomMeshPassSubsystem);
UClass* Z_Construct_UClass_UCustomMeshPassSubsystem_NoRegister()
{
	return UCustomMeshPassSubsystem::StaticClass();
}
struct Z_Construct_UClass_UCustomMeshPassSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
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
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCustomMeshPassSubsystem_GetLightingPath, "GetLightingPath" }, // 2183390535
		{ &Z_Construct_UFunction_UCustomMeshPassSubsystem_GetRegisteredComponentCount, "GetRegisteredComponentCount" }, // 609971616
		{ &Z_Construct_UFunction_UCustomMeshPassSubsystem_IsEnabled, "IsEnabled" }, // 2301788391
		{ &Z_Construct_UFunction_UCustomMeshPassSubsystem_SetEnabled, "SetEnabled" }, // 3821585231
		{ &Z_Construct_UFunction_UCustomMeshPassSubsystem_SetLightingPath, "SetLightingPath" }, // 3036627027
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomMeshPassSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCustomMeshPassSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_CustomMeshPass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMeshPassSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCustomMeshPassSubsystem_Statics::ClassParams = {
	&UCustomMeshPassSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMeshPassSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UCustomMeshPassSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCustomMeshPassSubsystem()
{
	if (!Z_Registration_Info_UClass_UCustomMeshPassSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCustomMeshPassSubsystem.OuterSingleton, Z_Construct_UClass_UCustomMeshPassSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCustomMeshPassSubsystem.OuterSingleton;
}
template<> CUSTOMMESHPASS_API UClass* StaticClass<UCustomMeshPassSubsystem>()
{
	return UCustomMeshPassSubsystem::StaticClass();
}
UCustomMeshPassSubsystem::UCustomMeshPassSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomMeshPassSubsystem);
UCustomMeshPassSubsystem::~UCustomMeshPassSubsystem() {}
// End Class UCustomMeshPassSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCustomMeshPassSubsystem, UCustomMeshPassSubsystem::StaticClass, TEXT("UCustomMeshPassSubsystem"), &Z_Registration_Info_UClass_UCustomMeshPassSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomMeshPassSubsystem), 3996790776U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_1269091053(TEXT("/Script/CustomMeshPass"),
	Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Learn_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
