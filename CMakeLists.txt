# Project details
cmake_minimum_required(VERSION 3.5)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
project(GameDemo VERSION 1.0 LANGUAGES CXX C)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# if(APPLE)
# enable_language(OBJCXX)
# endif()
include_directories(src)

# Import OpenGL
find_package(OpenGL REQUIRED)
include_directories(include/glad/include)
add_compile_definitions(GL_SILENCE_DEPRECATION)

# Import GLAD
add_library(GLAD include/glad/src/glad.c)
target_link_libraries(GLAD OpenGL::GL)

# Import glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(vendor/glfw/include)
add_subdirectory(vendor/glfw)
add_compile_definitions(GLFW_INCLUDE_GLEXT)

# Header-only dependencies
include_directories(vendor/stb)
include_directories(vendor/opengl/api)

# Include ImGUI
add_library(ImGUI
    "vendor/imgui/imgui.cpp"
    "vendor/imgui/imgui_demo.cpp"
    "vendor/imgui/imgui_draw.cpp"
    "vendor/imgui/imgui_widgets.cpp"
    "vendor/imgui/imgui_tables.cpp"
    "vendor/imgui/misc/cpp/imgui_stdlib.cpp"
    "vendor/imgui/backends/imgui_impl_glfw.cpp"
    "vendor/imgui/backends/imgui_impl_metal.mm"
    "vendor/imgui/backends/imgui_impl_opengl3.cpp"
)
include_directories(vendor/imgui vendor/imgui/backends)

# Import easylogging++
add_library(easyloggingpp
    "vendor/easyloggingpp/src/easylogging++.h"
    "vendor/easyloggingpp/src/easylogging++.cc")
include_directories(vendor/easyloggingpp/src)

if(MSVC)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif()

if(WIN32)
    add_compile_definitions(__WIN32__)
elseif(LINUX)
    add_compile_definitions(__LINUX__)
elseif(APPLE)
    add_compile_definitions(__APPLE__)
endif()

# Assign source files and target output
set(DEMO_SRC
    src/texture.cpp
    src/main.cpp
    src/window.cpp
    src/gfx.cpp
)

add_executable(GameDemo ${INCLUDE_SRC} ${DEMO_SRC})
add_dependencies(GameDemo glfw)
target_link_libraries(GameDemo
    PRIVATE OpenGL::GL
    PRIVATE GLAD
    PRIVATE glfw
    PRIVATE ImGUI
    PRIVATE easyloggingpp
)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra")
set(DEBUG_FLAGS "-g")
set(RELEASE_FLAGS "-O3")
target_compile_options(GameDemo PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_FLAGS}>")
target_compile_options(GameDemo PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_FLAGS}>")

# if( MSVC )
# if(${CMAKE_VERSION} VERSION_LESS "3.6.0")
# message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'GLFW-CMake-starter' as StartUp Project in Visual Studio.\n" )
# else()
# set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GameDemo )
# endif()
# endif()
