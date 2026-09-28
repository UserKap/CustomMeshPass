#pragma once

#include "CoreMinimal.h"
#include "RenderGraphResources.h"
#include "ShaderParameterMacros.h"

class FSceneView;

/**
 * 引擎 FForwardLightUniformParameters（SceneRendering.h）的镜像，成员名与顺序必须一致。
 * 引擎那份没有导出，插件既不能放进 RDG Pass 参数，也不能 GetUniformBufferParameter<>；
 * 所以自建一份同布局 UB，Shader 里用 #define ForwardLightStruct CMPForwardLight 复用 LightGridCommon.ush。
 * 升级引擎时要对照 SceneRendering.h 同步。
 */
BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FCustomMeshPassForwardLightParameters, )
	SHADER_PARAMETER(uint32, NumLocalLights)
	SHADER_PARAMETER(uint32, NumDirectionalLights)
	SHADER_PARAMETER(uint32, NumReflectionCaptures)
	SHADER_PARAMETER(uint32, HasDirectionalLight)
	SHADER_PARAMETER(uint32, NumGridCells)
	SHADER_PARAMETER(uint32, LightNameDwords)
	SHADER_PARAMETER(FIntVector, CulledGridSize)
	SHADER_PARAMETER(uint32, MaxCulledLightsPerCell)
	SHADER_PARAMETER(uint32, LightGridPixelSizeShift)
	SHADER_PARAMETER(FVector3f, LightGridZParams)
	SHADER_PARAMETER(FVector3f, DirectionalLightDirection)
	SHADER_PARAMETER(float, DirectionalLightSourceRadius)
	SHADER_PARAMETER(float, DirectionalLightSoftSourceRadius)
	SHADER_PARAMETER(FVector3f, DirectionalLightColor)
	SHADER_PARAMETER(float, DirectionalLightVolumetricScatteringIntensity)
	SHADER_PARAMETER(float, DirectionalLightSpecularScale)
	SHADER_PARAMETER(float, DirectionalLightDiffuseScale)
	SHADER_PARAMETER(uint32, DirectionalLightSceneInfoExtraDataPacked)
	SHADER_PARAMETER(FVector2f, DirectionalLightDistanceFadeMAD)
	SHADER_PARAMETER(int32, DirectionalLightVSM)
	SHADER_PARAMETER(uint32, DirectionalLightHandledByMegaLights)
	SHADER_PARAMETER(uint32, DirectionalMegaLightsSupportedStartIndex)
	SHADER_PARAMETER(uint32, DirectLightingShowFlag)
	SHADER_PARAMETER(uint32, CulledBufferOffsetISR)
	SHADER_PARAMETER(uint32, DirectionalLightLightFunctionAtlasLightIndex)
	SHADER_PARAMETER(uint32, DirectionalLightAffectsTranslucentLighting)
	SHADER_PARAMETER(FVector4f, PreViewTranslationOffsetISR)
	SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<float4>, ForwardLightBuffer)
	SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<uint>, NumCulledLightsGrid)
	SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<uint>, CulledLightDataGrid32Bit)
	SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<uint>, CulledLightDataGrid16Bit)
	SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<uint>, DirectionalLightIndices)
	SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<FLightViewData>, LightViewData)
	SHADER_PARAMETER_RDG_BUFFER_SRV(ByteAddressBuffer, LightNamesBuffer)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

namespace CustomMeshPass
{
	/** 从 FViewInfo::ForwardLightingResources 拷贝本帧的 Light Grid；拿不到时返回 NumLocalLights = 0 的空 UB */
	TRDGUniformBufferRef<FCustomMeshPassForwardLightParameters> CreateForwardLightUniformBuffer(
		FRDGBuilder& GraphBuilder,
		const FSceneView& View);
}
