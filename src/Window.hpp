#pragma once
#include <GLFW/glfw3.h>

#include "constants.hpp"
#include "gfx/structs.hpp"
#include "world/Camera.hpp"

namespace goat {

class GameWindow {
   protected:
    GLFWwindow *window;
    uint width;
    uint height;
    bool firstMouse;
    double lastX;
    double lastY;
    float deltaTime;
    float lastFrame;
    std::shared_ptr<world::Camera> camera;

    static void handleKeypress(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void handleMouse(GLFWwindow *window, double xpos, double ypos);
    static void logDriverInfo();

   public:
    GameWindow() : GameWindow("GameWindow") {}
    GameWindow(
        std::string const &window_title,
        gfx::EngineConfig = {gfx::gl::glAPI::OPENGL3_3},
        uint width = gfx::DEFAULT_SCREEN_WIDTH,
        uint height = gfx::DEFAULT_SCREEN_HEIGHT);
    GameWindow(GameWindow &&) = delete;
    GameWindow(const GameWindow &) = delete;
    ~GameWindow() {
        glfwTerminate();
        if (this->camera) this->camera.reset();
    }

    constexpr void createCamera(vec3s start_pos);
    constexpr void setFeature(const gfx::gl::glFeature feature, bool enable = true) const;
    GLFWwindow *getHandle() const;
    const std::shared_ptr<world::Camera> &getCamera() const;
    void loop(std::function<void()> tick_fn);
};

}  // namespace goat
