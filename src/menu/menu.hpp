#pragma once
#include <GLFW/glfw3.h>

namespace goat::menu {

static bool _INITIALIZED = 0;
void init_menu(GLFWwindow* window);

}  // namespace goat::menu