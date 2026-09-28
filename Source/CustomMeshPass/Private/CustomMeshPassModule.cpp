#include "CustomMeshPassModule.h"

#include "CoreGlobals.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/ConfigUtilities.h"
#include "Misc/Paths.h"
#include "ShaderCore.h"

DEFINE_LOG_CATEGORY(LogCustomMeshPass);

#define LOCTEXT_NAMESPACE "FCustomMeshPassModule"

/*
	启动模块：
	1. 获取插件管理器，并检查插件描述符是否有效
	2. 添加着色器源目录映射
	3. 应用 CVar 设置
	4. 记录日志
*/
void FCustomMeshPassModule::StartupModule()
{
	const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("CustomMeshPass"));
	checkf(Plugin.IsValid(), TEXT("CustomMeshPass plugin descriptor not found"));

	const FString ShaderDir = FPaths::Combine(Plugin->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/CustomMeshPass"), ShaderDir);

	// 设置类的 ini 键就是 CVar 名；编辑器里由设置 CDO 同步，打包后只能靠这里在启动时推送
	UE::ConfigUtilities::ApplyCVarSettingsFromIni(
		TEXT("/Script/CustomMeshPass.CustomMeshPassSettings"), *GEngineIni, ECVF_SetByProjectSetting);

	UE_LOG(LogCustomMeshPass, Log, TEXT("CustomMeshPass started, shader dir: %s"), *ShaderDir);
}

void FCustomMeshPassModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FCustomMeshPassModule, CustomMeshPass)
