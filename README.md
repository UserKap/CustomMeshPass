# CustomMeshPass — 自定义 Mesh Pass + 可选 Lumen

独立运行时插件（v2.0）。用 SceneViewExtension + MeshMaterialShader 绘制 StaticMesh，两条光照路径可切换：

- **Deferred + Lumen**：BasePass 之后补写 GBuffer，光照交给引擎  
- **Forward Custom**：后处理前用自写 BRDF 直接画进 SceneColor  

**架构与源码解读：** [ScriptReadme.md](./ScriptReadme.md)（知识点 + 架构分层 + 逐文件解读）。

---

## 怎么用

1. 启用插件，编译 / 开工程  
2. 放置 `CustomMeshPassActor`（或给任意 Actor 加 `CustomMeshPassComponent`），设 Static Mesh（勿用 Nanite），在 **CustomMeshPass|Material** 里调表面参数和贴图  
3. **项目设置 → 插件 → Custom Mesh Pass** 里选开关和光照路径（保存在 `DefaultEngine.ini`，打包后同样生效）

### 设置 / CVar 对照

| 设置项 | CVar | 取值 |
|---|---|---|
| Enabled | `r.CustomMeshPass` | 0 关（**会黑**：组件不进 MainPass，只写深度）/ 1 开 |
| Lighting Path | `r.CustomMeshPass.LightingPath` | 0 = Forward Custom；1 = Deferred + Lumen（无经典 GBuffer 如 Substrate 时**自动回退前向**） |

优先级（高 → 低）：控制台命令 / 蓝图 API（SetByCode） > `ConsoleVariables.ini` > 项目设置。  
所以**不要**再在 `ConsoleVariables.ini` 写 `r.CustomMeshPass*`，否则设置页改了也不生效。

### 蓝图 API（`CustomMeshPass Subsystem`）

| 节点 | 说明 |
|---|---|
| `Set Enabled` / `Is Enabled` | 总开关 |
| `Set Lighting Path` / `Get Lighting Path` | 光照路径（`ECustomMeshPassLightingPath`） |
| `Get Registered Component Count` | 当前 World 注册的组件数 |

CVar 是全局的，通过任意 World 的 Subsystem 设置都会影响所有视口。

### 表面参数（Default Lit）

组件上的标量和贴图会收成一份 `FCMP_PBRSurface`，前向 BRDF 和 GBuffer 共用。网格材质图的颜色输出不会被读取（本 Pass 固定用默认表面材质）。

| 属性 | 作用 |
|---|---|
| BaseColor / BaseMap | 没有贴图时用颜色；有 BaseMap 时颜色 × 贴图。BaseMap 打开 sRGB |
| NormalMap | 切线空间法线，关闭 sRGB。没有贴图时用顶点法线 |
| NormalStrength | 法线贴图强度，默认 1。0 = 完全平面，>1 加强凹凸（缩放切线空间 XY 后重新归一化） |
| Metallic / MetallicMap | 有贴图时用贴图 R，否则用标量 |
| Specular | 电介质高光，默认 0.5（F0 = 0.04） |
| Roughness / RoughnessMap | 有贴图时用贴图 R，否则用标量。结果钳在 0.02–1 |
| AmbientOcclusion / AOMap | 有贴图时用贴图 R，否则用标量（默认 1）。只压间接光 |
| Emissive | 线性自发光。前向加到最终色；GBuffer 路径以加法写入 SceneColor |

**UV（CustomMeshPass|Material|UV，五张贴图共用）：**

| 属性 | 作用 |
|---|---|
| UVChannel | 用网格的第几套 UV（0 = UV0，最大 7）。超过网格已有的套数时退回最后一套 |
| UVTiling | 重复次数，默认 (1, 1)。(4, 4) 即贴图在两个方向各重复 4 次 |
| UVOffset | 偏移，在 Tiling 之后叠加：`UV = MeshUV × UVTiling + UVOffset` |

默认材质不声明纹理坐标，所以 UV 是在顶点着色器里从顶点工厂的 UV 缓冲直接读的，不走 `MaterialParameters.TexCoords`。不支持 Virtual Texture 和 Nanite。Roughness / Metallic / AO / Normal 请关闭 sRGB。

### 调试

- 日志类别：`LogCustomMeshPass`  
- GPU 耗时：`stat gpu` 里的 **CustomMeshPass**  
- RenderDoc / Insights 事件：`CustomMeshPass` → `CustomMeshPass_GBuffer N` / `CustomMeshPass_Forward N`

---

## 常见问题

| 现象 | 原因 |
|---|---|
| 全黑剪影 | 开关关了；组件 `bRenderInMainPass=false` 只剩深度 |
| 黑影随相机漂 / 遮不住别的物体 | Viewport 必须用 `FViewInfo::ViewRect`，且本 Pass 要写深度（已处理） |
| 拖动时闪黑 | 须在 `BeginRenderViewFamily` 收集 Proxy 并用渲染命令交给渲染线程（已处理） |
| 材质编辑器预览里也出现 | `IsActiveThisFrame_Internal` 必须调用基类做 World 过滤（已处理） |
| Details 里仍有材质槽 | 材质槽仍被 DepthPass / 阴影 / 拾取使用；请用不透明、无 WPO 的材质保持深度一致 |
| 贴了图仍是纯色 | 网格没有 UV，UVTiling 被设成 0，或贴图是 Virtual Texture（只接受普通 Texture2D） |
| 改 UVChannel 没变化 | 网格只有一套 UV（会退回最后一套）；或平台不走 Manual Vertex Fetch，只能拿到 UV0 |
| Tiling 后接缝明显 | 贴图的 Address 模式不影响本 Pass，采样器固定 Wrap；接缝来自贴图本身不可平铺 |
| 法线凹凸反了 | 导入法线时勾选 Flip Green Channel（烘焙进纹理，本 Pass 不再翻一次） |
| 粗糙 / 金属 / AO 发灰发亮 | 这些图以及 NormalMap 必须关闭 sRGB |
| 前向下点光照不亮 | 光源的 Lighting Channel 0 被关了，或路径追踪模式下没有 Light Grid |
| 前向下点光穿墙 | 前向局部光源不算阴影，属于预期；需要阴影请切 Deferred + Lumen |
| 前向下没有主光 | 方向光要勾选 **Atmosphere Sun Light**（前向主光读 `AtmosphereLights[0]`） |

---

## 两种路径对比

| | Forward Custom | Deferred + Lumen |
|---|---|---|
| 挂点 | PrePostProcess | PostRenderBasePassDeferred |
| Direct | 自写 GGX：主方向光 + 点光 / 聚光 / 矩形光（复用引擎 Light Grid，无阴影） | 引擎 DefaultLit（含阴影） |
| Indirect | Lumen 半透明 GI 体积 / 天光 SH | Lumen Screen Probe（正式 GI） |

前向局部光源读的是引擎每帧为半透明准备的 Light Grid（按屏幕格子剔除好的光源列表），所以场景里的点光、聚光、矩形光都会自动生效，数量多了也不会逐像素遍历全部光源。限制：没有阴影、IES、光照函数；矩形光按"面积 × 朝向余弦"近似成点光，亮度与 Deferred 下会有差别。

---

## 目录

```
Shaders/Private/      Common/Surface/BRDF/Indirect/LocalLights.ush + Vertex/Forward/GBuffer.usf
Source/CustomMeshPass/
  Public/             Module、Types、Settings、Subsystem、Component、Actor
  Private/            模块实现、CVars、场景层实现
  Private/Rendering/  SceneViewExtension、Passes、MeshProcessor、Shaders、LumenBridge、ForwardLight
```
