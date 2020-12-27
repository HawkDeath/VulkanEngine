cmake_minimum_required(VERSION 3.10)
project(VulkanEngine)

include_directories(${CMAKE_SOURCE_DIR}/3part)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/common)
include_directories(${CMAKE_SOURCE_DIR}/renderer)
include_directories(${CMAKE_SOURCE_DIR}/window)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(COMMON_SRC
              common/Profiler.cpp
              common/Utils.cpp)

set(RENDERER_SRC
                renderer/VulkanDevice.cpp)

set(WINDOW_SRC 
              window/Input.cpp
              window/Window.cpp)

add_executable(${PROJECT_NAME} ${COMMON_SRC} ${WINDOW_SRC} ${RENDERER_SRC} Engine.cpp main.cpp)
target_link_libraries(${PROJECT_NAME} vulkan glm spdlog_header_only glfw EnTT)