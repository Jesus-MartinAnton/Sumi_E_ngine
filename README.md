# SumiEngine (墨絵) — Custom Vulkan 1.3 Render Engine

![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)
![Vulkan](https://img.shields.io/badge/Vulkan-1.3-red.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

**SumiEngine** es un motor de renderizado en tiempo real desarrollado desde cero en **C++20** y **Vulkan 1.3**, orientado al estudio de arquitectura de gráficos de bajo nivel y a la investigación de **Renderizado No Fotorrealista (NPR)** enfocado en la estética *Sumi-e* (pintura tradicional con tinta china y acuarela).

> 📌 **Objetivo del Proyecto:** Este proyecto forma parte de mi portfolio técnico para especializarme como *Graphics / Engine / Systems Programmer*. El objetivo principal es dominar las APIs explícitas de bajo nivel, la gestión de memoria GPU y la simulación de materiales estilizados en Compute Shaders.

---

## 🎨 Características & Objetivos de Renderizado (NPR Sumi-e)

- **Core de Vulkan 1.3:** Uso nativo de *Dynamic Rendering*, *Synchronization2* y pipelines de cómputo.
- **Gestión de Memoria GPU:** Integración de *Vulkan Memory Allocator (VMA)* para la gestión limpia de Buffers y Texturas.
- **Efecto Tinta & Bordes Orgánicos:** Detección de bordes en espacio de pantalla (filtros Sobel/Laplaciano sobre búferes de Normales/Profundidad) deformados mediante mapas de ruido procedural (Perlin/Simplex).
- **Sumi-e Shading:** Mapeo de iluminación no lineal (Toon/Ramp Shading) con simulación de absorción de tinta y textura de grano de papel.
- **Post-Procesado Multipasada:** Simulación de difusión de pigmentos en acuarela mediante *Compute Shaders*.

---

## 📚 Hoja de Ruta (Roadmap)

- **[x] Fase 0:** Configuración de la infraestructura (CMake, vcpkg, GLFW, spdlog).
- **[ ] Fase 1:** Inicialización de Vulkan 1.3 (Instance, Device, Swapchain, Dynamic Rendering).
- **[ ] Fase 2:** Carga de geometría 3D (glTF) y abstracción de buffers de vértices con VMA.
- **[ ] Fase 3:** Pipeline gráfico básico, cámara interactiva e integración de ImGui.
- **[ ] Fase 4:** Implementación del shader Sumi-e (Bordes de tinta, rampas de color y ruido).
- **[ ] Fase 5:** Profiling de rendimiento en GPU (RenderDoc / NVIDIA Nsight) y optimización.

---

## 🛠️ Stack Tecnológico & Herramientas

- **Lenguaje:** C++20
- **API Gráfica:** Vulkan 1.3 SDK
- **Build System:** CMake (v3.25+)
- **Gestor de Dependencias:** `vcpkg` (Manifest Mode)
- **Ventana y Eventos:** GLFW 3
- **Matemáticas Gráficas:** GLM (OpenGL Mathematics)
- **Gestión de Memoria:** Vulkan Memory Allocator (VMA)
- **Logging:** `spdlog`

---

## 🚀 Compilación y Configuración Local

### Requisitos Previos
- Visual Studio 2022 / 2026 (con la carga de trabajo de C++ y herramientas CMake)
- Vulkan SDK (1.3+)
- Git & vcpkg

### Pasos de Compilación

```bash
# 1. Clonar el repositorio
git clone [https://github.com/Jesus-MartinAnton/Sumi_E_ngine.git](https://github.com/Jesus-MartinAnton/Sumi_E_ngine.git)
cd Sumi_E_ngine

# 2. Abrir la carpeta en Visual Studio o compilar mediante CMake
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[RUTA_A_VCPKG]/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Debug
```

---

## 📜 Licencia
Este proyecto se distribuye bajo la licencia MIT.
