# Project details
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
project(GameDemo VERSION 1.0 LANGUAGES CXX)

find_package(OpenGL REQUIRED)
include_directories(src src/gfx)
include_directories(${OPENGL_INCLUDE_DIRS})

# Import GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(vendor/glfw/deps)
add_subdirectory(vendor/glfw)

set(INCLUDE_SRC ${INCLUDE_SRC} "vendor/glad/")
add_compile_definitions(GLFW_INCLUDE_GLEXT)

# Import GLEXT
include_directories(vendor/opengl/api)
set(INCLUDE_SRC ${INCLUDE_SRC} "vendor/opengl/api/GL/glext.h")

# Import EGL-registry
include_directories(vendor/egl/api)

# Import easylogging++
include_directories(vendor/easyloggingpp/src)
set(INCLUDE_SRC ${INCLUDE_SRC}
    "vendor/easyloggingpp/src/easylogging++.h"
    "vendor/easyloggingpp/src/easylogging++.cc"
)

if(MSVC)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif()

# Remove this because its dumb :)
set(CMAKE_BUILD_TYPE Debug)

if(WIN32)
    add_compile_definitions(WIN32)
elseif(LINUX)
    add_compile_definitions(LINUX)
elseif(APPLE)
    add_compile_definitions(MACOS)
endif()

# Assign source files and target output
set(DEMO_SRC
    src/main.cpp
    src/window.cpp
    src/gfx.cpp
)

add_executable(GameDemo ${INCLUDE_SRC} ${DEMO_SRC})
add_dependencies(GameDemo glfw)
target_link_libraries(GameDemo ${OPENGL_LIBRARIES} glfw)

# if( MSVC )
# if(${CMAKE_VERSION} VERSION_LESS "3.6.0")
# message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'GLFW-CMake-starter' as StartUp Project in Visual Studio.\n" )
# else()
# set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GameDemo )
# endif()
# endif()
