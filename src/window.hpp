#pragma once
#include <GLFW/glfw3.h>

#include "constants.hpp"
#include "gfx/structs.hpp"
#include "world/Camera.hpp"

namespace goat {

class GameWindow {
   private:
    typedef uint uint;

   protected:
    GLFWwindow *window;
    uint width;
    uint height;
    float deltaTime;
    float lastFrame;
    world::Camera *camera = nullptr;

    static void handleKeypress(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void logDriverInfo();

   public:
    GameWindow(std::string window_title = "GameWindow", gfx::EngineConfig = {gfx::gl::glAPI::OPENGL3_3},
               uint width = gfx::DEFAULT_SCREEN_WIDTH, uint height = gfx::DEFAULT_SCREEN_HEIGHT);
    ~GameWindow() {
        glfwTerminate();
        if (this->camera)
            delete this->camera;
    }

    void createCamera(glm::vec3 start_pos = world::CAMERA_DEFAULT_POS);
    void setFeature(gfx::gl::glFeature feature, bool enable = true);
    GLFWwindow *getHandle() const;
    world::Camera *getCamera() const;
    void loop(std::function<void()> tick_fn);
};

}  // namespace goat
