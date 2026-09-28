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
│    CustomMeshPassForwardLight.*         镜像引擎 ForwardLightStruct，给前向接 Light Grid 局部光源              │
│    CustomMeshPassDrawItem.h             游戏线程 → 渲染线程的数据                                          │
└────────────────────────────────────────────────────────────────────────────────────────────────────────┘
```

**分层原则：**

- **Public 头不出现任何渲染器类型**。使用者（你的游戏模块）只 include 组件 / 子系统 / 设置，不会被迫依赖 `Renderer` 私有头。所以 `Build.cs` 里 `RenderCore/RHI/Renderer/Projects` 都放在 **Private** 依赖。  
- **每个文件只回答一个问题**：什么时候画（Extension）、怎么建 Pass（Passes）、怎么生成命令（Processor）、Shader 长什么样（Shaders）。  
- **引擎私有 API 集中隔离**：Lumen 体积读取只在 `LumenBridge.cpp`，Light Grid 读取只在 `ForwardLight.cpp`，引擎升级时各改一处。  
- **CVar 只有一个入口**：设置页、蓝图、渲染代码都通过 `CustomMeshPass::CVars::*`，不直接碰 `TAutoConsoleVariable`。

### 2.1 目录

```
Plugins/CustomMeshPass/
├── CustomMeshPass.uplugin
├── README.md / ScriptReadme.md
├── Shaders/Private/
│   ├── CustomMeshPassCommon.ush      # VS→PS 结构、按通道拉 UV + Tiling/Offset、像素参数重建、法线翻转
│   ├── CustomMeshPassSurface.ush     # FCMP_PBRSurface：标量 + Base/Normal/AO/Rough/Metal 贴图
│   ├── CustomMeshPassBRDF.ush        # Lambert + GGX，F0 = 0.08 * Specular
│   ├── CustomMeshPassIndirect.ush    # 天光 SH + Lumen 半透明体积采样
│   ├── CustomMeshPassLocalLights.ush # 前向局部光源：遍历引擎 Light Grid，点光 / 聚光 / 矩形光
│   ├── CustomMeshPassVertex.usf      # MainVS（两路径共用）
│   ├── CustomMeshPassForward.usf     # MainPS：自写光照
│   └── CustomMeshPassGBuffer.usf     # MainPS：EncodeGBuffer + 加法自发光
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
| 11 | `Rendering/CustomMeshPassLumenBridge.*` + `CustomMeshPassForwardLight.*` | 如何隔离引擎私有 API；未导出的 UB 怎么镜像复用 |
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
- GBuffer 路径对 SceneColor 用 **加法**（`CW_RGB`，One + One）只写自发光；自发光为 0 时加 0，不会把 RT0 抹黑  
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

struct FCustomMeshPassSurface
{
    FVector3f BaseColor;
    float Metallic;
    float Specular;          // 默认 0.5
    float Roughness;
    float AmbientOcclusion;  // 默认 1
    FVector3f Emissive;

    float NormalStrength;    // 默认 1，PS 用
    uint32 UVChannel;        // 默认 0，VS 用
    FVector2f UVTiling;      // 默认 (1,1)，VS 用
    FVector2f UVOffset;      // 默认 (0,0)，VS 用
};
```

- **枚举带 `UENUM`**：要在设置页和蓝图里显示成下拉框。数值与 `r.CustomMeshPass.LightingPath` 一一对应，所以设置页可直接绑定这个 CVar  
- **结构体不带 `USTRUCT`**：只在 C++ 里做游戏线程 → 渲染线程的拷贝，不需要反射  
- **这里只有标量**。贴图是 `FTextureRHIRef`，放在私有的 `FCustomMeshPassDrawItem` 里。Public 头不出现 RHI 类型  

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
FCustomMeshPassSurface GetSurface() const;   // 只拷贝标量：BaseColor/Metallic/Specular/Roughness/AO/Emissive/NormalStrength/UV 参数
```

贴图（`BaseMap` / `NormalMap` / `MetallicMap` / `RoughnessMap` / `AOMap`）是组件上的 `UTexture2D*`，**不进** `GetSurface()`。  
`BeginRenderViewFamily` 里用 `GetResource()->GetTexture2DRHI()` 抓成 `FTextureRHIRef`，和标量一起放进 `FCustomMeshPassDrawItem`。这样 Public 头仍然不依赖 RHI，纹理在这一帧的渲染命令里也有引用计数。

渲染层不再直接读组件的标量字段。有贴图时用贴图（金属 / 粗糙 / AO 取 R），没有贴图时用标量；`BaseColor` 在有 `BaseMap` 时作为颜色相乘。

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
3. `CreateForwardLightUniformBuffer` 拷一份本帧 Light Grid，作为 `ForwardLight` 声明在 Pass 参数里（见 5.11.1）  
4. `AddPass("CustomMeshPass_Forward N")`，**在 Pass lambda 内**才 `GetRHI()`（RDG 纹理 / UB 的 RHI 资源只在执行期有效）

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
          → CurrentElementData 的五张贴图 = Item 上的 FTextureRHIRef
          → AddMeshBatch
```

**InstanceCulling：** 动态画法没走实例剔除管线，用 `CreateDummyInstanceCullingUniformBuffer` 占位。

---

### 5.9 `Rendering/CustomMeshPassMeshProcessor` — 怎么生成 DrawCommand

**打开：** `Private/Rendering/CustomMeshPassMeshProcessor.*`

#### 5.9.1 构造：RenderState

| 模式 | Blend | Depth |
|---|---|---|
| WriteGBufferForLumen | RT0 加法写自发光（`CW_RGB`，One+One），RT1–3 写 GBuffer | `DepthNearOrEqual` + 写入 + StencilWrite |
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
| `FCustomMeshPassVS` | `CustomMeshPassVertex.usf` `MainVS` | 两路径共用；绑定 `UVChannel` / `UVTilingOffset` |
| `FCustomMeshPassForwardPS` | `CustomMeshPassForward.usf` `MainPS` | 前向 BRDF |
| `FCustomMeshPassGBufferPS` | `CustomMeshPassGBuffer.usf` `MainPS` | 写 GBuffer |

**`ShouldCompilePermutation`：** 只给 **默认表面材质 × `FLocalVertexFactory`** 编译。渲染时本来就只用默认材质，其它材质生成的变体全是浪费。

**ElementData =「材质参数块」：** `Surface` 标量 + 五张贴图的 `FRHITexture*` + 前向用的 Lumen 体积和 Light Grid UB（`ForwardLightUniformBuffer`）。  
ForwardPS 的 `ModifyCompilationEnvironment` 补上 `FORWARD_LIGHT_DATA_STRIDE` / `NUM_CULLED_LIGHTS_GRID_STRIDE`，`LightGridCommon.ush` 靠它们算缓冲下标。  
VS 和 PS 各自有 `GetShaderBindings`，收到的是同一份 ElementData：VS 只取 UV 相关字段，PS 取其余表面参数。`BuildMeshDrawCommands` 按模板参数调到各 Shader 自己的 `GetShaderBindings`，所以 VS 也能用插件自定义的 ElementData 类型。  
`GetShaderBindings` 里 `ShaderBindings.Add(...)` / `AddTexture(...)` 喂给 HLSL。贴图为空时仍绑一张白图，并用 `SurfaceMapMask` 告诉着色器这个槽无效（空 SRV 在 D3D 上不合法）。掩码位与 `CustomMeshPassSurface.ush` 的 `CMP_MAP_*` 一致。

---

### 5.11 `Rendering/CustomMeshPassLumenBridge` — 隔离私有 API

```cpp
FCustomMeshPassLumenVolume GetLumenTranslucencyGIVolume(FRDGBuilder&, const FSceneView&);
```

`FViewInfo::GetOwnLumenTranslucencyGIVolume()` 来自 `Renderer/Private`，每个引擎版本都可能变。  
把它包在一个函数里：Passes 只认识 `FCustomMeshPassLumenVolume`，升级引擎时只改这个 cpp。

#### 5.11.1 `CustomMeshPassForwardLight` — 前向局部光源

延迟管线每帧都会调用 `PrepareForwardLightData` 建 Light Grid：把屏幕切成格子（默认 64 像素 × 32 层深度），每格记下影响它的点光 / 聚光 / 矩形光。结果放在 `FViewInfo::ForwardLightingResources`，半透明、体积雾、MegaLights 都在用。

**问题：** 这份数据的类型 `FForwardLightUniformParameters` 声明时没有 `RENDERER_API`，插件：

- 不能写 `SHADER_PARAMETER_RDG_UNIFORM_BUFFER(FForwardLightUniformParameters, ...)`（要链接它的 `GetStructMetadata`）  
- 不能 `GetUniformBufferParameter<FForwardLightUniformParameters>()`（同上）  
- 不声明又不行：RDG 只给 Pass 里声明过的 UB 创建 RHI，也只追踪声明过的缓冲的生命周期

**做法：镜像一份同布局的 UB。**

```
C++  FCustomMeshPassForwardLightParameters  ← 成员名 / 顺序与引擎完全一致，Shader 变量名 CMPForwardLight
     CreateForwardLightUniformBuffer()      ← 逐字段从 View.ForwardLightingResources.ForwardLightUniformParameters 拷贝
                                               （SRV 指针是 RDG 资源，拷过来就等于在本 Pass 里再声明一次）
HLSL #define ForwardLightStruct CMPForwardLight
     #include "/Engine/Private/LightGridCommon.ush"   ← 引擎的格子查找 / 解包函数原样复用
```

逐字段拷贝而不是 `memcpy`：引擎改了成员名或删了字段时会直接编译报错，而不是悄悄错位。

**Shader 侧（`CustomMeshPassLocalLights.ush`）：**

1. `PixelPos = SvPosition.xy - ViewRectMin`，`SceneDepth = ConvertFromDeviceZ(SvPosition.z)` → `ComputeLightGridCellIndex`  
2. `GetCulledLightsGridHeader` 拿到这格的光源数和起始下标  
3. 逐个 `GetLocalLightDataFromGrid` → `ConvertToDeferredLight` 解包成 `FDeferredLightData`  
4. 衰减与 `DeferredLightingCommon.ush` 的 `GetLocalLightAttenuation` 一致（反平方遮罩 / 指数衰减 + 聚光锥角），再乘 `1 / (d² + 1)`  
5. 矩形光：单面发光，按「面积 × 光源侧余弦」近似成点光（引擎已把颜色除以 `0.5 × 宽 × 高`）  
6. 光照结果交给同一个 `CMP_BRDF_Direct`，和主方向光累加

不做的：阴影、IES、光照函数、Lighting Channel 1/2（只认 Channel 0）。路径追踪模式下 Light Grid 不构建，走空 UB（`NumLocalLights = 0`）。

---

### 5.12 Shader 文件

**公共 ush（被 include，不单独编译）：**

| 文件 | 内容 |
|---|---|
| `CustomMeshPassCommon.ush` | `FCustomMeshPassVSToPS`（含 `BaseUV`）、`UVChannel` / `UVTilingOffset`、`CMP_FetchMeshUV`、`CMP_FetchBaseUV`、`CMP_GetPixelParameters`、`CMP_GetWorldNormal` |
| `CustomMeshPassSurface.ush` | `FCMP_PBRSurface`、贴图与标量声明、`CMP_EvaluatePBRSurface` |
| `CustomMeshPassBRDF.ush` | Fresnel / GGX D / Smith G / `CMP_ComputeF0` / `CMP_BRDF_Direct` |
| `CustomMeshPassIndirect.ush` | Lumen 体积参数声明、`CMP_GetSkySHDiffuse`、`CMP_SampleLumenDiffuseGI` |
| `CustomMeshPassLocalLights.ush` | 重定向 `ForwardLightStruct` 后 include `LightGridCommon.ush`、`CMP_LocalLightAttenuation`、`CMP_EvaluateLocalLights` |

**入口 usf（对应 C++ Shader 类型）：**

- `CustomMeshPassVertex.usf`：Local VF → `CMP_FetchBaseUV` → WorldPos(+WPO) → `TranslatedWorldToClip`。两条路径共用这一份 VS  
- `CustomMeshPassGBuffer.usf`：`CMP_EvaluatePBRSurface` 填 `FGBufferData`（DefaultLit）→ `EncodeGBuffer`；SV_Target0 = 自发光 × PreExposure（C++ 侧加法）  
- `CustomMeshPassForward.usf`：同一份表面。Direct（`AtmosphereLightDirection[0]` + `CMP_EvaluateLocalLights`）+ Indirect（Lumen 体积 / SkySH，再乘 AO）+ 极简环境高光 + 自发光，最后 `* PreExposure`

#### 5.12.1 为什么 UV 不走材质的 TexCoords

`ShouldCompilePermutation` 把着色器锁在**默认表面材质**上。默认材质不采样纹理，`NUM_MATERIAL_TEXCOORDS` 往往是 0，`MaterialParameters.TexCoords` 会被编译掉。

`CMP_FetchBaseUV` 因此在顶点着色器里直接读 `FLocalVertexFactory` 的手动顶点拉取缓冲：

```hlsl
LocalVF.VertexFetch_TexCoordBuffer[NumTexCoords * (VertexOffset + VertexId)]
```

多套 UV 在缓冲里按顶点交错存放（UV0, UV1, … 再到下一个顶点），所以第 `UVChannel` 套的下标是 `NumTexCoords × 顶点号 + min(UVChannel, NumTexCoords - 1)`，与引擎 `LocalVertexFactory.ush` 的写法相同，越界时夹到最后一套。

拿到网格 UV 后立刻做 `UV × Tiling + Offset`（`UVTilingOffset` = xy Tiling、zw Offset）。这是线性变换，放在 VS 里插值出来的结果和逐像素计算完全一样，还省掉每个像素一次乘加。

插值语义用自定义的 `CMP_BASEUV`，避开顶点工厂已经占用的 `TEXCOORD`。桌面端 StaticMesh 默认走 Manual Vertex Fetch；非 Manual Vertex Fetch 的平台只能拿到 UV0。网格没有 UV 时返回 0，贴图会采到一个点上。Virtual Texture 的 `GetTexture2DRHI()` 为空，该槽退回标量。

`FCMP_PBRSurface` 是两条像素着色器的唯一表面输入，字段对齐引擎 Default Lit：

| 字段 | 来源 |
|---|---|
| BaseColor | `BaseColor`，有 BaseMap 时再乘贴图（sRGB 由纹理自身解码） |
| WorldNormal | 顶点法线，或 NormalMap（切线空间，Z 由 XY 重建；XY × `NormalStrength` 后重新归一化）经 `TangentToWorld` |
| Metallic / Roughness / AmbientOcclusion | 有对应贴图时取 R，否则用标量 |
| Specular | 标量，默认 0.5。`CMP_ComputeF0` = `lerp(0.08 * Specular, BaseColor, Metallic)` |
| Emissive | 标量，不加贴图 |

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
        ★ PostRenderBasePassDeferred   ← DeferredGBuffer：写 A/B/C，SceneColor 加法叠自发光
        │
        Deferred Lights + Lumen Screen Probe
        │
        半透明等
        │
        ★ PrePostProcess               ← Forward：自写 BRDF（读本帧早先建好的 Light Grid）
        │
        PostProcess
        │
        ★ PostRenderViewFamily         ← 清空 DrawItems
```

---

## 7. 实验建议

1. 项目设置里关掉 Enabled：确认黑剪影（只剩深度）  
2. Lighting Path 切 Forward：改 Roughness 看高光变化；挂 BaseMap / NormalMap（网格需有 UV）看贴图，拖 NormalStrength / UVTiling / UVOffset 看变化；放几盏点光 / 聚光，和 Deferred 对比（前向无阴影）  
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
| 贴图没有变化 | 网格没有 UV、UVTiling 为 0，或用了 Virtual Texture。Roughness / Metallic / AO / Normal 需要关闭 sRGB |
| 改 UVChannel 没变化 | 网格只有一套 UV（夹到最后一套），或平台不走 Manual Vertex Fetch |
| 法线方向反了 | 导入时勾选 Flip Green Channel。着色器不再翻绿通道，避免翻两次 |
| 前向下暗面 / 亮面和 Deferred 相反 | 多半是场景主要靠点光照明而前向没算局部光源（已接 Light Grid）；主方向光 `L0` 不要取负 |
| 前向下点光穿墙 | 局部光源不算阴影，预期行为 |
| 升级引擎后 `CustomMeshPassForwardLight.cpp` 编译失败 | 对照 `SceneRendering.h` 的 `FForwardLightUniformParameters` 同步镜像结构 |
| F12 跳不进定义 / 新文件满屏红线 | `compile_commands.json` 没收录该文件。先编译一次插件，再运行 `Scripts/RefreshCompileCommands.ps1`，然后 Reload Window |

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
| 更多表面参数 | 标量加进 `FCustomMeshPassSurface`；贴图加进 `FCustomMeshPassDrawItem` + `SurfaceMapMask` + `CustomMeshPassSurface.ush` |
| 每张贴图独立 Tiling / UV 通道 | VS 输出多组 UV（插值器增加），或 PS 里按贴图各自变换；参数放进 `FCustomMeshPassSurface` |
| 新的渲染路径 | `ECustomMeshPassRenderPath` + `ResolveRenderPath_RenderThread` |
| 升级引擎后 Lumen 编译失败 | 只看 `CustomMeshPassLumenBridge.cpp` |
| 前向局部光源加阴影 | 需要 VSM / ShadowMask，工作量大；更现实的是切 Deferred + Lumen |
| 前向主方向光不依赖 Atmosphere Sun Light | `CustomMeshPassForward.usf` 改读 `CMPForwardLight.DirectionalLightDirection / Color`（已绑定） |

---

## 11. 相关引擎对照阅读（选修）

- `SceneRendering.cpp`：`BeginRenderViewFamily` 与 `SendAllEndOfFrameUpdates` 的先后  
- `BasePassRendering.cpp`：调用 `PostRenderBasePassDeferred_RenderThread` 的位置  
- `DeferredShadingCommon.ush`：`EncodeGBuffer` / `FGBufferData`  
- `SceneViewExtension.h`：还有哪些可挂钩子  
- `LightGridInjection.cpp` + `LightGridCommon.ush`：Light Grid 怎么建、怎么查  
- `RendererSettings.h`：引擎自己的 `UDeveloperSettingsBackedByCVars` 用法  

---

*文档版本：与 CustomMeshPass v2.0 源码同步（表面参数含 Base / Normal / AO / Roughness / Metallic 与 Default Lit 标量、NormalStrength、UV 通道 / Tiling / Offset；前向路径接入引擎 Light Grid 局部光源）。*
