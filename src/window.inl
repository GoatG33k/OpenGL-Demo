#include <assert.h>

#include <chrono>

#include "gfx.hpp"
#include "window.hpp"

using namespace std::chrono;

namespace goat {

// I'm sorry, the memory boundaries made me do it...
static GameWindow *CURRENT_GAME_WINDOW = nullptr;

GameWindow::GameWindow(std::string window_title, gfx::glTarget gl_target, unsigned int width, unsigned int height)
    : window(0U), width(0U), height(0U), deltaTime(0.0f), lastFrame(0.0f) {
    assert(CURRENT_GAME_WINDOW == nullptr);
    CURRENT_GAME_WINDOW = this;

    if (width <= 0 || height <= 0) {
        std::stringstream err;
        err << "Invalid window dimensions provided (" << width << "x" << height << ")";
        throw std::runtime_error(err.str());
    }

    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    LOG(INFO) << "Requesting OpenGL 3.3+ Core Profile...";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    LOG(INFO) << "Requesting 4x MSAA...";
    glfwWindowHint(GLFW_SAMPLES, 4);

    // Create a new GLFW window
    this->window = glfwCreateWindow(width, height, window_title.c_str(), nullptr, nullptr);
    if (!this->window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(this->window);
    LOG(TRACE) << "glfwMakeContextCurrent(window) called";

    // Support the window being resized
    glfwSetFramebufferSizeCallback(this->window,
                                   [](GLFWwindow *window, int width, int height) { glViewport(0, 0, width, height); });
    LOG(DEBUG) << "glfwSetFramebufferSizeCallback called";

    // Handle keypresses
    glfwSetKeyCallback(this->window, handleKeypress);
    LOG(DEBUG) << "glfwSetKeyCallback called";
}

inline void GameWindow::loop(std::function<void()> tick_fn) {
    assert(!!this->window);
    this->logDriverInfo();

    LOG(INFO) << "Starting game loop...";
    while (!glfwWindowShouldClose(this->window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float currentFrame = glfwGetTime();
        this->deltaTime = currentFrame - this->lastFrame;
        this->lastFrame = currentFrame;

        tick_fn();

        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }

    glfwPollEvents();
}

inline void GameWindow::handleKeypress(GLFWwindow *_glfwWindow, int key, int scancode, int action, int mods) {
    assert(CURRENT_GAME_WINDOW != nullptr);
    auto window = static_cast<GameWindow *>(CURRENT_GAME_WINDOW);

    LOG(INFO) << "KEYPRESS = " << key << " (ACTION = " << action << ")";
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(CURRENT_GAME_WINDOW->window, true);
    } else if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        if (key == GLFW_KEY_W) {
            window->camera->move(camera::Direction::FORWARD, window->deltaTime);
        } else if (key == GLFW_KEY_S) {
            window->camera->move(camera::Direction::BACKWARD, window->deltaTime);
        } else if (key == GLFW_KEY_A) {
            window->camera->move(camera::Direction::LEFT, window->deltaTime);
        } else if (key == GLFW_KEY_D) {
            window->camera->move(camera::Direction::RIGHT, window->deltaTime);
        }
    }
}

inline void GameWindow::createCamera(glm::vec3 start_pos) {
    if (this->camera)
        throw std::runtime_error("Camera already set!");
    this->camera = new camera::Camera(start_pos);
    LOG(DEBUG) << "Created camera for GameWindow " << this;
}

constexpr camera::Camera *GameWindow::getCamera() const {
    assert(this->camera != nullptr);
    return this->camera;
}

constexpr inline GLFWwindow *GameWindow::getHandle() const {
    return this->window;
}

inline void GameWindow::logDriverInfo() {
    LOG(INFO) << "------------------------------------";
    LOG(INFO) << "OpenGL version: " << glGetString(GL_VERSION);
    LOG(INFO) << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION);
    LOG(INFO) << "Vendor: " << glGetString(GL_VENDOR);
    LOG(INFO) << "Device Name: " << glGetString(GL_RENDERER);
    LOG(INFO) << "------------------------------------";
}

}  // namespace goat
