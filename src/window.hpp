#pragma once

#include <string>
#include <GLFW/glfw3.h>
#include <easylogging++.h>

namespace goat
{
    class GameWindow
    {
    protected:
        unsigned int width;
        unsigned int height;
        GLFWwindow *window;

        static inline void set_framebuffer_size(GLFWwindow *window, int _width, int _height);
        static inline void handle_keypress(GLFWwindow *window, int key, int scancode, int action, int mods);
        static inline void handle_error(int error, const char *description);
        static inline void log_driver_info();

    public:
        GameWindow(
            std::string window_title = "GameWindow",
            unsigned int _width = goat::gfx::DEFAULT_SCREEN_WIDTH,
            unsigned int _height = goat::gfx::DEFAULT_SCREEN_HEIGHT);
        ~GameWindow();

        void loop(std::function<void()> tick_fn);
        GLFWwindow *get_window();
    };
}