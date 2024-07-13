#include <assert.h>

#include <chrono>

#include "gfx.hpp"
#include "menu.hpp"
#include "window.hpp"

using namespace std::chrono;

namespace goat {
inline std::vector<int> _gl_target_to_version(gfx::gl::glAPI target);

// I'm sorry, the memory boundaries made me do it...
static GameWindow *CURRENT_GAME_WINDOW = nullptr;

GameWindow::GameWindow(std::string window_title, gfx::EngineConfig config, uint width, uint height)
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

    // Set the OpenGL version
    auto version = _gl_target_to_version(config.gl_target);
    assert(version.size() == 2);

    int major = version[0];
    int minor = version[1];
    LOG(DEBUG) << "Requesting OpenGL " << major << "." << minor << " (" << (config.compat ? "compat" : "core") << ")";
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
        glfwSetFramebufferSizeCallback(
            this->window, [](GLFWwindow *window, int width, int height) { glViewport(0, 0, width, height); });

        // Initialize ImGUI
        goat::menu::init_menu(this->window);
    } else {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
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

constexpr inline void GameWindow::setFeature(gfx::gl::glFeature feature, bool enable) {
    if (enable) {
        glEnable(static_cast<GLenum>(feature));
    } else {
        glDisable(static_cast<GLenum>(feature));
    }
}

constexpr inline camera::Camera *GameWindow::getCamera() const {
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
