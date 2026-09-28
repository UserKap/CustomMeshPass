#include "CustomMeshPassSettings.h"

#define LOCTEXT_NAMESPACE "CustomMeshPassSettings"

/*
	获取分类名称：
	1. 返回插件分类名称
*/
FName UCustomMeshPassSettings::GetCategoryName() const
{
	return TEXT("Plugins");
}

#if WITH_EDITOR
/*
	获取分类名称：
	1. 返回插件分类名称
*/
FText UCustomMeshPassSettings::GetSectionText() const
{
	return LOCTEXT("SectionText", "Custom Mesh Pass");
}

/*
	获取分类描述：
	1. 返回插件分类描述
*/
FText UCustomMeshPassSettings::GetSectionDescription() const
{
	return LOCTEXT("SectionDescription", "Custom mesh pass: GBuffer (Deferred + Lumen) or forward custom BRDF.");
}
#endif

#undef LOCTEXT_NAMESPACE
