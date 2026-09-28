using UnrealBuildTool;
using System.IO;

public class CustomMeshPass : ModuleRules
{
	public CustomMeshPass(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		// 公开头文件只暴露组件 / Actor / 子系统 / 设置，渲染依赖全部放到 Private
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"DeveloperSettings"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"RenderCore",
			"RHI",
			"Renderer",
			"Projects"
		});

		// FViewInfo / SceneTextures / MeshPassProcessor / Lumen 等渲染器私有头
		var EngineDir = Path.GetFullPath(Target.RelativeEnginePath);
		PrivateIncludePaths.AddRange(new string[]
		{
			Path.Combine(EngineDir, "Source/Runtime/Renderer/Private"),
			Path.Combine(EngineDir, "Source/Runtime/Renderer/Internal")
		});
	}
}
