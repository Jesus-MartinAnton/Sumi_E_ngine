cmake_minimum_required(VERSION 3.25)

# Definir el proyecto y la versión de C++
project(SumiEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Buscar Vulkan SDK
find_package(Vulkan REQUIRED)

# Buscar librerías instaladas por vcpkg
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(VulkanMemoryAllocator CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# Incluir la carpeta src para poder hacer #include "engine/VulkanEngine.hpp"
include_directories(src)

# Recopilar todos los archivos .cpp y .hpp en src/
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.hpp")

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Enlazar las librerías con tu motor
target_link_libraries(${PROJECT_NAME} PRIVATE
    Vulkan::Vulkan
    glfw
    glm::glm
    GPUOpen::VulkanMemoryAllocator
    spdlog::spdlog
)