/*
	获取 Lumen 半透明 GI 体积：
	1. 获取系统纹理
	2. 初始化结果
	3. 如果视图不是视图信息，则返回结果
	4. 获取 Lumen 半透明 GI 体积
	5. 如果 Lumen 半透明 GI 体积有效，则设置结果
	6. 返回结果
*/
#include "CustomMeshPassLumenBridge.h"

#include "Lumen/LumenTranslucencyVolumeLighting.h"
#include "SceneRendering.h"
#include "SystemTextures.h"

namespace CustomMeshPass
{
	FCustomMeshPassLumenVolume GetLumenTranslucencyGIVolume(FRDGBuilder& GraphBuilder, const FSceneView& View)
	{
		const FRDGSystemTextures& SystemTextures = FRDGSystemTextures::Get(GraphBuilder);

		FCustomMeshPassLumenVolume Result;
		Result.Volume0 = SystemTextures.VolumetricBlack;
		Result.Volume1 = SystemTextures.VolumetricBlack;

		if (!View.bIsViewInfo)
		{
			return Result;
		}

		// GetOwnLumenTranslucencyGIVolume 不是 const，但这里只读
		FViewInfo& ViewInfo = const_cast<FViewInfo&>(static_cast<const FViewInfo&>(View));
		const FLumenTranslucencyGIVolume& LumenGI = ViewInfo.GetOwnLumenTranslucencyGIVolume();
		if (LumenGI.HistoryTexture0 && LumenGI.HistoryTexture1 && LumenGI.GridSize.Z > 0)
		{
			Result.Volume0 = LumenGI.HistoryTexture0;
			Result.Volume1 = LumenGI.HistoryTexture1;
			Result.GridZParams = (FVector3f)LumenGI.GridZParams;
			Result.GridSize = LumenGI.GridSize;
			Result.bValid = true;
		}
		return Result;
	}
}
