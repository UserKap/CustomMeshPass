/*
	CustomMeshPass 网格处理器：
	1. 构造函数：初始化基类，设置渲染状态
	2. 添加网格批次：根据绘制模式，构建命令
	3. 模板函数：构建命令
*/
#include "CustomMeshPassMeshProcessor.h"

#include "MeshPassProcessor.inl"
#include "Materials/Material.h"
#include "MaterialDomain.h"
#include "RHIStaticStates.h"

/*
	构造函数：
	1. 初始化基类
	2. 如果绘制模式为写入 Lumen 半透明 GI 体积，则设置渲染状态
	3. 否则设置渲染状态
*/
FCustomMeshPassMeshProcessor::FCustomMeshPassMeshProcessor(
	const FScene* InScene,
	const FSceneView* InView,
	FMeshPassDrawListContext* InDrawListContext,
	ECustomMeshPassDrawMode InDrawMode)
	: FMeshPassProcessor(EMeshPass::Num, InScene, InView->GetFeatureLevel(), InView, InDrawListContext)
	, DrawMode(InDrawMode)
{
	if (DrawMode == ECustomMeshPassDrawMode::WriteGBufferForLumen)
	{
		// 不写 SceneColor（避免抹成黑）；写 GBufferA/B/C。深度写入，保证与后续光照/遮挡一致
		//RT0 SceneColor
		//RT1 GBufferA WorldNormal
		//RT2 GBufferB Metallic/Specular/Roughness/ShadingModelID
		//RT3 GBufferC BaseColor/AO
		PassDrawRenderState.SetBlendState(
			TStaticBlendState<
				CW_NONE, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero, // RT0 SceneColor
				CW_RGBA, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero, // RT1 GBufferA
				CW_RGBA, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero, // RT2 GBufferB
				CW_RGBA, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero  // RT3 GBufferC
			>::GetRHI());
		//深度写入，保证与后续光照/遮挡一致
		PassDrawRenderState.SetDepthStencilState(
			TStaticDepthStencilState<true, CF_DepthNearOrEqual>::GetRHI());
		PassDrawRenderState.SetDepthStencilAccess(FExclusiveDepthStencil::DepthWrite_StencilWrite);
	}
	else
	{
		PassDrawRenderState.SetBlendState(TStaticBlendState<>::GetRHI());
		// 前向叠画也写深度，才能挡住已在 SceneColor 里、但深度更远的物体
		PassDrawRenderState.SetDepthStencilState(
			TStaticDepthStencilState<true, CF_DepthNearOrEqual>::GetRHI());
		PassDrawRenderState.SetDepthStencilAccess(FExclusiveDepthStencil::DepthWrite_StencilNop);
	}
}

/*
	添加网格批次：
	1. 获取默认材质渲染代理
	2. 遍历材质渲染代理
	3. 构建命令

	meshbatch: 网格批次
	batchelementmask: 批量元素掩码
	primitivesceneproxy: 场景代理
	staticmeshid: 静态网格ID
*/
void FCustomMeshPassMeshProcessor::AddMeshBatch(
	const FMeshBatch& RESTRICT MeshBatch,
	uint64 BatchElementMask,
	const FPrimitiveSceneProxy* RESTRICT PrimitiveSceneProxy,
	int32 StaticMeshId)
{
	const FMaterialRenderProxy* MaterialRenderProxy = UMaterial::GetDefaultMaterial(MD_Surface)->GetRenderProxy();
	// 遍历材质渲染代理
	while (MaterialRenderProxy)
	{
		const FMaterial* Material = MaterialRenderProxy->GetMaterialNoFallback(FeatureLevel);
		if (!Material)
		{
			MaterialRenderProxy = MaterialRenderProxy->GetFallback(FeatureLevel);
			continue;
		}

		// 获取材质着色器类型
		FMaterialShaderTypes ShaderTypes;
		ShaderTypes.AddShaderType<FCustomMeshPassVS>();
		if (DrawMode == ECustomMeshPassDrawMode::WriteGBufferForLumen)
		{
			ShaderTypes.AddShaderType<FCustomMeshPassGBufferPS>();
		}
		else
		{
			ShaderTypes.AddShaderType<FCustomMeshPassForwardPS>();
		}

		FMaterialShaders Shaders;
		if (!Material->TryGetShaders(ShaderTypes, MeshBatch.VertexFactory->GetType(), Shaders))
		{
			// 获取备用材质渲染代理
			MaterialRenderProxy = MaterialRenderProxy->GetFallback(FeatureLevel);
			continue;
		}

		// 初始化并且设置表面参数
		FCustomMeshPassShaderElementData ElementData = CurrentElementData;
		ElementData.InitializeMeshMaterialData(ViewIfDynamicMeshCommand, PrimitiveSceneProxy, MeshBatch, -1, true);

		if (DrawMode == ECustomMeshPassDrawMode::WriteGBufferForLumen)
		{
			BuildCommands<FCustomMeshPassGBufferPS>(
				MeshBatch, BatchElementMask, PrimitiveSceneProxy, *MaterialRenderProxy, *Material, Shaders, ElementData);
		}
		else
		{
			BuildCommands<FCustomMeshPassForwardPS>(
				MeshBatch, BatchElementMask, PrimitiveSceneProxy, *MaterialRenderProxy, *Material, Shaders, ElementData);
		}
		break;
	}
}

/*
	构建命令：
	1. 获取顶点着色器和像素着色器
	2. 计算网格填充模式和裁剪模式
	3. 构建网格绘制命令

	meshbatch: 网格批次
	batchelementmask: 批量元素掩码
	primitivesceneproxy: 场景代理
	materialrenderproxy: 材质渲染代理
	material: 材质
	shaders: 着色器
	elementdata: 表面参数
*/
template<typename PixelShaderType>
void FCustomMeshPassMeshProcessor::BuildCommands(
	const FMeshBatch& MeshBatch,
	uint64 BatchElementMask,
	const FPrimitiveSceneProxy* PrimitiveSceneProxy,
	const FMaterialRenderProxy& MaterialRenderProxy,
	const FMaterial& Material,
	const FMaterialShaders& Shaders,
	const FCustomMeshPassShaderElementData& ElementData)
{
	TMeshProcessorShaders<FCustomMeshPassVS, PixelShaderType> PassShaders;
	Shaders.TryGetVertexShader(PassShaders.VertexShader);
	Shaders.TryGetPixelShader(PassShaders.PixelShader);

	const FMeshDrawingPolicyOverrideSettings OverrideSettings = ComputeMeshOverrideSettings(MeshBatch);
	const ERasterizerFillMode MeshFillMode = ComputeMeshFillMode(Material, OverrideSettings);
	const ERasterizerCullMode MeshCullMode = ComputeMeshCullMode(Material, OverrideSettings);

	// 重写函数：构建网格绘制命令
	/*
		MeshBatch: 网格批次
		BatchElementMask: 批量元素掩码
		PrimitiveSceneProxy: 场景代理
		MaterialRenderProxy: 材质渲染代理
		Material: 材质
		PassDrawRenderState: 渲染状态
		PassShaders: 着色器
		MeshFillMode: 网格填充模式
		MeshCullMode: 网格裁剪模式
		StaticSortKey: 静态排序键
		MeshPassFeatures: 网格传递特性
		ElementData: 表面参数
	*/
	BuildMeshDrawCommands(
		MeshBatch, BatchElementMask, PrimitiveSceneProxy,
		MaterialRenderProxy, Material, PassDrawRenderState, PassShaders,
		MeshFillMode, MeshCullMode,
		CalculateMeshStaticSortKey(PassShaders.VertexShader, PassShaders.PixelShader),
		EMeshPassFeatures::Default, ElementData);
}
