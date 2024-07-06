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
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

            glfwWindowHint(GLFW_SAMPLES, 4);
            glEnable(GL_MULTISAMPLE);

            GLFWwindow *_window = glfwCreateWindow(width, height, window_title.c_str(), NULL, NULL);
            if (!_window)
            {
                glfwTerminate();
                throw std::runtime_error("Failed to create GLFW window");
            }

            window = _window;
            glfwMakeContextCurrent(window);
            glViewport(0, 0, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);

            // Resolve OpenGL function pointers once the GLFW window is created
            load_gl_extensions();

            // Support the window being resized
            glfwSetFramebufferSizeCallback(window, &GameWindow::set_framebuffer_size);

            // Handle keypresses
            glfwSetKeyCallback(window, &GameWindow::handle_keypress);
        }

        ~GameWindow()
        {
            glfwTerminate();
        }

        void loop(std::function<void()> tick_fn)
        {
            if (!window)
                throw std::runtime_error("Window not initialized");

            log_driver_info();
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
