#pragma once

#include <GLFW/glfw3.h>
#include <easylogging++.h>

#include <string>

#include "constants.hpp"
#include "world.hpp"

namespace goat {
class GameWindow {
   protected:
    unsigned int width;
    unsigned int height;
    float deltaTime;
    float lastFrame;
    GLFWwindow *window;
    camera::Camera *camera = nullptr;

    static inline void handleKeypress(GLFWwindow *window, int key, int scancode, int action, int mods);
    static inline void logDriverInfo() {
        LOG(INFO) << "------------------------------------";
        LOG(INFO) << "OpenGL version: " << glGetString(GL_VERSION);
        LOG(INFO) << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION);
        LOG(INFO) << "Vendor: " << glGetString(GL_VENDOR);
        LOG(INFO) << "Device Name: " << glGetString(GL_RENDERER);
        LOG(INFO) << "------------------------------------";
    }

   public:
    GameWindow(std::string window_title = "GameWindow", unsigned int _width = goat::gfx::DEFAULT_SCREEN_WIDTH,
               unsigned int _height = goat::gfx::DEFAULT_SCREEN_HEIGHT);
    inline ~GameWindow() {
        glfwTerminate();
    }

    inline GLFWwindow *get_window() const {
        return this->window;
    }

    inline void createCamera(glm::vec3 start_pos = camera::CAMERA_DEFAULT_POS) {
        if (this->camera)
            throw std::runtime_error("Camera already set!");
        this->camera = new camera::Camera(start_pos);
        LOG(DEBUG) << "Created camera for GameWindow " << this;
    }

    constexpr camera::Camera *getCamera() const {
        assert(this->camera != nullptr);
        return this->camera;
    }
    void loop(std::function<void()> tick_fn);
};
}  // namespace goat