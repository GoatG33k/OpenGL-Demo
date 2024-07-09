#include <chrono>

#include "gfx.hpp"
#include "window.hpp"

using namespace std::chrono;

namespace goat
{
    inline void GameWindow::set_framebuffer_size(GLFWwindow *window, int _width, int _height)
    {
        glViewport(0, 0, _width, _height);
    }

    inline void GameWindow::handle_keypress(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        switch (action)
        {
        case GLFW_RELEASE:
            LOG(DEBUG) << "Key released: " << key;
            if (key == GLFW_KEY_D)
            {
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            }
            break;

        case GLFW_PRESS:
            LOG(DEBUG) << "Key pressed: " << key;

            if (key == GLFW_KEY_ESCAPE)
            {
                glfwSetWindowShouldClose(window, true);
            }
            else if (key == GLFW_KEY_D)
            {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            }
            break;
        }
    }

    inline void GameWindow::handle_error(int error, const char *description)
    {
        LOG(ERROR) << "GLFW Error: " << description;
    }

    inline void GameWindow::log_driver_info()
    {
        LOG(WARNING) << "------------------------------------";
        LOG(WARNING) << "OpenGL version: " << glGetString(GL_VERSION);
        LOG(WARNING) << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION);
        LOG(WARNING) << "Vendor: " << glGetString(GL_VENDOR);
        LOG(WARNING) << "Device Name: " << glGetString(GL_RENDERER);
        LOG(WARNING) << "------------------------------------";
    }

    GameWindow::GameWindow(std::string window_title, unsigned int _width, unsigned int _height)
    {
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

        // Register an error callback to GLFW
        glfwSetErrorCallback(&handle_error);

        // Create a new GLFW window
        window = glfwCreateWindow(_width, _height, window_title.c_str(), NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }
        glfwMakeContextCurrent(window);
        LOG(TRACE) << "glfwMakeContextCurrent(window) called";

        // Support the window being resized
        glfwSetFramebufferSizeCallback(window, &GameWindow::set_framebuffer_size);
        LOG(DEBUG) << "glfwSetFramebufferSizeCallback called";

        // Handle keypresses
        glfwSetKeyCallback(window, &GameWindow::handle_keypress);
        LOG(DEBUG) << "glfwSetKeyCallback called";
    }

    GameWindow::~GameWindow()
    {
        glfwTerminate();
    }

    void GameWindow::loop(std::function<void()> tick_fn)
    {
        GameWindow::log_driver_info();
        if (!window)
        {
            LOG(ERROR) << "Window is null!";
            return;
        }

        LOG(INFO) << "Starting game loop...";
        while (!glfwWindowShouldClose(window))
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            tick_fn();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwPollEvents();
    }

    GLFWwindow *GameWindow::get_window()
    {
        return window;
    }
}
