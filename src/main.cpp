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

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#undef STB_IMAGE_IMPLEMENTATION

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <constants.hpp>
#include <gfx.hpp>
#include <texture.hpp>
#include <window.hpp>
// clang-format on

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#ifdef __APPLE__
#include <imgui_impl_metal.h>
#endif  // __APPLE__

using namespace std;
using namespace std::chrono;
using namespace goat;
using namespace goat::gfx;

// [4][4][4][4][4][4][4][4]
// \-------/\-------/\----/
//  pos[12]  rgb[12]  tex[8]
//
const vector<float> vertices{
    // positions          // colors           // texture coords
    0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,  // top right
    0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom left
    -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
};
const vector<unsigned int> indices{0, 1, 3, 1, 2, 3};

inline void run_game() {
    glfwSetErrorCallback([](int error, const char *description) {
        LOG(ERROR) << "Fatal Error: " << description << "(Code " << error << ")";
    });

    unique_ptr<GameWindow> window = make_unique<GameWindow>("Hello, World!");

    // ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui_ImplGlfw_InitForOpenGL(window->get_window(), true);
    ImGui_ImplOpenGL3_Init();

    // Load GLAD
    if (gladLoadGL() == 0)
        throw std::runtime_error("Failed to load OpenGL functions via GLAD");

    ShaderProgram shaderProg{};
    Shader vertexShader{"shaders/basic.vert", ShaderType::VERTEX};
    Shader fragmentShader{"shaders/basic.frag", ShaderType::FRAGMENT};
    shaderProg.attachShader(&vertexShader);
    shaderProg.attachShader(&fragmentShader);

    // Let our fancy code calculate the attribute pointer bounds, stride, and
    // offset magically!
    auto vbo = new VBO<float>(BufferType::ARRAY, DrawType::STATIC, DataType::FLOAT, indices);
    vbo->addAttributeBound(0, 3);  // XYZ
    vbo->addAttributeBound(1, 3);  // RGB
    vbo->addAttributeBound(2, 2);  // TEX
    vbo->applyAttributeBounds(vertices);

    RenderContext ctx{};
    ctx.add(vbo);
    ctx.add(&shaderProg);

    // Textures!
    // Texture tex{"textures/gaga.jpg"};
    Texture happy{"textures/happy.png"};
    // ctx.add(&tex);
    ctx.add(&happy);

    shaderProg.use();
    fragmentShader.setInt("texture1", 0);
    fragmentShader.setInt("texture2", 1);

    window->loop([&vbo, &shaderProg, &happy, &ctx]() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow();

        ctx.render();

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, happy.getID());

        // glActiveTexture(GL_TEXTURE1);
        // glBindTexture(GL_TEXTURE_2D, happy.getID());

        shaderProg.use();
        vbo->use();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glDrawArrays(GL_TRIANGLES, 0, 3);

        // glBindVertexArray(0);
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
