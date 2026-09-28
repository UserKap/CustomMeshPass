// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomMeshPassComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeCustomMeshPassComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UTexture2D(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_CustomMeshPass(ETypeConstructPhase);
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassComponent(ETypeConstructPhase);
CUSTOMMESHPASS_API UClass* Z_Construct_UClass_UCustomMeshPassComponent(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UCustomMeshPassComponent *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UCustomMeshPassComponent_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
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
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xba\xbf\xe6\x80\xa7\xe9\xa2\x9c\xe8\x89\xb2\xe3\x80\x82\xe6\x9c\x89 BaseMap \xe6\x97\xb6\xe4\xb8\x8e\xe8\xb4\xb4\xe5\x9b\xbe\xe7\x9b\xb8\xe4\xb9\x98\xef\xbc\x9b""BaseMap \xe8\xaf\xb7\xe6\x89\x93\xe5\xbc\x80 sRGB */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xba\xbf\xe6\x80\xa7\xe9\xa2\x9c\xe8\x89\xb2\xe3\x80\x82\xe6\x9c\x89 BaseMap \xe6\x97\xb6\xe4\xb8\x8e\xe8\xb4\xb4\xe5\x9b\xbe\xe7\x9b\xb8\xe4\xb9\x98\xef\xbc\x9b""BaseMap \xe8\xaf\xb7\xe6\x89\x93\xe5\xbc\x80 sRGB" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseMap_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalMap_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\x87\xe7\xba\xbf\xe7\xa9\xba\xe9\x97\xb4\xe6\xb3\x95\xe7\xba\xbf\xe3\x80\x82\xe5\x85\xb3\xe9\x97\xad sRGB\xef\xbc\x9b\xe5\xaf\xbc\xe5\x85\xa5\xe6\x97\xb6\xe7\x9a\x84 Flip Green Channel \xe5\xb7\xb2\xe7\x83\x98\xe7\x84\x99\xe8\xbf\x9b\xe7\xba\xb9\xe7\x90\x86\xef\xbc\x8c\xe7\x9d\x80\xe8\x89\xb2\xe5\x99\xa8\xe4\xb8\x8d\xe5\x86\x8d\xe7\xbf\xbb\xe8\xbd\xac */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\x87\xe7\xba\xbf\xe7\xa9\xba\xe9\x97\xb4\xe6\xb3\x95\xe7\xba\xbf\xe3\x80\x82\xe5\x85\xb3\xe9\x97\xad sRGB\xef\xbc\x9b\xe5\xaf\xbc\xe5\x85\xa5\xe6\x97\xb6\xe7\x9a\x84 Flip Green Channel \xe5\xb7\xb2\xe7\x83\x98\xe7\x84\x99\xe8\xbf\x9b\xe7\xba\xb9\xe7\x90\x86\xef\xbc\x8c\xe7\x9d\x80\xe8\x89\xb2\xe5\x99\xa8\xe4\xb8\x8d\xe5\x86\x8d\xe7\xbf\xbb\xe8\xbd\xac" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalStrength_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb3\x95\xe7\xba\xbf\xe8\xb4\xb4\xe5\x9b\xbe\xe5\xbc\xba\xe5\xba\xa6\xef\xbc\x9a""0 = \xe5\xae\x8c\xe5\x85\xa8\xe5\xb9\xb3\xe9\x9d\xa2\xef\xbc\x8c""1 = \xe5\x8e\x9f\xe5\x9b\xbe\xef\xbc\x8c\xe5\xa4\xa7\xe4\xba\x8e 1 \xe5\x8a\xa0\xe5\xbc\xba\xe5\x87\xb9\xe5\x87\xb8\xe3\x80\x82\xe6\xb2\xa1\xe6\x9c\x89 NormalMap \xe6\x97\xb6\xe6\x97\xa0\xe6\x95\x88 */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb3\x95\xe7\xba\xbf\xe8\xb4\xb4\xe5\x9b\xbe\xe5\xbc\xba\xe5\xba\xa6\xef\xbc\x9a""0 = \xe5\xae\x8c\xe5\x85\xa8\xe5\xb9\xb3\xe9\x9d\xa2\xef\xbc\x8c""1 = \xe5\x8e\x9f\xe5\x9b\xbe\xef\xbc\x8c\xe5\xa4\xa7\xe4\xba\x8e 1 \xe5\x8a\xa0\xe5\xbc\xba\xe5\x87\xb9\xe5\x87\xb8\xe3\x80\x82\xe6\xb2\xa1\xe6\x9c\x89 NormalMap \xe6\x97\xb6\xe6\x97\xa0\xe6\x95\x88" },
#endif
		{ "UIMax", "4" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Metallic_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb2\xa1\xe6\x9c\x89\xe8\xb4\xb4\xe5\x9b\xbe\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82\xe6\x9c\x89 MetallicMap \xe6\x97\xb6\xe8\xa2\xab\xe8\xb4\xb4\xe5\x9b\xbe\xe7\x9a\x84 R \xe9\x80\x9a\xe9\x81\x93\xe6\x9b\xbf\xe6\x8d\xa2 */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb2\xa1\xe6\x9c\x89\xe8\xb4\xb4\xe5\x9b\xbe\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82\xe6\x9c\x89 MetallicMap \xe6\x97\xb6\xe8\xa2\xab\xe8\xb4\xb4\xe5\x9b\xbe\xe7\x9a\x84 R \xe9\x80\x9a\xe9\x81\x93\xe6\x9b\xbf\xe6\x8d\xa2" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MetallicMap_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x85\xb3\xe9\x97\xad sRGB\xef\xbc\x8c\xe4\xbd\xbf\xe7\x94\xa8 R \xe9\x80\x9a\xe9\x81\x93\xe3\x80\x82\xe6\x8c\x87\xe5\xae\x9a\xe5\x90\x8e\xe6\x9b\xbf\xe6\x8d\xa2 Metallic */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x85\xb3\xe9\x97\xad sRGB\xef\xbc\x8c\xe4\xbd\xbf\xe7\x94\xa8 R \xe9\x80\x9a\xe9\x81\x93\xe3\x80\x82\xe6\x8c\x87\xe5\xae\x9a\xe5\x90\x8e\xe6\x9b\xbf\xe6\x8d\xa2 Metallic" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Specular_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\x94\xb5\xe4\xbb\x8b\xe8\xb4\xa8\xe9\xab\x98\xe5\x85\x89\xe5\xbc\xba\xe5\xba\xa6\xef\xbc\x8c\xe9\xbb\x98\xe8\xae\xa4 0.5\xef\xbc\x88""F0 = 0.08 * Specular = 0.04\xef\xbc\x89 */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\x94\xb5\xe4\xbb\x8b\xe8\xb4\xa8\xe9\xab\x98\xe5\x85\x89\xe5\xbc\xba\xe5\xba\xa6\xef\xbc\x8c\xe9\xbb\x98\xe8\xae\xa4 0.5\xef\xbc\x88""F0 = 0.08 * Specular = 0.04\xef\xbc\x89" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Roughness_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0.02" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb2\xa1\xe6\x9c\x89\xe8\xb4\xb4\xe5\x9b\xbe\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82\xe6\x9c\x89 RoughnessMap \xe6\x97\xb6\xe8\xa2\xab\xe8\xb4\xb4\xe5\x9b\xbe\xe7\x9a\x84 R \xe9\x80\x9a\xe9\x81\x93\xe6\x9b\xbf\xe6\x8d\xa2 */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb2\xa1\xe6\x9c\x89\xe8\xb4\xb4\xe5\x9b\xbe\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82\xe6\x9c\x89 RoughnessMap \xe6\x97\xb6\xe8\xa2\xab\xe8\xb4\xb4\xe5\x9b\xbe\xe7\x9a\x84 R \xe9\x80\x9a\xe9\x81\x93\xe6\x9b\xbf\xe6\x8d\xa2" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoughnessMap_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x85\xb3\xe9\x97\xad sRGB\xef\xbc\x8c\xe4\xbd\xbf\xe7\x94\xa8 R \xe9\x80\x9a\xe9\x81\x93\xe3\x80\x82\xe6\x8c\x87\xe5\xae\x9a\xe5\x90\x8e\xe6\x9b\xbf\xe6\x8d\xa2 Roughness */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x85\xb3\xe9\x97\xad sRGB\xef\xbc\x8c\xe4\xbd\xbf\xe7\x94\xa8 R \xe9\x80\x9a\xe9\x81\x93\xe3\x80\x82\xe6\x8c\x87\xe5\xae\x9a\xe5\x90\x8e\xe6\x9b\xbf\xe6\x8d\xa2 Roughness" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmbientOcclusion_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb2\xa1\xe6\x9c\x89\xe8\xb4\xb4\xe5\x9b\xbe\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xef\xbc\x8c\xe9\xbb\x98\xe8\xae\xa4 1\xe3\x80\x82\xe6\x9c\x89 AOMap \xe6\x97\xb6\xe8\xa2\xab\xe8\xb4\xb4\xe5\x9b\xbe\xe7\x9a\x84 R \xe9\x80\x9a\xe9\x81\x93\xe6\x9b\xbf\xe6\x8d\xa2\xe3\x80\x82\xe5\x8f\xaa\xe5\x8e\x8b\xe9\x97\xb4\xe6\x8e\xa5\xe5\x85\x89 */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb2\xa1\xe6\x9c\x89\xe8\xb4\xb4\xe5\x9b\xbe\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xef\xbc\x8c\xe9\xbb\x98\xe8\xae\xa4 1\xe3\x80\x82\xe6\x9c\x89 AOMap \xe6\x97\xb6\xe8\xa2\xab\xe8\xb4\xb4\xe5\x9b\xbe\xe7\x9a\x84 R \xe9\x80\x9a\xe9\x81\x93\xe6\x9b\xbf\xe6\x8d\xa2\xe3\x80\x82\xe5\x8f\xaa\xe5\x8e\x8b\xe9\x97\xb4\xe6\x8e\xa5\xe5\x85\x89" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AOMap_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\x8e\xaf\xe5\xa2\x83\xe5\x85\x89\xe9\x81\xae\xe8\x94\xbd\xef\xbc\x8c\xe5\x85\xb3\xe9\x97\xad sRGB\xef\xbc\x8c\xe4\xbd\xbf\xe7\x94\xa8 R \xe9\x80\x9a\xe9\x81\x93 */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\x8e\xaf\xe5\xa2\x83\xe5\x85\x89\xe9\x81\xae\xe8\x94\xbd\xef\xbc\x8c\xe5\x85\xb3\xe9\x97\xad sRGB\xef\xbc\x8c\xe4\xbd\xbf\xe7\x94\xa8 R \xe9\x80\x9a\xe9\x81\x93" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Emissive_MetaData[] = {
		{ "Category", "CustomMeshPass|Material" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x87\xaa\xe5\x8f\x91\xe5\x85\x89\xef\xbc\x88\xe7\xba\xbf\xe6\x80\xa7\xef\xbc\x89\xe3\x80\x82\xe5\x89\x8d\xe5\x90\x91\xe7\x9b\xb4\xe6\x8e\xa5\xe5\x8a\xa0\xe5\x88\xb0\xe9\xa2\x9c\xe8\x89\xb2\xe4\xb8\x8a\xef\xbc\x9bGBuffer \xe8\xb7\xaf\xe5\xbe\x84\xe4\xbb\xa5\xe5\x8a\xa0\xe6\xb3\x95\xe5\x86\x99\xe5\x85\xa5 SceneColor */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x87\xaa\xe5\x8f\x91\xe5\x85\x89\xef\xbc\x88\xe7\xba\xbf\xe6\x80\xa7\xef\xbc\x89\xe3\x80\x82\xe5\x89\x8d\xe5\x90\x91\xe7\x9b\xb4\xe6\x8e\xa5\xe5\x8a\xa0\xe5\x88\xb0\xe9\xa2\x9c\xe8\x89\xb2\xe4\xb8\x8a\xef\xbc\x9bGBuffer \xe8\xb7\xaf\xe5\xbe\x84\xe4\xbb\xa5\xe5\x8a\xa0\xe6\xb3\x95\xe5\x86\x99\xe5\x85\xa5 SceneColor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UVChannel_MetaData[] = {
		{ "Category", "CustomMeshPass|Material|UV" },
		{ "ClampMax", "7" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x89\x80\xe6\x9c\x89\xe8\xb4\xb4\xe5\x9b\xbe\xe9\x87\x87\xe6\xa0\xb7\xe7\x94\xa8\xe7\x9a\x84\xe7\xbd\x91\xe6\xa0\xbc UV \xe9\x80\x9a\xe9\x81\x93\xef\xbc\x88""0 = UV0\xef\xbc\x89\xe3\x80\x82\xe8\xb6\x85\xe8\xbf\x87\xe7\xbd\x91\xe6\xa0\xbc\xe5\xb7\xb2\xe6\x9c\x89\xe7\x9a\x84\xe9\x80\x9a\xe9\x81\x93\xe6\x95\xb0\xe6\x97\xb6\xe9\x80\x80\xe5\x9b\x9e\xe6\x9c\x80\xe5\x90\x8e\xe4\xb8\x80\xe4\xb8\xaa\xe9\x80\x9a\xe9\x81\x93 */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\x80\xe6\x9c\x89\xe8\xb4\xb4\xe5\x9b\xbe\xe9\x87\x87\xe6\xa0\xb7\xe7\x94\xa8\xe7\x9a\x84\xe7\xbd\x91\xe6\xa0\xbc UV \xe9\x80\x9a\xe9\x81\x93\xef\xbc\x88""0 = UV0\xef\xbc\x89\xe3\x80\x82\xe8\xb6\x85\xe8\xbf\x87\xe7\xbd\x91\xe6\xa0\xbc\xe5\xb7\xb2\xe6\x9c\x89\xe7\x9a\x84\xe9\x80\x9a\xe9\x81\x93\xe6\x95\xb0\xe6\x97\xb6\xe9\x80\x80\xe5\x9b\x9e\xe6\x9c\x80\xe5\x90\x8e\xe4\xb8\x80\xe4\xb8\xaa\xe9\x80\x9a\xe9\x81\x93" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UVTiling_MetaData[] = {
		{ "Category", "CustomMeshPass|Material|UV" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xb4\xb4\xe5\x9b\xbe\xe9\x87\x8d\xe5\xa4\x8d\xe6\xac\xa1\xe6\x95\xb0\xef\xbc\x88Tiling\xef\xbc\x89\xef\xbc\x8c\xe6\x89\x80\xe6\x9c\x89\xe8\xb4\xb4\xe5\x9b\xbe\xe5\x85\xb1\xe7\x94\xa8\xe3\x80\x82UV = MeshUV * UVTiling + UVOffset */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xb4\xb4\xe5\x9b\xbe\xe9\x87\x8d\xe5\xa4\x8d\xe6\xac\xa1\xe6\x95\xb0\xef\xbc\x88Tiling\xef\xbc\x89\xef\xbc\x8c\xe6\x89\x80\xe6\x9c\x89\xe8\xb4\xb4\xe5\x9b\xbe\xe5\x85\xb1\xe7\x94\xa8\xe3\x80\x82UV = MeshUV * UVTiling + UVOffset" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UVOffset_MetaData[] = {
		{ "Category", "CustomMeshPass|Material|UV" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xb4\xb4\xe5\x9b\xbe\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe5\x9c\xa8 Tiling \xe4\xb9\x8b\xe5\x90\x8e\xe5\x8f\xa0\xe5\x8a\xa0 */" },
#endif
		{ "ModuleRelativePath", "Public/CustomMeshPassComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xb4\xb4\xe5\x9b\xbe\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe5\x9c\xa8 Tiling \xe4\xb9\x8b\xe5\x90\x8e\xe5\x8f\xa0\xe5\x8a\xa0" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UCustomMeshPassComponent constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_BaseColor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BaseMap;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NormalMap;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NormalStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Metallic;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MetallicMap;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Specular;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Roughness;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RoughnessMap;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AmbientOcclusion;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AOMap;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Emissive;
	static const UECodeGen_Private::FIntPropertyParams NewProp_UVChannel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UVTiling;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UVOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCustomMeshPassComponent constinit property declarations *******************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomMeshPassComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UCustomMeshPassComponent Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_BaseColor = { "BaseColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, BaseColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseColor_MetaData), NewProp_BaseColor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_BaseMap = { "BaseMap", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, BaseMap), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseMap_MetaData), NewProp_BaseMap_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_NormalMap = { "NormalMap", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, NormalMap), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalMap_MetaData), NewProp_NormalMap_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_NormalStrength = { "NormalStrength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, NormalStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalStrength_MetaData), NewProp_NormalStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Metallic = { "Metallic", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, Metallic), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Metallic_MetaData), NewProp_Metallic_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_MetallicMap = { "MetallicMap", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, MetallicMap), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MetallicMap_MetaData), NewProp_MetallicMap_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Specular = { "Specular", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, Specular), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Specular_MetaData), NewProp_Specular_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Roughness = { "Roughness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, Roughness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Roughness_MetaData), NewProp_Roughness_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_RoughnessMap = { "RoughnessMap", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, RoughnessMap), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoughnessMap_MetaData), NewProp_RoughnessMap_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AmbientOcclusion = { "AmbientOcclusion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, AmbientOcclusion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmbientOcclusion_MetaData), NewProp_AmbientOcclusion_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_AOMap = { "AOMap", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, AOMap), Z_Construct_UClass_UTexture2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AOMap_MetaData), NewProp_AOMap_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Emissive = { "Emissive", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, Emissive), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Emissive_MetaData), NewProp_Emissive_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_UVChannel = { "UVChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, UVChannel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UVChannel_MetaData), NewProp_UVChannel_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_UVTiling = { "UVTiling", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, UVTiling), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UVTiling_MetaData), NewProp_UVTiling_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_UVOffset = { "UVOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMeshPassComponent, UVOffset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UVOffset_MetaData), NewProp_UVOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BaseColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BaseMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NormalMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NormalStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Metallic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MetallicMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Specular,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Roughness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RoughnessMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AmbientOcclusion,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AOMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Emissive,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UVChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UVTiling,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UVOffset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UCustomMeshPassComponent Property Definitions ******************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UStaticMeshComponent,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_CustomMeshPass,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UCustomMeshPassComponent,
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
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UCustomMeshPassComponent;
UClass* Z_Construct_UClass_UCustomMeshPassComponent(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UCustomMeshPassComponent;
		if (!Z_Registration_Info_UClass_UCustomMeshPassComponent.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("CustomMeshPassComponent"),
				Z_Registration_Info_UClass_UCustomMeshPassComponent.InnerSingleton,
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
		return Z_Registration_Info_UClass_UCustomMeshPassComponent.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UCustomMeshPassComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCustomMeshPassComponent.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UCustomMeshPassComponent.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCustomMeshPassComponent);
UCustomMeshPassComponent::~UCustomMeshPassComponent() {}
// ********** End Class UCustomMeshPassComponent ***************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassComponent_h__Script_CustomMeshPass_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCustomMeshPassComponent, TEXT("UCustomMeshPassComponent"), &Z_Registration_Info_UClass_UCustomMeshPassComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomMeshPassComponent), 829596490U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnityProject_Unreal_Learn_Project_Plugins_CustomMeshPass_Source_CustomMeshPass_Public_CustomMeshPassComponent_h__Script_CustomMeshPass_551119e0e40e78a122b03c997cbe2be6f51cbb2b{
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
