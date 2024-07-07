#include <GLFW/glfw3.h>
#include "easylogging++.h"
#include <chrono>

using namespace std::chrono;

namespace goat
{
    static const int DEFAULT_SCREEN_WIDTH = 1600;
    static const int DEFAULT_SCREEN_HEIGHT = 900;

    class GameWindow
    {
    private:
        static void set_framebuffer_size(GLFWwindow *window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }

        static void handle_keypress(GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            switch (action)
            {
            case GLFW_RELEASE:
                LOG(DEBUG) << "Key released: " << key;
                break;

            case GLFW_PRESS:
                LOG(DEBUG) << "Key pressed: " << key;

                if (key == GLFW_KEY_ESCAPE)
                {
                    glfwSetWindowShouldClose(window, true);
                }
                break;
            }
        }

        static void log_driver_info()
        {
            LOG(WARNING) << "------------------------------------";
            LOG(WARNING) << "OpenGL version: " << glGetString(GL_VERSION);
            LOG(WARNING) << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION);
            LOG(WARNING) << "Vendor: " << glGetString(GL_VENDOR);
            LOG(WARNING) << "Device Name: " << glGetString(GL_RENDERER);
            LOG(WARNING) << "------------------------------------";
        }

        GLFWwindow *window;

    public:
        GameWindow(
            std::string window_title = "GameWindow",
            unsigned int width = DEFAULT_SCREEN_WIDTH,
            unsigned int height = DEFAULT_SCREEN_HEIGHT)
        {
            if (!glfwInit())
                throw std::runtime_error("Failed to initialize GLFW");

            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#ifndef MACOS
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
            glfwWindowHint(GLFW_SAMPLES, 4);

            GLFWwindow *_window = glfwCreateWindow(width, height, window_title.c_str(), NULL, NULL);
            if (!_window)
            {
                glfwTerminate();
                throw std::runtime_error("Failed to create GLFW window");
            }

            window = _window;
            glfwMakeContextCurrent(window);
            LOG(DEBUG) << "glfwMakeContextCurrent(window) called";

            glViewport(0, 0, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
            LOG(DEBUG) << "glViewport set";

            // Resolve OpenGL function pointers once the GLFW window is created
            load_gl_extensions();
            LOG(DEBUG) << "load_gl_extensions called";

            // Support the window being resized
            glfwSetFramebufferSizeCallback(window, &GameWindow::set_framebuffer_size);
            LOG(DEBUG) << "glfwSetFramebufferSizeCallback called";

            // Handle keypresses
            glfwSetKeyCallback(window, &GameWindow::handle_keypress);
            LOG(DEBUG) << "glfwSetKeyCallback called";
        }

        ~GameWindow()
        {
            glfwTerminate();
        }

        void loop(std::function<void()> tick_fn)
        {
            if (!window)
            {
                LOG(ERROR) << "Window is null!";
                return;
            }
            LOG(INFO) << "::loop invoked";

            GameWindow::log_driver_info();
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
            delete this;
        }

        GLFWwindow *get_window()
        {
            return window;
        }
    };
}
