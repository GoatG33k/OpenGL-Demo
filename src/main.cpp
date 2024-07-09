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

    ShaderProgram shaderProg;
    auto vertexShader = new Shader("shaders/basic.vert", GL_VERTEX_SHADER);
    auto fragmentShader = new Shader("shaders/basic.frag", GL_FRAGMENT_SHADER);
    shaderProg.attachShader(vertexShader);
    shaderProg.attachShader(fragmentShader);

    VBO<float> vbo(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
    vbo.bufferData(vertices);
    vbo.setAttributePointer(0, 3, sizeof(float) * 6, 0);
    vbo.setAttributePointer(1, 3, sizeof(float) * 6, 3 * sizeof(float));

    // EBO ebo(indices, GL_STATIC_DRAW);

    shaderProg.link();

    window->loop([&vbo, &shaderProg]()
                 {
                     shaderProg.use();

                     //  float timeValue = glfwGetTime();
                     //  float blueValue = sin(timeValue) / 2.0f + 0.5f;
                     //  int colorUniformLocation = shaderProg.getUniform("color");
                     //  glUniform4f(colorUniformLocation, 1.0f, 0.0f, blueValue, 1.0f);

                     vbo.use();
                     glDrawArrays(GL_TRIANGLES, 0, 3);
                     //  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                     glBindVertexArray(0);
                     // glDrawArrays(GL_TRIANGLES, 0, 3);
                 });
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
