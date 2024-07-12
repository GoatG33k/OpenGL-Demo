#pragma once
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#ifdef __APPLE__
#include <imgui_impl_metal.h>
#endif  // __APPLE__

namespace goat::menu {

static bool _INITIALIZED = 0;
inline void init_menu(GLFWwindow* window);

}  // namespace goat::menu
#include "menu.inl"