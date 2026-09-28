#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettingsBackedByCVars.h"
#include "CustomMeshPassTypes.h"
#include "CustomMeshPassSettings.generated.h"

/**
 * 项目设置 → 插件 → Custom Mesh Pass
 * 每个属性通过 meta=(ConsoleVariable) 与同名 CVar 双向同步，保存在 DefaultEngine.ini
 * 注意：ConsoleVariables.ini 与控制台命令的优先级高于这里
 */
UCLASS(config = Engine, defaultconfig, meta = (DisplayName = "Custom Mesh Pass"))
class CUSTOMMESHPASS_API UCustomMeshPassSettings : public UDeveloperSettingsBackedByCVars
{
	GENERATED_BODY()

public:
	/** 总开关 */
	UPROPERTY(config, EditAnywhere, Category = "Rendering", meta = (ConsoleVariable = "r.CustomMeshPass", DisplayName = "Enabled"))
	bool bEnabled = true;

	/** 光照路径 */
	UPROPERTY(config, EditAnywhere, Category = "Rendering", meta = (ConsoleVariable = "r.CustomMeshPass.LightingPath"))
	ECustomMeshPassLightingPath LightingPath = ECustomMeshPassLightingPath::DeferredLumen;

	virtual FName GetCategoryName() const override;

#if WITH_EDITOR
	virtual FText GetSectionText() const override;
	virtual FText GetSectionDescription() const override;
#endif
};
