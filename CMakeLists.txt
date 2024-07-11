# Project details
cmake_minimum_required(VERSION 3.5)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
project(GameDemo VERSION 1.0 LANGUAGES CXX C)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Hardening compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=implicit -Werror=incompatible-pointer-types -Werror=int-conversion -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FORTIFY_SOURCE=3 -D_GLIBCXX_ASSERTIONS")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector-strong -mbranch-protection=standard -fexceptions")

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,-z,nodlopen -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now")
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # message(STATUS "GCC compiler detected")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wtrampolines -Wbidi-chars=any")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstrict-flex-arrays=3 -fstack-clash-protection")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIE -pie -fhardened")
endif()

if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
    message(STATUS "x86_64 detected")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcf-protection=full")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "(arm)|(ARM)")
    message(STATUS "ARM detected")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mbranch-protection=standard")
endif()

if(CMAKE_BUILD_TYPE MATCHES "Release")
    message(STATUS "Targeting Release build")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-delete-null-pointer-checks -fno-strict-overflow -fno-strict-aliasing -ftrivial-auto-var-init=zero")
endif()

include_directories(src)

# Import OpenGL
find_package(OpenGL REQUIRED)
include_directories(include/glad/include)
add_compile_definitions(GL_SILENCE_DEPRECATION)

# Import GLAD
set(GLAD_SRC "include/glad/src/gl.c" "include/glad/src/vulkan.c")
add_library(GLAD ${GLAD_SRC})
target_link_libraries(GLAD OpenGL::GL)

# Import glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(vendor/glfw/include)
add_subdirectory(vendor/glfw)
add_compile_definitions(GLFW_INCLUDE_GLEXT)

# Header-only dependencies
include_directories(vendor/glm)
include_directories(vendor/gli)
include_directories(vendor/opengl/api)

# Include ImGUI
set(IMGUI_SRC
    "vendor/imgui/imgui.cpp"
    "vendor/imgui/imgui_demo.cpp"
    "vendor/imgui/imgui_draw.cpp"
    "vendor/imgui/imgui_widgets.cpp"
    "vendor/imgui/imgui_tables.cpp"
    "vendor/imgui/misc/cpp/imgui_stdlib.cpp"
    "vendor/imgui/backends/imgui_impl_glfw.cpp"
    "vendor/imgui/backends/imgui_impl_opengl3.cpp"
)

if(APPLE)
    set(IMGUI_SRC ${IMGUI_SRC} "vendor/imgui/backends/imgui_impl_metal.mm")
endif()

add_library(ImGUI ${IMGUI_SRC})
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
    src/texture.hpp
    src/texture.cpp
    src/main.cpp
    src/window.hpp
    src/window.cpp
    src/gfx.hpp
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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
endif()

set(DEBUG_FLAGS "-g")
set(RELEASE_FLAGS "-O3")
target_compile_options(GameDemo PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_FLAGS}>")
target_compile_options(GameDemo PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_FLAGS}>")

message(NOTICE "CMAKE_BUILD_TYPE => ${CMAKE_BUILD_TYPE}")
message(NOTICE "CMAKE_CXX_FLAGS  => ${CMAKE_CXX_FLAGS}")

# if( MSVC )
# if(${CMAKE_VERSION} VERSION_LESS "3.6.0")
# message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'GLFW-CMake-starter' as StartUp Project in Visual Studio.\n" )
# else()
# set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GameDemo )
# endif()
# endif()
