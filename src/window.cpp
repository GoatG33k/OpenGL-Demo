#include "window.hpp"

#include <assert.h>

#include <chrono>

using namespace std::chrono;

namespace goat {

// I'm sorry for my sins...
static GameWindow *CURRENT_GAME_WINDOW = nullptr;

GameWindow::GameWindow(std::string window_title, unsigned int _width, unsigned int _height) {
    assert(CURRENT_GAME_WINDOW == nullptr);
    CURRENT_GAME_WINDOW = this;

    if (_width <= 0 || _height <= 0)
        throw std::runtime_error("Invalid window dimensions provided");

    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    width = _width;
    height = _height;

    LOG(INFO) << "Requesting OpenGL 3.3+ Core Profile...";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // TODO: abstract this out into a
    LOG(INFO) << "Requesting 4x MSAA...";
    glfwWindowHint(GLFW_SAMPLES, 4);

    // Create a new GLFW window
    window = glfwCreateWindow(_width, _height, window_title.c_str(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);
    LOG(TRACE) << "glfwMakeContextCurrent(window) called";

    // Support the window being resized
    glfwSetFramebufferSizeCallback(window,
                                   [](GLFWwindow *window, int width, int height) { glViewport(0, 0, width, height); });
    LOG(DEBUG) << "glfwSetFramebufferSizeCallback called";

    // Handle keypresses
    glfwSetKeyCallback(window, handleKeypress);
    LOG(DEBUG) << "glfwSetKeyCallback called";
}

void GameWindow::loop(std::function<void()> tick_fn) {
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

}  // namespace goat
