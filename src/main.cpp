#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

#define GLFW_INCLUDE_GLEXT
#include <GLFW/glfw3.h>
#include "glextloader.c"

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP

// Begin core imports
#include <gfx/gfx.cpp>
#include <window.cpp>
// End core imports

using namespace goat;
using namespace std::chrono;

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                   "}\0";
const float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f};

inline void run_game()
{

    glfwSetErrorCallback([](int error, const char *description)
                         { LOG(ERROR) << "Fatal Error: " << description; });

    GameWindow *window = new GameWindow();

    int success;
    char infoLog[512];

    // Vertex shader
    auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        LOG(ERROR) << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                   << infoLog;
    }

    // Fragment shader
    auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        LOG(ERROR) << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                   << infoLog;
    }

    // Shader program
    auto shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        LOG(ERROR) << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                   << infoLog;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    window->loop([vao, shaderProgram]()
                 { 
                    glUseProgram(shaderProgram);
                    glBindVertexArray(vao);
                    glDrawArrays(GL_TRIANGLES, 0, 3); });

    // glDeleteVertexArrays(1, &vao);
    // glDeleteBuffers(1, &vbo);
    glDeleteProgram(shaderProgram);

    delete window;
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
