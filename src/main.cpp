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

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <gfx.hpp>
#include <window.hpp>

using namespace std;
using namespace std::chrono;
using namespace goat;
using namespace goat::gfx;

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

const float vertices[]{
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f};
const vector<float> verticesVec{
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f};

inline void run_game()
{
    glfwSetErrorCallback([](int error, const char *description)
                         { LOG(ERROR) << "Fatal Error: " << description; });

    GameWindow *window = new GameWindow("Hello, World!");

    // Load GLAD
    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0)
    {
        throw std::runtime_error("Failed to load OpenGL functions via GLAD");
    }

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
    LOG(INFO) << "glDeleteShader - cleaned up shaders";

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    LOG(INFO) << "glGenVertexArrays called";
    glGenBuffers(1, &vbo);
    LOG(INFO) << "glGenBuffers called";
    glBindVertexArray(vao);
    LOG(INFO) << "glBindVertexArray called";
    LOG(INFO) << "Created VAO and VBO";

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    LOG(INFO) << "Bound vertex data to VAO and VBO";

    window->loop([vao, shaderProgram]()
                 { 
                    // glViewport(0, 0, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
                    glUseProgram(shaderProgram);
                    glBindVertexArray(vao);
                    glDrawArrays(GL_TRIANGLES, 0, 3); });

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(shaderProgram);
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
