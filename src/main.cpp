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

// [4][4][4][4][4][4]
// \-------/\-------/
//  pos[12]  rgb[12]
//
// stride = 24
// colorOffset = 12
const vector<float> vertices{
    0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
    0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
};

const vector<unsigned int> indices{
    0, 1, 3,
    1, 2, 3};

inline void run_game()
{
    glfwSetErrorCallback([](int error, const char *description)
                         { LOG(ERROR) << "Fatal Error: " << description; });

    GameWindow *window = new GameWindow("Hello, World!");

    // Load GLAD
    if (gladLoadGL() == 0)
        throw std::runtime_error("Failed to load OpenGL functions via GLAD");

    auto shaderProg = new ShaderProgram();
    auto vertexShader = new Shader("shaders/basic.vert", ShaderType::VERTEX);
    auto fragmentShader = new Shader("shaders/basic.frag", ShaderType::FRAGMENT);
    shaderProg->attachShader(vertexShader);
    shaderProg->attachShader(fragmentShader);

    // Let our fancy code calculate the attribute pointer bounds, stride, and offset magically!
    auto vbo = new VBO<float>(BufferType::ARRAY, DrawType::STATIC, DataType::FLOAT);
    vbo->addAttributeBound(0, 3);
    vbo->addAttributeBound(1, 3);
    vbo->applyAttributeBounds(vertices);

    auto ctx = new RenderContext();
    ctx->add(vbo);
    ctx->add(shaderProg);

    shaderProg->link();
    window->loop([&ctx, &vbo, &shaderProg]()
                 {
                     ctx->render();
                     shaderProg->use();
                     vbo->use();
                     glDrawArrays(GL_TRIANGLES, 0, 3);
                     glBindVertexArray(0); });
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
