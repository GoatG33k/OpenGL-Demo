#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <gfx.hpp>
#include <window.hpp>

using namespace std;
using namespace std::chrono;
using namespace goat;
using namespace goat::gfx;

const vector<float> vertices{
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f};

inline void run_game()
{
    glfwSetErrorCallback([](int error, const char *description)
                         { LOG(ERROR) << "Fatal Error: " << description; });

    GameWindow *window = new GameWindow("Hello, World!");

    // Load GLAD
    if (gladLoadGL() == 0)
        throw std::runtime_error("Failed to load OpenGL functions via GLAD");

    ShaderProgram shaderProg;
    auto vertexShader = new Shader("shaders/basic.vert", GL_VERTEX_SHADER);
    auto fragmentShader = new Shader("shaders/basic.frag", GL_FRAGMENT_SHADER);
    shaderProg.attachShader(vertexShader);
    shaderProg.attachShader(fragmentShader);
    shaderProg.link();

    VBO vbo(GL_ARRAY_BUFFER, vertices, GL_STATIC_DRAW);

    window->loop([&vbo, &shaderProg]()
                 { 
                    shaderProg.use();
                    vbo.use();
                    glDrawArrays(GL_TRIANGLES, 0, 3); });
}

int main(int argc, char *argv[])
{
    { // Configure logging runtime
        START_EASYLOGGINGPP(argc, argv);
        el::Configurations defaultConf;
        defaultConf.set(el::Level::Global, el::ConfigurationType::Format, "%datetime %level %msg");
        el::Loggers::reconfigureAllLoggers(defaultConf);
    }

    try
    {
        run_game();
        return 0;
    }
    catch (const std::exception &e)
    {
        LOG(ERROR) << e.what();
        return 1;
    }
}
