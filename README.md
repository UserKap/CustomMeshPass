# CustomMeshPass — 自定义 Mesh Pass + 可选 Lumen

独立运行时插件（v2.0）。用 SceneViewExtension + MeshMaterialShader 绘制 StaticMesh，两条光照路径可切换：

- **Deferred + Lumen**：BasePass 之后补写 GBuffer，光照交给引擎  
- **Forward Custom**：后处理前用自写 BRDF 直接画进 SceneColor  

**架构与源码解读：** [ScriptReadme.md](./ScriptReadme.md)（知识点 + 架构分层 + 逐文件解读）。

---

## 怎么用

1. 启用插件，编译 / 开工程  
2. 放置 `CustomMeshPassActor`（或给任意 Actor 加 `CustomMeshPassComponent`），设 Static Mesh（勿用 Nanite），调 BaseColor / Metallic / Roughness  
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

---

## 两种路径对比

| | Forward Custom | Deferred + Lumen |
|---|---|---|
| 挂点 | PrePostProcess | PostRenderBasePassDeferred |
| Direct | 自写 GGX（主方向光，无阴影） | 引擎 DefaultLit（含阴影） |
| Indirect | Lumen 半透明 GI 体积 / 天光 SH | Lumen Screen Probe（正式 GI） |

---

## 目录

```
Shaders/Private/      CustomMeshPassCommon/BRDF/Indirect.ush + Vertex/Forward/GBuffer.usf
Source/CustomMeshPass/
  Public/             Module、Types、Settings、Subsystem、Component、Actor
  Private/            模块实现、CVars、场景层实现
  Private/Rendering/  SceneViewExtension、Passes、MeshProcessor、Shaders、LumenBridge
```
