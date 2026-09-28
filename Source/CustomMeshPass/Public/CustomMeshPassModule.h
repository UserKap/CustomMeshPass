#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

CUSTOMMESHPASS_API DECLARE_LOG_CATEGORY_EXTERN(LogCustomMeshPass, Log, All);

/**
 * 插件模块入口
 * - 注册 Shader 虚拟目录 /Plugin/CustomMeshPass
 * - 把项目设置（DefaultEngine.ini）里的值推送到 r.CustomMeshPass* CVar
 */
class FCustomMeshPassModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
