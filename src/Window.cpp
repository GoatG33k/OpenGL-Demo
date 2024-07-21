#include "./Window.hpp"

#include <assert.h>

#include <chrono>

#include "menu/menu.hpp"

using namespace std::chrono;

namespace goat {

std::vector<int> _gl_target_to_version(gfx::gl::glAPI target);

// I'm sorry, the memory boundaries made me do it...
static GameWindow *CURRENT_GAME_WINDOW = nullptr;

GameWindow::GameWindow(
    std::string const &window_title, gfx::EngineConfig config, uint width, uint height)
    : window(0U),
      width(0U),
      height(0U),
      firstMouse(true),
      lastX(0.0),
      lastY(0.0),
      deltaTime(0.0f),
      lastFrame(0.0f) {
    // Set global window instance
    assert(CURRENT_GAME_WINDOW == nullptr);
    CURRENT_GAME_WINDOW = this;

    if (width <= 0 || height <= 0) {
        std::stringstream err;
        err << "Invalid window dimensions provided (" << width << "x" << height << ")";
        throw std::runtime_error(err.str());
    }

    if (!glfwInit()) throw std::runtime_error("Failed to initialize GLFW");

    // Set the OpenGL version
    auto version = _gl_target_to_version(config.gl_target);
    assert(version.size() == 2);

    int major = version[0];
    int minor = version[1];
    LOG(DEBUG) << "Requesting OpenGL " << major << "." << minor << " ("
               << (config.compat ? "compat" : "core") << ")";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version[0]);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version[1]);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    LOG(INFO) << "OpenGL forward compatibility enabled";
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create a new GLFW window
    this->window = glfwCreateWindow(width, height, window_title.c_str(), nullptr, nullptr);
    if (this->window) {
        glfwMakeContextCurrent(this->window);
        glfwSetKeyCallback(this->window, handleKeypress);
        glfwSetFramebufferSizeCallback(this->window, [](GLFWwindow *window, int width, int height) {
            glViewport(0, 0, width, height);
        });

        // Initialize ImGUI
        goat::menu::init_menu(this->window);
    } else {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
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

#ifdef __DEBUG__
        auto startTime = high_resolution_clock::now();
#endif
        tick_fn();
#ifdef __DEBUG__
        auto endTime = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(endTime - startTime);
        LOG(DEBUG) << "Game loop took " << duration.count() << " ms";
#endif

        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }

    glfwPollEvents();
}

void GameWindow::handleMouse(GLFWwindow *_glfwWindow, double xpos, double ypos) {
    assert(CURRENT_GAME_WINDOW != nullptr);
    auto window = CURRENT_GAME_WINDOW;

    if (window->camera) {
        // window->camera->turn()
    }
}

void GameWindow::handleKeypress(
    GLFWwindow *_glfwWindow, int key, int scancode, int action, int mods) {
    assert(CURRENT_GAME_WINDOW != nullptr);
    auto window = static_cast<GameWindow *>(CURRENT_GAME_WINDOW);

    LOG(INFO) << "KEYPRESS = " << key << " (ACTION = " << action << ")";
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(CURRENT_GAME_WINDOW->window, true);
    } else if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        if (key == GLFW_KEY_W) {
            window->camera->walk(world::Direction::FORWARD, window->deltaTime);
        } else if (key == GLFW_KEY_S) {
            window->camera->walk(world::Direction::BACKWARD, window->deltaTime);
        } else if (key == GLFW_KEY_A) {
            window->camera->walk(world::Direction::LEFT, window->deltaTime);
        } else if (key == GLFW_KEY_D) {
            window->camera->walk(world::Direction::RIGHT, window->deltaTime);
        }
    }
}

constexpr void GameWindow::createCamera(vec3s start_pos = world::getCameraDefaultPos()) {
    if (this->camera) throw std::runtime_error("Camera already set!");
    this->camera = std::make_shared<world::Camera>(start_pos);
    LOG(DEBUG) << "Created camera for GameWindow " << this;
}

constexpr void GameWindow::setFeature(const gfx::gl::glFeature feature, bool enable) const {
    if (enable) {
        glEnable(static_cast<GLenum>(feature));
    } else {
        glDisable(static_cast<GLenum>(feature));
    }
}

const std::shared_ptr<world::Camera> &GameWindow::getCamera() const {
    assert(this->camera != nullptr);
    return this->camera;
}

GLFWwindow *GameWindow::getHandle() const { return this->window; }

void GameWindow::logDriverInfo() {
    LOG(INFO) << "------------------------------------";
    LOG(INFO) << "OpenGL version: " << glGetString(GL_VERSION);
    LOG(INFO) << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION);
    LOG(INFO) << "Vendor: " << glGetString(GL_VENDOR);
    LOG(INFO) << "Device Name: " << glGetString(GL_RENDERER);
    LOG(INFO) << "------------------------------------";
}

// Utilities
inline std::vector<int> _gl_target_to_version(gfx::gl::glAPI target) {
    switch (target) {
        case gfx::gl::glAPI::OPENGL2_0:
            return {2, 0};
        case gfx::gl::glAPI::OPENGL3_0:
            return {3, 0};
        case gfx::gl::glAPI::OPENGL3_3:
            return {3, 3};
        case gfx::gl::glAPI::OPENGL4_0:
            return {4, 0};
        case gfx::gl::glAPI::OPENGL4_1:
            return {4, 1};
        case gfx::gl::glAPI::OPENGL4_2:
            return {4, 2};
        case gfx::gl::glAPI::OPENGL4_3:
            return {4, 3};
        case gfx::gl::glAPI::OPENGL4_4:
            return {4, 4};
        case gfx::gl::glAPI::OPENGL4_5:
            return {4, 5};
        default:
            throw std::runtime_error("Invalid OpenGL target");
    }
}

}  // namespace goat
