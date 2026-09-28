# CustomMeshPass — 对照阅读脚本（ScriptReadme）

> 用途：按章节打开对应文件，边看边理解「UE 自定义 Mesh Pass」以及「一个正式插件该怎么分层」。  
> 建议顺序按「推荐阅读顺序」走，每节先看「知识点」，再看「代码在哪」，最后看「逐段解读」。

---

## 0. 本插件要解决什么问题

从 Unity 的「自己写个 Pass 画网格」迁到 UE 时，常见误区是：

- 只写 GlobalShader / Compute，画不出带顶点工厂的 StaticMesh  
- 或改材质蓝图，学不到引擎 Mesh Pass / GBuffer / Lumen 挂点  

**本插件目标：**

1. 物体**不进默认 BasePass 材质光照**（`bRenderInMainPass=false`）  
2. 用 **SceneViewExtension** 在正确帧钩子上，用 **MeshMaterialShader + MeshPassProcessor** 画 StaticMesh  
3. 两条光照路径可切换：  
   - **写 GBuffer** → 交给引擎 Deferred + 不透明 Lumen  
   - **前向自写 BRDF** → 完全自己算光（可采半透明 Lumen Volume / SkySH）  
4. 以正式插件的形式交付：项目设置页、蓝图 API、独立日志、GPU Stat、公开/私有分层

---

## 1. 和 Unity 对照（先建立坐标）

| Unity | 本插件 |
|---|---|
| Scriptable Render Feature | `FSceneViewExtension` |
| `CommandBuffer.DrawMesh` + Shader | `DrawDynamicMeshPass` + `FMeshPassProcessor` |
| MaterialPropertyBlock | `FCustomMeshPassShaderElementData` |
| 关掉物体进默认管线 | `bRenderInMainPass=false` |
| 写 GBuffer 再 Lit | `PostRenderBasePassDeferred` |
| 后处理前叠画 | `PrePostProcessPass` |
| Render Pipeline Asset 上的开关 | `UCustomMeshPassSettings`（项目设置页） |

UE 多了一层固定骨架：**Shader 类型 → Processor 填 DrawCommand → RDG Pass 绑 RT**。

---

## 2. 架构分层

```
┌────────────────────────── Public（对外 API，只依赖 Engine / DeveloperSettings）──────────────────────────┐
│  CustomMeshPassModule.h     模块 + LogCustomMeshPass                                                      │
│  CustomMeshPassTypes.h      ECustomMeshPassLightingPath（蓝图枚举）、FCustomMeshPassSurface（表面参数）       │
│  CustomMeshPassSettings.h   项目设置页，属性 ⇄ CVar 双向同步                                              │
│  CustomMeshPassSubsystem.h  World 级管家 + 蓝图 API                                                     │
│  CustomMeshPassComponent.h  自定义 StaticMesh 组件                                                      │
│  CustomMeshPassActor.h      拖进关卡用的 Actor                                                          │
└────────────────────────────────────────────────────────────────────────────────────────────────────────┘
┌────────────────────────── Private（实现细节，可随意改，不影响使用者）─────────────────────────────────────┐
│  CustomMeshPassCVars.*      CVar 定义 + 唯一访问入口 + 渲染路径决策                                         │
│  Rendering/                                                                                            │
│    CustomMeshPassSceneViewExtension.*   什么时候画：收集 → 分派                                            │
│    CustomMeshPassPasses.*               怎么建 RDG Pass：绑 RT / Viewport / GPU Stat                       │
│    CustomMeshPassMeshProcessor.*        怎么生成 DrawCommand：RenderState / 选 Shader                      │
│    CustomMeshPassShaders.*              Shader 类型 + 参数绑定                                            │
│    CustomMeshPassLumenBridge.*          唯一碰 Lumen 私有头的地方                                         │
│    CustomMeshPassDrawItem.h             游戏线程 → 渲染线程的数据                                          │
└────────────────────────────────────────────────────────────────────────────────────────────────────────┘
```

**分层原则：**

- **Public 头不出现任何渲染器类型**。使用者（你的游戏模块）只 include 组件 / 子系统 / 设置，不会被迫依赖 `Renderer` 私有头。所以 `Build.cs` 里 `RenderCore/RHI/Renderer/Projects` 都放在 **Private** 依赖。  
- **每个文件只回答一个问题**：什么时候画（Extension）、怎么建 Pass（Passes）、怎么生成命令（Processor）、Shader 长什么样（Shaders）。  
- **引擎私有 API 集中隔离**：Lumen 体积读取只在 `LumenBridge.cpp`，引擎升级时只改一处。  
- **CVar 只有一个入口**：设置页、蓝图、渲染代码都通过 `CustomMeshPass::CVars::*`，不直接碰 `TAutoConsoleVariable`。

### 2.1 目录

```
Plugins/CustomMeshPass/
├── CustomMeshPass.uplugin
├── README.md / ScriptReadme.md
├── Shaders/Private/
│   ├── CustomMeshPassCommon.ush      # VS→PS 结构、像素参数重建、法线翻转
│   ├── CustomMeshPassBRDF.ush        # Lambert + GGX
│   ├── CustomMeshPassIndirect.ush    # 天光 SH + Lumen 半透明体积采样
│   ├── CustomMeshPassVertex.usf      # MainVS（两路径共用）
│   ├── CustomMeshPassForward.usf     # MainPS：自写光照
│   └── CustomMeshPassGBuffer.usf     # MainPS：EncodeGBuffer
└── Source/CustomMeshPass/
    ├── CustomMeshPass.Build.cs
    ├── Public/    (见上图)
    └── Private/
        ├── CustomMeshPassModule.cpp
        ├── CustomMeshPassSettings.cpp
        ├── CustomMeshPassCVars.h/.cpp
        ├── CustomMeshPassSubsystem.cpp
        ├── CustomMeshPassComponent.cpp
        ├── CustomMeshPassActor.cpp
        └── Rendering/ (见上图)
```

### 2.2 运行时对象关系

```
ACustomMeshPassActor
  └─ UCustomMeshPassComponent ──OnRegister──► UCustomMeshPassSubsystem
                                                        ├─ Components[]
                                                        └─ FCustomMeshPassSceneViewExtension
                                                               │
                                     BeginRenderViewFamily：ForEachDrawableComponent → DrawItems
                                                               │ ENQUEUE_RENDER_COMMAND
                                                               ▼
                                              DrawItems_RenderThread
                                                               │
                                     CVars::ResolveRenderPath_RenderThread()
                              ┌────────────────────────────────┴───────────────────────────┐
                        DeferredGBuffer                                                Forward
              PostRenderBasePassDeferred                                        PrePostProcessPass
              Passes::AddGBufferPass                                            Passes::AddForwardPass
                              └──────────────── DrawItems() ───────────────────────────────┘
                                                DrawDynamicMeshPass
                                                FCustomMeshPassMeshProcessor
                                                VS + (GBufferPS | ForwardPS)
```

---

## 3. 推荐阅读顺序

| 步 | 文件 | 你应带走的一句话 |
|---|---|---|
| 1 | `CustomMeshPassModule.*` | 着色器虚拟路径怎么挂上；打包后设置怎么推给 CVar |
| 2 | `CustomMeshPassTypes.h` | 蓝图枚举 vs 纯 C++ 结构体 |
| 3 | `CustomMeshPassCVars.*` + `CustomMeshPassSettings.*` | CVar 与项目设置页如何双向同步 |
| 4 | `CustomMeshPassActor.*` | Actor 只是容器，真正干活的是 Component |
| 5 | `CustomMeshPassComponent.*` | 为何关 MainPass、如何报名给 Subsystem |
| 6 | `CustomMeshPassSubsystem.*` | World 级生命周期 + 创建 Extension + 蓝图 API |
| 7 | `Rendering/CustomMeshPassSceneViewExtension.*` | 在哪一帧收集、在哪个钩子分派 |
| 8 | `Rendering/CustomMeshPassPasses.*` | RDG Pass：RT 绑定、ViewRect、GPU Stat |
| 9 | `Rendering/CustomMeshPassMeshProcessor.*` | RenderState / 选 Shader / BuildMeshDrawCommands |
| 10 | `Rendering/CustomMeshPassShaders.*` | MeshMaterialShader 与参数绑定 |
| 11 | `Rendering/CustomMeshPassLumenBridge.*` | 如何隔离引擎私有 API |
| 12 | `Shaders/Private/*` | 公共 ush + 三个入口 usf |
| 13 | `Build.cs` + `.uplugin` | 依赖分层与私有头路径 |

---

## 4. 知识点清单（可当复习卡）

### 4.1 UE 对象 / 线程

- **`UCLASS` + `GENERATED_BODY()`**：生成 `Super`（父类别名）、反射等  
- **`CUSTOMMESHPASS_API`**：导出宏。别的模块要用这个类（继承、调用函数）就必须有；正式插件的公开类都加上  
- **游戏线程 vs 渲染线程**：Component/Subsystem 在游戏线程；真正画在 Extension 的 `*_RenderThread`  
- **`FPrimitiveSceneProxy`**：组件在渲染侧的代理；跨线程传 Proxy，不传 UObject 去画  
- **`ENQUEUE_RENDER_COMMAND`**：把数据「按帧顺序」交给渲染线程，避免数据竞争  

### 4.2 渲染管线挂点

- **DepthPass**：可单独写深度（本组件 `bRenderInDepthPass=true`）  
- **BasePass / MainPass**：默认材质写 GBuffer / 颜色；本组件关掉  
- **`PostRenderBasePassDeferred`**：BasePass 刚完、光照之前 → 适合补写 GBuffer  
- **`PrePostProcessPass`**：光照之后、后处理之前 → 适合往 SceneColor 叠最终色  
- **RDG**：`AllocParameters` + `AddPass` 声明要用的 View/Scene/RT  

### 4.3 自定义画网格三件套

1. **`FMeshMaterialShader`**：和材质 + VertexFactory 一起编译的 VS/PS  
2. **`FMeshPassProcessor::AddMeshBatch`**：选 Shader、设 RenderState、`BuildMeshDrawCommands`  
3. **`DrawDynamicMeshPass`**：当帧动态收集并提交  

对比：`FGlobalShader` 适合全屏/Compute，**不负责** LocalVertexFactory 网格管线。

### 4.4 GBuffer / 视口 / 深度（踩过的坑）

- GBufferA/B/C：Normal / Metal-Spec-Rough-ShadingModel / BaseColor(+AO)  
- **Viewport 必须用 `FViewInfo::ViewRect`**，不能用 `UnscaledViewRect`（TAA 下会错位 → 黑影漂）  
- 自定义 Pass **要写深度**，否则遮挡/后续重建会错  
- GBuffer 路径对 SceneColor 用 **`CW_NONE`**，避免把 RT0 抹成黑  
- Substrate 工程可能 **没有经典 GBuffer** → 自动回退前向  

### 4.5 两条「Lumen」别混

| 路径 | 实际吃到的 |
|---|---|
| GBuffer + Deferred | **不透明 Lumen Screen Probe**（引擎正式路径） |
| 前向 usf | **半透明 Lumen Translucency Volume** 或 SkySH（近似，不是同一套） |

### 4.6 设置 / CVar / 优先级

```
r.CustomMeshPass 0/1          # 总开关；关了 + 无 MainPass = 黑剪影
r.CustomMeshPass.LightingPath 0/1    # 0=强制前向；1=优先 GBuffer（无 GBuffer 则回退）
```

CVar 每次赋值都带「来源优先级」，低优先级写不过高优先级：

```
Constructor < Scalability < GameSetting < ProjectSetting < SystemSettingsIni
            < DeviceProfile < ConsoleVariablesIni < CommandLine < Code < Console
```

- 项目设置页写入 = `ECVF_SetByProjectSetting`  
- 蓝图 `SetEnabled` / `SetLightingPath` = `ECVF_SetByCode`（会压过设置页）  
- `ConsoleVariables.ini` 高于项目设置 → **不要在那里写本插件的 CVar**

---

## 5. 分文件详细解读

---

### 5.1 `CustomMeshPassModule` — 模块启动

**打开：** `Public/CustomMeshPassModule.h` + `Private/CustomMeshPassModule.cpp`

**知识点：**

1. 插件着色器不在 `/Engine` 下，必须 `AddShaderSourceDirectoryMapping`：

```cpp
AddShaderSourceDirectoryMapping(TEXT("/Plugin/CustomMeshPass"), ShaderDir);
```

之后 `IMPLEMENT_MATERIAL_SHADER_TYPE(..., TEXT("/Plugin/CustomMeshPass/Private/CustomMeshPassVertex.usf"), ...)` 才能找到文件。`LoadingPhase: PostConfigInit` 保证在 Shader 编译前完成映射。

2. **独立日志类别**：

```cpp
// .h
CUSTOMMESHPASS_API DECLARE_LOG_CATEGORY_EXTERN(LogCustomMeshPass, Log, All);
// .cpp
DEFINE_LOG_CATEGORY(LogCustomMeshPass);
```

输出日志窗口可以按 `LogCustomMeshPass` 过滤，也能用 `log LogCustomMeshPass Verbose` 调级别。别再用 `LogTemp`。

3. **打包后应用项目设置**：

```cpp
UE::ConfigUtilities::ApplyCVarSettingsFromIni(
    TEXT("/Script/CustomMeshPass.CustomMeshPassSettings"), *GEngineIni, ECVF_SetByProjectSetting);
```

编辑器里设置 CDO 会自己同步 CVar；打包后没有这一步就读不到设置页的值。

---

### 5.2 `CustomMeshPassTypes.h` — 公共类型

```cpp
UENUM(BlueprintType)
enum class ECustomMeshPassLightingPath : uint8 { ForwardCustom = 0, DeferredLumen = 1 };

struct FCustomMeshPassSurface { FVector3f BaseColor; float Metallic; float Roughness; };
```

- **枚举带 `UENUM`**：要在设置页和蓝图里显示成下拉框。数值与 `r.CustomMeshPass.LightingPath` 一一对应，所以设置页可直接绑定这个 CVar  
- **结构体不带 `USTRUCT`**：只在 C++ 里做游戏线程 → 渲染线程的拷贝，不需要反射  

---

### 5.3 `CustomMeshPassCVars` + `CustomMeshPassSettings` — 配置系统

**打开：** `Private/CustomMeshPassCVars.*`、`Public/CustomMeshPassSettings.h`

#### 5.3.1 CVar 只有一个入口

```cpp
namespace CustomMeshPass::CVars
{
    bool IsEnabled_GameThread();
    void SetEnabled(bool);
    ECustomMeshPassLightingPath GetLightingPath_GameThread();
    void SetLightingPath(ECustomMeshPassLightingPath);
    ECustomMeshPassRenderPath ResolveRenderPath_RenderThread();
}
```

`TAutoConsoleVariable` 放在 cpp 的匿名命名空间里，外部拿不到，只能走这些函数。  
`_GameThread` / `_RenderThread` 后缀提醒调用线程：CVar 有两份值（`GetValueOnGameThread` / `GetValueOnRenderThread`），渲染线程那份在帧边界同步。

#### 5.3.2 渲染路径决策集中在一处

```cpp
ECustomMeshPassRenderPath ResolveRenderPath_RenderThread()
{
    if (!Enabled) return Disabled;
    return (WantsGBuffer && FSceneTexturesConfig::Get().bIsUsingGBuffers)
        ? DeferredGBuffer : Forward;
}
```

两个渲染钩子都只问这一个函数，天然互斥，不会出现「两条路径都画」或「都不画」。

#### 5.3.3 项目设置页 ⇄ CVar

```cpp
UCLASS(config = Engine, defaultconfig)
class UCustomMeshPassSettings : public UDeveloperSettingsBackedByCVars
{
    UPROPERTY(config, EditAnywhere, meta = (ConsoleVariable = "r.CustomMeshPass"))
    bool bEnabled = true;

    UPROPERTY(config, EditAnywhere, meta = (ConsoleVariable = "r.CustomMeshPass.LightingPath"))
    ECustomMeshPassLightingPath LightingPath = ...;
};
```

| 机制 | 说明 |
|---|---|
| `UDeveloperSettings` | 引擎自动发现，出现在 项目设置 → `GetCategoryName()`（这里是 Plugins） |
| `BackedByCVars` + `meta=(ConsoleVariable)` | 打开设置页时从 CVar 读值；改动时写回 CVar（`SetByProjectSetting`） |
| `config=Engine, defaultconfig` | 保存到 `Config/DefaultEngine.ini` 的 `[/Script/CustomMeshPass.CustomMeshPassSettings]`，键名就是 CVar 名 |

这和引擎自己的「渲染」设置页（`URendererSettings`）是同一套机制。

---

### 5.4 `CustomMeshPassActor` — 关卡入口

**打开：** `Public/CustomMeshPassActor.h` + `Private/CustomMeshPassActor.cpp`

- 构造函数里 `CreateDefaultSubobject` 创建默认组件  
- `SetRootComponent` 让 Actor 有 Transform  

Actor 几乎没有逻辑，真正策略在 Component。你也可以不用它，直接给任意 Actor 加 `CustomMeshPassComponent`。

---

### 5.5 `CustomMeshPassComponent` — 退出默认光照 + 报名

**打开：** `Public/CustomMeshPassComponent.h` + `Private/CustomMeshPassComponent.cpp`

#### 5.5.1 继承

```cpp
class CUSTOMMESHPASS_API UCustomMeshPassComponent : public UStaticMeshComponent
```

`: public UStaticMeshComponent` **就是指定父类**，因此可直接写 `bRenderInMainPass`；`Super` 也指向它。

#### 5.5.2 构造函数：为什么不进主渲染

| 标志 | 含义 |
|---|---|
| `bRenderInMainPass=false` | 引擎不会用组件材质画 GBuffer/颜色 |
| `bRenderInDepthPass=true` | DepthPass 仍写入 → 遮挡、自定义 Pass 深度测试有依据 |

**副作用：** 开关关掉时只剩深度 → **黑剪影**。  
**材质槽仍在用：** DepthPass / 阴影 / 拾取 / 物理都用它，保持不透明、无 WPO 的材质，否则深度与本 Pass（`DepthNearOrEqual`）对不上。

#### 5.5.3 给渲染层的两个只读接口

```cpp
bool ShouldDrawWithCustomMeshPass() const;   // IsVisible() && SceneProxy
FCustomMeshPassSurface GetSurface() const;   // 拷贝 BaseColor/Metallic/Roughness
```

渲染层不再直接读组件字段，组件内部怎么存参数（将来换成材质实例、DataAsset）都不影响渲染代码。

#### 5.5.4 OnRegister / OnUnregister

`OnRegister` / `OnUnregister` 是对 `UActorComponent` 的 **override**；里面调用的 `Subsystem->RegisterComponent(this)` 是**本插件自己的普通成员函数**。

---

### 5.6 `CustomMeshPassSubsystem` — World 级管家

**打开：** `Public/CustomMeshPassSubsystem.h` + `Private/CustomMeshPassSubsystem.cpp`

#### 5.6.1 职责

1. 生命周期：World 创建 → `Initialize` 创建 Extension；World 销毁 → `Deinitialize` 释放  
2. 组件登记：`RegisterComponent` / `UnregisterComponent`  
3. 给渲染层遍历：`ForEachDrawableComponent`（已过滤无效 / 隐藏 / 无 Proxy）  
4. 蓝图 API：`SetEnabled` / `IsEnabled` / `SetLightingPath` / `GetLightingPath` / `GetRegisteredComponentCount`

#### 5.6.2 `UWorldSubsystem` 创建时机

默认只在 **Game / Editor / PIE** World 创建，材质编辑器预览等 `EditorPreview` World 不会有它。

#### 5.6.3 为何 IDE 对 Initialize「查不到调用」

引擎通过 `USubsystem*` **虚调用** `Initialize`，对 override 做「查找引用」经常列不全。

#### 5.6.4 `TFunctionRef`

```cpp
void ForEachDrawableComponent(TFunctionRef<void(const UCustomMeshPassComponent&)> Func) const;
```

`TFunctionRef` 是不分配内存的函数引用，适合「立即调用、不保存」的回调；需要保存回调时用 `TFunction`。

---

### 5.7 `Rendering/CustomMeshPassSceneViewExtension` — 什么时候画

**打开：** `Private/Rendering/CustomMeshPassSceneViewExtension.*`

| 回调 | 线程 | 用途 |
|---|---|---|
| `IsActiveThisFrame_Internal` | 游戏 | 基类 World 过滤 + 总开关 |
| `BeginRenderViewFamily` | 游戏 | 收集 DrawItems，渲染命令交给渲染线程 |
| `PostRenderBasePassDeferred_RenderThread` | 渲染 | `DeferredGBuffer` 时调 `AddGBufferPass` |
| `PrePostProcessPass_RenderThread` | 渲染 | `Forward` 时调 `AddForwardPass` |
| `PostRenderViewFamily_RenderThread` | 渲染 | 清空 DrawItems |

#### 5.7.1 为什么在 BeginRenderViewFamily 收集

一帧顺序：`SetupViewFamily` → `World->SendAllEndOfFrameUpdates()`（此时 Proxy 才会重建）→ `BeginRenderViewFamily`。  
拖动物体时 Proxy 每帧重建，在 `SetupViewFamily` 拿到的是**旧的、即将销毁**的 Proxy → 闪黑。

#### 5.7.2 为什么用渲染命令传数据

```cpp
ENQUEUE_RENDER_COMMAND(CustomMeshPassSetDrawItems)(
    [This, Items = MoveTemp(Items)](FRHICommandListImmediate&) mutable
    { This->DrawItems_RenderThread = MoveTemp(Items); });
```

渲染线程可能还在画上一帧。直接写成员变量 = 数据竞争。渲染命令与本帧渲染命令**同序执行**，保证拿到的列表与本帧场景一致。

#### 5.7.3 为什么必须调用基类 IsActiveThisFrame_Internal

`FWorldSceneViewExtension` 基类比较 `World == Context.GetWorld()`。覆盖时不调基类 → 材质编辑器预览窗口也会画本 World 的物体。

---

### 5.8 `Rendering/CustomMeshPassPasses` — 怎么建 RDG Pass

**打开：** `Private/Rendering/CustomMeshPassPasses.*`

#### 5.8.1 GBuffer Pass

1. 复用引擎传入的 BasePass `RenderTargets`（SceneColor + GBuffer MRT + Depth）  
2. 把 Depth 改为 **可写**（`DepthWrite_StencilWrite`）  
3. Viewport = **`FViewInfo::ViewRect`**（`GetRasterViewRect`）  
4. `AddPass("CustomMeshPass_GBuffer N")` → `DrawItems(..., WriteGBufferForLumen)`

#### 5.8.2 Forward Pass

1. 绑 SceneColor（Load）+ Depth 可写（没有深度时用 DepthDummy）  
2. `GetLumenTranslucencyGIVolume` 取 Lumen 半透明体积（失败时黑色 3D 纹理）  
3. `AddPass("CustomMeshPass_Forward N")`，**在 Pass lambda 内**才 `GetRHI()`（RDG 纹理的 RHI 资源只在执行期有效）

#### 5.8.3 调试标记

```cpp
DECLARE_GPU_STAT_NAMED(CustomMeshPassGPU, TEXT("CustomMeshPass"));
...
RDG_EVENT_SCOPE(GraphBuilder, "CustomMeshPass");      // RenderDoc / Insights 里的分组
RDG_GPU_STAT_SCOPE(GraphBuilder, CustomMeshPassGPU);  // stat gpu 里的耗时条目
```

#### 5.8.4 DrawItems（两条路径共用）

```
SetViewport(ViewRect)
  → DrawDynamicMeshPass
      → FCustomMeshPassMeshProcessor
          → 跳过 GetPrimitiveSceneInfo()==nullptr 的 Proxy（尚未进场景，没有 GPUScene 数据）
          → Proxy->GetMeshDescription(LOD0) → FMeshBatch
          → CurrentElementData.Surface = Item.Surface
          → AddMeshBatch
```

**InstanceCulling：** 动态画法没走实例剔除管线，用 `CreateDummyInstanceCullingUniformBuffer` 占位。

---

### 5.9 `Rendering/CustomMeshPassMeshProcessor` — 怎么生成 DrawCommand

**打开：** `Private/Rendering/CustomMeshPassMeshProcessor.*`

#### 5.9.1 构造：RenderState

| 模式 | Blend | Depth |
|---|---|---|
| WriteGBufferForLumen | RT0 `CW_NONE`，RT1–3 写 | `DepthNearOrEqual` + 写入 + StencilWrite |
| ForwardCustomBRDF | 默认不透明写 SceneColor | `DepthNearOrEqual` + 写入 |

#### 5.9.2 AddMeshBatch

1. 用 **Default Surface 材质** 的 RenderProxy 取已编译的 MeshMaterialShader  
2. `TryGetShaders` 失败则 Fallback  
3. `InitializeMeshMaterialData` 填基础元素数据  
4. 按模式调用模板函数 `BuildCommands<PixelShaderType>`

#### 5.9.3 模板消除重复

原来两种模式各写一遍 `TMeshProcessorShaders + BuildMeshDrawCommands`，现在：

```cpp
template<typename PixelShaderType>
void BuildCommands(...)
{
    TMeshProcessorShaders<FCustomMeshPassVS, PixelShaderType> PassShaders;
    ...
    BuildMeshDrawCommands(...);
}
```

模板成员函数定义在 cpp 里也没问题：它只在同一个 cpp 里被实例化。

---

### 5.10 `Rendering/CustomMeshPassShaders` — Shader 类型

**打开：** `Private/Rendering/CustomMeshPassShaders.*`

| 类 | 文件 / 入口 | 用途 |
|---|---|---|
| `FCustomMeshPassVS` | `CustomMeshPassVertex.usf` `MainVS` | 两路径共用 |
| `FCustomMeshPassForwardPS` | `CustomMeshPassForward.usf` `MainPS` | 前向 BRDF |
| `FCustomMeshPassGBufferPS` | `CustomMeshPassGBuffer.usf` `MainPS` | 写 GBuffer |

**`ShouldCompilePermutation`：** 只给 **默认表面材质 × `FLocalVertexFactory`** 编译。渲染时本来就只用默认材质，其它材质生成的变体全是浪费。

**ElementData =「材质参数块」：** `Surface` + 前向用的 Lumen 体积，在 `GetShaderBindings` 里 `ShaderBindings.Add(...)` 喂给 HLSL 全局变量。

---

### 5.11 `Rendering/CustomMeshPassLumenBridge` — 隔离私有 API

```cpp
FCustomMeshPassLumenVolume GetLumenTranslucencyGIVolume(FRDGBuilder&, const FSceneView&);
```

`FViewInfo::GetOwnLumenTranslucencyGIVolume()` 来自 `Renderer/Private`，每个引擎版本都可能变。  
把它包在一个函数里：Passes 只认识 `FCustomMeshPassLumenVolume`，升级引擎时只改这个 cpp。

---

### 5.12 Shader 文件

**公共 ush（被 include，不单独编译）：**

| 文件 | 内容 |
|---|---|
| `CustomMeshPassCommon.ush` | `FCustomMeshPassVSToPS`、`CMP_GetPixelParameters`、`CMP_GetWorldNormal` |
| `CustomMeshPassBRDF.ush` | Fresnel / GGX D / Smith G / `CMP_BRDF_Direct` |
| `CustomMeshPassIndirect.ush` | Lumen 体积参数声明、`CMP_GetSkySHDiffuse`、`CMP_SampleLumenDiffuseGI` |

**入口 usf（对应 C++ Shader 类型）：**

- `CustomMeshPassVertex.usf`：Local VF → WorldPos(+WPO) → `TranslatedWorldToClip`。原来两个 usf 各拷一份 VS，现在只有一份  
- `CustomMeshPassGBuffer.usf`：填 `FGBufferData`（DefaultLit）→ `EncodeGBuffer` 输出 SV_Target1/2/3；SV_Target0 = 0（C++ 侧 CW_NONE 双保险）  
- `CustomMeshPassForward.usf`：Direct（`AtmosphereLightDirection[0]`）+ Indirect（Lumen 体积 / SkySH）+ 极简环境高光，最后 `* PreExposure`

**include 规则：** 插件内部 include 一律写完整虚拟路径 `/Plugin/CustomMeshPass/Private/xxx.ush`；每个入口 usf 先 include `/Engine/Private/Common.ush`。

---

### 5.13 `Build.cs` + `.uplugin`

```csharp
PublicDependencyModuleNames  = Core, CoreUObject, Engine, DeveloperSettings  // Public 头用到的
PrivateDependencyModuleNames = RenderCore, RHI, Renderer, Projects           // 只在 cpp 用
PrivateIncludePaths          = Renderer/Private, Renderer/Internal           // FViewInfo / Lumen 等私有头
```

**Public vs Private 依赖：** Public 依赖会「传染」给依赖本插件的模块；渲染依赖只在实现里用，放 Private 让使用者更干净。  
`DeveloperSettings` 必须是 Public，因为 `CustomMeshPassSettings.h`（Public 头）继承了它的类。

---

## 6. 一帧时序（对照调试用）

```
[游戏线程] SetupViewFamily（不用）
          SendAllEndOfFrameUpdates   ← Proxy 在这里重建
          ★ BeginRenderViewFamily    ← 收集 DrawItems → ENQUEUE_RENDER_COMMAND
        │
[渲染]  DepthPass          ← 本组件写深度（MainPass 关）
        │
        BasePass           ← 本组件不画
        │
        ★ PostRenderBasePassDeferred   ← DeferredGBuffer：写 A/B/C
        │
        Deferred Lights + Lumen Screen Probe
        │
        半透明等
        │
        ★ PrePostProcess               ← Forward：自写 BRDF
        │
        PostProcess
        │
        ★ PostRenderViewFamily         ← 清空 DrawItems
```

---

## 7. 实验建议

1. 项目设置里关掉 Enabled：确认黑剪影（只剩深度）  
2. Lighting Path 切 Forward：改 Roughness 看高光变化  
3. Lighting Path 切 Deferred + Lumen：开 Lumen 看间接光和阴影  
4. 关卡蓝图 BeginPlay 调 `Set Lighting Path`，再去设置页改，体会 SetByCode 优先级  
5. `stat gpu` 看 CustomMeshPass 耗时；RenderDoc 抓帧找 `CustomMeshPass` 事件  
6. 临时把 `GetRasterViewRect` 改回 `UnscaledViewRect`（学习完改回）：观察 TAA 下错位  

---

## 8. 常见问题速查

| 现象 | 原因 |
|---|---|
| 全黑剪影 | 开关关了，或自定义 Pass 失败，MainPass 又是 false |
| 黑影随相机漂 | ViewRect / UnscaledViewRect 不一致 |
| 遮不住后面物体 | 自定义 Pass 没写深度 |
| 拖动时闪黑 | 在 SetupViewFamily 拿了旧 Proxy / 跨线程直接写数组 |
| 材质编辑器预览也出现 | 没调基类 `IsActiveThisFrame_Internal` |
| Substrate 下黑 | 无经典 GBuffer；应走前向回退 |
| 设置页改了没反应 | `ConsoleVariables.ini` 或蓝图 SetByCode 写过同一 CVar（优先级更高） |
| F12 跳不进定义 | `compile_commands.json` 未含插件或含 @rsp；重新生成并运行 `Tools/expand_compile_commands.py` |

---

## 9. 读完应能回答的问题

1. 为什么 Component 要关 MainPass、开 DepthPass？  
2. Subsystem、SceneViewExtension、Passes、MeshProcessor 各管什么？  
3. 为什么 Public 头里不出现任何渲染器类型？  
4. 为什么在 `BeginRenderViewFamily` 收集而不是 `SetupViewFamily`？  
5. 项目设置页、`ConsoleVariables.ini`、蓝图 API 同时设置 CVar 时谁生效？  
6. `FMeshPassProcessor` 相比直接 `DrawIndexed` 多做了什么？  
7. 为什么 Viewport 必须用 `ViewRect`？  
8. 前向 usf 里的「Lumen」和 GBuffer 路径的 Lumen 有何不同？  

---

## 10. 将来扩展的落点

| 想做的事 | 改哪里 |
|---|---|
| 绕开材质系统（GlobalShader + 手动顶点拉取） | 新增 `Rendering/` 下的 Shader + Pass，Extension 分派多一个分支 |
| 更多表面参数（自发光、法线贴图） | `FCustomMeshPassSurface` + 组件属性 + Shaders 绑定 + usf |
| 新的渲染路径 | `ECustomMeshPassRenderPath` + `ResolveRenderPath_RenderThread` |
| 升级引擎后 Lumen 编译失败 | 只看 `CustomMeshPassLumenBridge.cpp` |

---

## 11. 相关引擎对照阅读（选修）

- `SceneRendering.cpp`：`BeginRenderViewFamily` 与 `SendAllEndOfFrameUpdates` 的先后  
- `BasePassRendering.cpp`：调用 `PostRenderBasePassDeferred_RenderThread` 的位置  
- `DeferredShadingCommon.ush`：`EncodeGBuffer` / `FGBufferData`  
- `SceneViewExtension.h`：还有哪些可挂钩子  
- `RendererSettings.h`：引擎自己的 `UDeveloperSettingsBackedByCVars` 用法  

---

*文档版本：与 CustomMeshPass v2.0 源码同步，供对照学习。*
