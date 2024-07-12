#include "menu.hpp"

namespace goat::menu {

inline void init_menu(GLFWwindow *window) {
    assert(!_INITIALIZED);
    _INITIALIZED = true;
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();
}

}  // namespace goat::menu