#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP

// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <constants.hpp>
#include <gfx.hpp>
#include <texture.hpp>
#include <window.hpp>
#include <world.hpp>
// clang-format on

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#ifdef __APPLE__
#include <imgui_impl_metal.h>
#endif  // __APPLE__

#include <gli/gli.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace std::chrono;
using namespace goat;
using namespace goat::gfx;

// [4][4][4][4][4]
// \-------/\----/
//  pos[12]  tex[8]
//
const vector<float> vertices{
    -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.5f,  -0.5f, -0.5f, 1.0f,  0.0f,  0.5f,  0.5f,  -0.5f, 1.0f,  1.0f,  0.5f,
    0.5f,  -0.5f, 1.0f,  1.0f,  -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  -0.5f, -0.5f,
    0.5f,  0.0f,  0.0f,  0.5f,  -0.5f, 0.5f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  1.0f,  0.5f,  0.5f,  0.5f,
    1.0f,  1.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  1.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  1.0f,
    0.0f,  -0.5f, 0.5f,  -0.5f, 1.0f,  1.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,
    -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.5f,
    0.5f,  -0.5f, 1.0f,  1.0f,  0.5f,  -0.5f, -0.5f, 0.0f,  1.0f,  0.5f,  -0.5f, -0.5f, 0.0f,  1.0f,  0.5f,  -0.5f,
    0.5f,  0.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  0.5f,  -0.5f, -0.5f,
    1.0f,  1.0f,  0.5f,  -0.5f, 0.5f,  1.0f,  0.0f,  0.5f,  -0.5f, 0.5f,  1.0f,  0.0f,  -0.5f, -0.5f, 0.5f,  0.0f,
    0.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.5f,  0.5f,  -0.5f, 1.0f,  1.0f,
    0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  -0.5f,
    0.5f,  -0.5f, 0.0f,  1.0f

};

const vector<unsigned int> indices{0, 1, 3, 1, 2, 3};
const glm::vec3 cubePositions[] = {glm::vec3(0.0f, 0.0f, 0.0f),    glm::vec3(2.0f, 5.0f, -15.0f),
                                   glm::vec3(-1.5f, -2.2f, -2.5f), glm::vec3(-3.8f, -2.0f, -12.3f),
                                   glm::vec3(2.4f, -0.4f, -3.5f),  glm::vec3(-1.7f, 3.0f, -7.5f),
                                   glm::vec3(1.3f, -2.0f, -2.5f),  glm::vec3(1.5f, 2.0f, -2.5f),
                                   glm::vec3(1.5f, 0.2f, -1.5f),   glm::vec3(-1.3f, 1.0f, -1.5f)};

inline void run_game() {
    glfwSetErrorCallback([](int error, const char *description) {
        LOG(ERROR) << "Fatal Error: " << description << "(Code " << error << ")";
    });

    unique_ptr<GameWindow> window = make_unique<GameWindow>("Hello, World!");
    window->createCamera();

    // Load GLAD
    if (!gladLoadGL(glfwGetProcAddress))
        throw std::runtime_error("Failed to load OpenGL functions via GLAD");

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    // ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui_ImplGlfw_InitForOpenGL(window->get_window(), true);
    ImGui_ImplOpenGL3_Init();

    ShaderProgram shaderProg{};
    Shader vertexShader{"shaders/basic.vert", ShaderType::VERTEX};
    Shader fragmentShader{"shaders/basic.frag", ShaderType::FRAGMENT};
    shaderProg.attachShader(&vertexShader);
    shaderProg.attachShader(&fragmentShader);

    // Let our fancy code calculate the attribute pointer bounds, stride, and
    // offset magically!
    auto vbo = new VBO<float>(BufferType::ARRAY, DrawType::STATIC, DataType::FLOAT, indices);
    vbo->addAttributeBound(0, 3);  // XYZ
    vbo->addAttributeBound(1, 2);  // TEX
    vbo->applyAttributeBounds(vertices);

    RenderContext ctx{};
    ctx.add(vbo);
    ctx.add(&shaderProg);

    // Textures!
    Texture happy{"textures/gaga.dds"};
    ctx.add(&happy);

    shaderProg.use();
    fragmentShader.setInt("texture1", 0);

    // Create 3D world space
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.f / 600.f, 0.1f, 100.0f);

    auto camera = window->getCamera();

    window->loop([&vertexShader, &model, &camera, &projection, &vbo, &shaderProg, &happy, &ctx]() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        // ImGui::ShowDemoWindow();

        ctx.render();

        // vertexShader.setMatrix("model", static_cast<float *>(glm::value_ptr(model)), 4);
        const float radius = 10.0f;

        float camX = sin(glfwGetTime()) * radius;
        float camZ = cos(glfwGetTime()) * radius;

        vertexShader.setMatrix("view", static_cast<float *>(glm::value_ptr(camera->view)), 4);
        vertexShader.setMatrix("projection", static_cast<float *>(glm::value_ptr(projection)), 4);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, happy.getID());

        shaderProg.use();

        for (auto i = 0; i < 10; i++) {
            vbo->use();
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);

            float angle = 1.0f * (i + 1);
            model = glm::rotate(model, glm::radians((float)glfwGetTime() * angle), glm::vec3(1.0f, 0.3f, 0.5f));
            vertexShader.setMatrix("model", static_cast<float *>(glm::value_ptr(model)), 4);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glDrawArrays(GL_TRIANGLES, 0, 36);

        glBindVertexArray(0);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    });

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

int main(int argc, char *argv[]) {
    {  // Configure logging runtime
        START_EASYLOGGINGPP(argc, argv);
        el::Configurations defaultConf;
        defaultConf.set(el::Level::Global, el::ConfigurationType::Format, "%datetime %level %msg");
        el::Loggers::reconfigureAllLoggers(defaultConf);
    }

    try {
        run_game();
        return 0;
    } catch (const std::exception &e) {
        LOG(ERROR) << e.what();
        return 1;
    }
}
