# 🎮 Game-Engines

Engine projects in modern C++, from 2D foundations up to full engine architecture.
Graphics work lives in **Umbra**; this repo is where the engines are built.

## 🗂️ Projects

| | Project | Built with | What it is | Status |
|:-:|:--|:--|:--|:-:|
| 🧱 | **2DEngine** | `C++17` `SDL3` `OpenGL` `Lua` | 2D engine on an ECS core, rendered through my own OpenGL batch renderer instead of SDL's built-in renderer | ![](https://img.shields.io/badge/-Active-e9a21f?style=flat-square) |

## ⚙️ 2DEngine — Architecture

- **ECS** — entities, packed component pools, bitset signatures, systems
- **Renderer** — custom OpenGL batch renderer: textured quads, tilemaps, 2D camera
- **Platform layer** — SDL3 for window, input, timing and audio
- **Game loop** — frame-rate independent, delta-time driven
- **Event bus** — publish/subscribe events between systems
- **Asset store** — textures and fonts loaded once, looked up by ID
- **Scripting** — Lua embedded through Sol for levels and entity behaviour
- **Tooling** — Dear ImGui panels for live inspection and tweaking

## 🧰 Tech Stack

`C++` · `OpenGL` · `GLSL` · `SDL3` · `GLM` · `Lua` · `Sol` · `Dear ImGui` · `Visual Studio`

## 🔨 Building

Windows, Visual Studio, x64. All dependencies live in `vendor/`, so the solution builds straight after cloning.
