#include "CustomMeshPassCVars.h"

#include "HAL/IConsoleManager.h"
#include "SceneTexturesConfig.h"

namespace
{
	TAutoConsoleVariable<int32> CVarCustomMeshPassEnabled(
		TEXT("r.CustomMeshPass"),
		1,
		TEXT("0 = off, 1 = draw CustomMeshPass components."),
		ECVF_RenderThreadSafe);

	TAutoConsoleVariable<int32> CVarCustomMeshPassLightingPath(
		TEXT("r.CustomMeshPass.LightingPath"),
		1,
		TEXT("0 = forward custom BRDF (PrePostProcess).\n")
		TEXT("1 = write GBuffer after BasePass, lit by engine Deferred + Lumen (falls back to forward without classic GBuffer)."),
		ECVF_RenderThreadSafe);
}

namespace CustomMeshPass::CVars
{
	bool IsEnabled_GameThread()
	{
		return CVarCustomMeshPassEnabled.GetValueOnGameThread() != 0;
	}

	void SetEnabled(bool bEnabled)
	{
		CVarCustomMeshPassEnabled->Set(bEnabled ? 1 : 0, ECVF_SetByCode);
	}

	ECustomMeshPassLightingPath GetLightingPath_GameThread()
	{
		return CVarCustomMeshPassLightingPath.GetValueOnGameThread() != 0
			? ECustomMeshPassLightingPath::DeferredLumen
			: ECustomMeshPassLightingPath::ForwardCustom;
	}

	void SetLightingPath(ECustomMeshPassLightingPath Path)
	{
		CVarCustomMeshPassLightingPath->Set(static_cast<int32>(Path), ECVF_SetByCode);
	}

	ECustomMeshPassRenderPath ResolveRenderPath_RenderThread()
	{
		if (CVarCustomMeshPassEnabled.GetValueOnRenderThread() == 0)
		{
			return ECustomMeshPassRenderPath::Disabled;
		}

		// Substrate 等没有经典 GBuffer 时写不进去，只剩深度会变成黑模，所以回退前向
		const bool bWantsGBuffer = CVarCustomMeshPassLightingPath.GetValueOnRenderThread() != 0;
		return (bWantsGBuffer && FSceneTexturesConfig::Get().bIsUsingGBuffers)
			? ECustomMeshPassRenderPath::DeferredGBuffer
			: ECustomMeshPassRenderPath::Forward;
	}
}
