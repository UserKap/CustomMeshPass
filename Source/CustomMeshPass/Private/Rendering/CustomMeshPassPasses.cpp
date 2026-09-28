#include "CustomMeshPassPasses.h"

#include "CustomMeshPassLumenBridge.h"
#include "CustomMeshPassMeshProcessor.h"

#include "InstanceCulling/InstanceCullingContext.h"
#include "MeshPassProcessor.inl"
#include "PostProcess/PostProcessInputs.h"
#include "PrimitiveSceneProxy.h"
#include "RenderGraphUtils.h"
#include "SceneRendering.h"
#include "SystemTextures.h"

// 定义 GPU 统计名称
DECLARE_GPU_STAT_NAMED(CustomMeshPassGPU, TEXT("CustomMeshPass"));

// 定义 GBuffer 参数结构体
BEGIN_SHADER_PARAMETER_STRUCT(FCustomMeshPassGBufferParameters, )
	SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, View)
	SHADER_PARAMETER_RDG_UNIFORM_BUFFER(FSceneUniformParameters, Scene)
	SHADER_PARAMETER_RDG_UNIFORM_BUFFER(FInstanceCullingGlobalUniforms, InstanceCulling)
	RENDER_TARGET_BINDING_SLOTS()
END_SHADER_PARAMETER_STRUCT()

// 定义 Forward 参数结构体
BEGIN_SHADER_PARAMETER_STRUCT(FCustomMeshPassForwardParameters, )
	SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, View)
	SHADER_PARAMETER_RDG_UNIFORM_BUFFER(FSceneUniformParameters, Scene)
	SHADER_PARAMETER_RDG_UNIFORM_BUFFER(FInstanceCullingGlobalUniforms, InstanceCulling)
	SHADER_PARAMETER_RDG_TEXTURE(Texture3D, LumenVolume0)
	SHADER_PARAMETER_RDG_TEXTURE(Texture3D, LumenVolume1)
	RENDER_TARGET_BINDING_SLOTS()
END_SHADER_PARAMETER_STRUCT()

namespace
{
	/** 与引擎光栅化一致用 FViewInfo::ViewRect；UnscaledViewRect 在 TAA/超分下会错位 → 黑影随相机漂、遮挡错乱 */
	FIntRect GetRasterViewRect(const FSceneView& View)
	{
		return View.bIsViewInfo
			? static_cast<const FViewInfo&>(View).ViewRect
			: View.UnscaledViewRect;
	}

	/*
		绘制动态网格传递：
		1. 设置视口
		2. 绘制动态网格传递
		3. 处理网格批次
		4. 更新材质渲染代理的统一表达式缓存
		5. 添加网格批次
	*/
	void DrawItems(
		FRHICommandListImmediate& RHICmdList,
		const FSceneView& View,
		const TArray<FCustomMeshPassDrawItem>& Items,
		ECustomMeshPassDrawMode Mode,
		const FCustomMeshPassShaderElementData& SharedData,
		const FIntRect& ViewRect)
	{
		// 设置视口
		RHICmdList.SetViewport(
			(float)ViewRect.Min.X, (float)ViewRect.Min.Y, 0.0f,
			(float)ViewRect.Max.X, (float)ViewRect.Max.Y, 1.0f);
		
		//url:https://dev.epicgames.com/documentation/unreal-engine/mesh-drawing-pipeline-in-unreal-engine
		DrawDynamicMeshPass(View, RHICmdList,
			[&View, &Items, &SharedData, Mode](FDynamicPassMeshDrawListContext* DynamicMeshPassContext)
			{
				FCustomMeshPassMeshProcessor Processor(nullptr, &View, DynamicMeshPassContext, Mode);
				for (const FCustomMeshPassDrawItem& Item : Items)
				{
					// 尚未加入场景（或已移出）的 Proxy 没有 GPUScene 数据，画出来位置/深度都不对
					if (!Item.Proxy || !Item.Proxy->GetPrimitiveSceneInfo())
					{
						continue;
					}

					TArray<FMeshBatch> MeshBatches;
					// 获取网格描述
					Item.Proxy->GetMeshDescription(/*LODIndex=*/0, MeshBatches);
					if (MeshBatches.Num() == 0)
					{
						continue;
					}

					// 确保材质的 uniform 表达式缓存已经更新
					MeshBatches[0].MaterialRenderProxy->UpdateUniformExpressionCacheIfNeeded(View.GetFeatureLevel());

					Processor.CurrentElementData = SharedData;
					Processor.CurrentElementData.Surface = Item.Surface;
					Processor.AddMeshBatch(MeshBatches[0], /*BatchElementMask=*/1, Item.Proxy);
				}
			});
	}
}

namespace CustomMeshPass
{
	// 添加 GBuffer 传递
	void AddGBufferPass(
		FRDGBuilder& GraphBuilder,
		const FSceneView& View,
		const FRenderTargetBindingSlots& BasePassRenderTargets,
		const TArray<FCustomMeshPassDrawItem>& Items)
	{
		check(View.bIsViewInfo);
		RDG_EVENT_SCOPE(GraphBuilder, "CustomMeshPass");
		RDG_GPU_STAT_SCOPE(GraphBuilder, CustomMeshPassGPU);

		FCustomMeshPassGBufferParameters* PassParameters = GraphBuilder.AllocParameters<FCustomMeshPassGBufferParameters>();
		PassParameters->View = View.ViewUniformBuffer;
		PassParameters->Scene = GetSceneUniformBufferRef(GraphBuilder, View);
		PassParameters->InstanceCulling = FInstanceCullingContext::CreateDummyInstanceCullingUniformBuffer(GraphBuilder);
		// 复用 BasePass 的 MRT；深度改为可写，保证遮挡与光照重建一致
		PassParameters->RenderTargets = BasePassRenderTargets;
		if (PassParameters->RenderTargets.DepthStencil.GetTexture())
		{
			PassParameters->RenderTargets.DepthStencil = FDepthStencilBinding(
				PassParameters->RenderTargets.DepthStencil.GetTexture(),
				ERenderTargetLoadAction::ELoad,
				ERenderTargetLoadAction::ELoad,
				FExclusiveDepthStencil::DepthWrite_StencilWrite);
		}

		const FIntRect ViewRect = GetRasterViewRect(View);

		GraphBuilder.AddPass(
			RDG_EVENT_NAME("CustomMeshPass_GBuffer %d", Items.Num()),
			PassParameters,
			ERDGPassFlags::Raster,
			[&View, Items, ViewRect](FRHICommandListImmediate& RHICmdList)
			{
				FCustomMeshPassShaderElementData SharedData;
				DrawItems(RHICmdList, View, Items, ECustomMeshPassDrawMode::WriteGBufferForLumen, SharedData, ViewRect);
			});
	}

	// 添加 Forward 传递
	void AddForwardPass(
		FRDGBuilder& GraphBuilder,
		const FSceneView& View,
		const FPostProcessingInputs& Inputs,
		const TArray<FCustomMeshPassDrawItem>& Items)
	{
		Inputs.Validate();

		FRDGTextureRef SceneColorTexture = (*Inputs.SceneTextures)->SceneColorTexture;
		if (!SceneColorTexture)
		{
			return;
		}

		RDG_EVENT_SCOPE(GraphBuilder, "CustomMeshPass");
		RDG_GPU_STAT_SCOPE(GraphBuilder, CustomMeshPassGPU);

		const FRDGSystemTextures& SystemTextures = FRDGSystemTextures::Get(GraphBuilder);
		FRDGTextureRef SceneDepthTexture = HasBeenProduced((*Inputs.SceneTextures)->SceneDepthTexture)
			? (*Inputs.SceneTextures)->SceneDepthTexture
			: SystemTextures.DepthDummy;

		const FCustomMeshPassLumenVolume Lumen = GetLumenTranslucencyGIVolume(GraphBuilder, View);

		FCustomMeshPassForwardParameters* PassParameters = GraphBuilder.AllocParameters<FCustomMeshPassForwardParameters>();
		PassParameters->View = View.ViewUniformBuffer;
		PassParameters->Scene = GetSceneUniformBufferRef(GraphBuilder, View);
		PassParameters->InstanceCulling = FInstanceCullingContext::CreateDummyInstanceCullingUniformBuffer(GraphBuilder);
		PassParameters->LumenVolume0 = Lumen.Volume0;
		PassParameters->LumenVolume1 = Lumen.Volume1;
		PassParameters->RenderTargets[0] = FRenderTargetBinding(SceneColorTexture, ERenderTargetLoadAction::ELoad);
		PassParameters->RenderTargets.DepthStencil = FDepthStencilBinding(
			SceneDepthTexture,
			ERenderTargetLoadAction::ELoad,
			ERenderTargetLoadAction::ELoad,
			FExclusiveDepthStencil::DepthWrite_StencilNop);

		const FIntRect ViewRect = GetRasterViewRect(View);
		const FVector3f GridZParams = Lumen.GridZParams;
		const FIntVector GridSize = Lumen.GridSize;
		const uint32 bLumenValid = Lumen.bValid ? 1u : 0u;

		GraphBuilder.AddPass(
			RDG_EVENT_NAME("CustomMeshPass_Forward %d", Items.Num()),
			PassParameters,
			ERDGPassFlags::Raster,
			[&View, Items, PassParameters, ViewRect, GridZParams, GridSize, bLumenValid](FRHICommandListImmediate& RHICmdList)
			{
				// RDG 纹理的 RHI 资源只在 Pass 执行时才有效
				FCustomMeshPassShaderElementData SharedData;
				SharedData.LumenVolume0 = PassParameters->LumenVolume0->GetRHI();
				SharedData.LumenVolume1 = PassParameters->LumenVolume1->GetRHI();
				SharedData.LumenGridZParams = GridZParams;
				SharedData.LumenGridSize = GridSize;
				SharedData.bLumenValid = bLumenValid;

				DrawItems(RHICmdList, View, Items, ECustomMeshPassDrawMode::ForwardCustomBRDF, SharedData, ViewRect);
			});
	}
}
