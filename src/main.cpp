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

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
// clang-format on

// #include <gli/gli.hpp>

#include "Window.hpp"
#include "constants.hpp"
#include "world/GameObject.hpp"
#include "world/Scene.hpp"

using namespace std::chrono;
using namespace goat;
using namespace goat::gfx;

// [4][4][4][4][4]
// \-------/\----/
//  pos[12]  tex[8]
//
const std::vector<float> vertices{
  -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.5f,  -0.5f, -0.5f, 1.0f,  0.0f,  0.5f,  0.5f,  -0.5f, 1.0f,
  1.0f,  0.5f,  0.5f,  -0.5f, 1.0f,  1.0f,  -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  -0.5f, -0.5f, -0.5f,
  0.0f,  0.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.5f,  -0.5f, 0.5f,  1.0f,  0.0f,  0.5f,  0.5f,
  0.5f,  1.0f,  1.0f,  0.5f,  0.5f,  0.5f,  1.0f,  1.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  1.0f,  -0.5f,
  -0.5f, 0.5f,  0.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  1.0f,  0.0f,  -0.5f, 0.5f,  -0.5f, 1.0f,  1.0f,
  -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  -0.5f, -0.5f, 0.5f,  0.0f,
  0.0f,  -0.5f, 0.5f,  0.5f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.5f,  0.5f,  -0.5f,
  1.0f,  1.0f,  0.5f,  -0.5f, -0.5f, 0.0f,  1.0f,  0.5f,  -0.5f, -0.5f, 0.0f,  1.0f,  0.5f,  -0.5f,
  0.5f,  0.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  0.5f,
  -0.5f, -0.5f, 1.0f,  1.0f,  0.5f,  -0.5f, 0.5f,  1.0f,  0.0f,  0.5f,  -0.5f, 0.5f,  1.0f,  0.0f,
  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  -0.5f, 0.5f,  -0.5f, 0.0f,
  1.0f,  0.5f,  0.5f,  -0.5f, 1.0f,  1.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,
  1.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f

};

const std::vector<unsigned int> indices{0, 1, 3, 1, 2, 3};
const vec3s cubePositions[] = {
  {{0.0f, 0.0f, 0.0f}},   {{2.0f, 5.0f, -15.0f}}, {{-1.5f, -2.2f, -2.5f}}, {{-3.8f, -2.0f, -12.3f}},
  {{2.4f, -0.4f, -3.5f}}, {{-1.7f, 3.0f, -7.5f}}, {{1.3f, -2.0f, -2.5f}},  {{1.5f, 2.0f, -2.5f}},
  {{1.5f, 0.2f, -1.5f}},  {{-1.3f, 1.0f, -1.5f}}};

void run_game() {
    glfwSetErrorCallback([](int error, const char *description) {
        LOG(ERROR) << "Fatal Error: " << description << "(Code " << error << ")";
    });

    std::unique_ptr<GameWindow> window = std::make_unique<GameWindow>(
        "Hello, World!", EngineConfig{.gl_target = gl::glAPI::OPENGL3_3});

    // Load GLAD
    if (!gladLoadGL(glfwGetProcAddress))
        throw std::runtime_error("Failed to load OpenGL functions via GLAD");

    window->createCamera(std::move(world::getCameraDefaultPos()));
    window->setFeature(gl::glFeature::DEPTH_TESTING);

    // Create our 3D scene and add our cube vertices
    world::Scene *scene =
        world::Scene::create("Main Scene", std::shared_ptr<world::Camera>(window->getCamera()));

    // Create the VBO buffer for our cube
    auto vbo = std::make_unique<VBO>(BufferType::ARRAY, DrawType::STATIC, DataType::FLOAT, indices);
    vbo->addAttributeBound(0, 3);  // XYZ
    vbo->addAttributeBound(1, 2);  // UV
    vbo->applyAttributeBounds(vertices);

    // Create cube objects
    for (int i = 0; i < 10; i++) {
        auto cube_obj = world::GameObject::create(cubePositions[i], ObjectLifetime::SCENE);
        scene->objects.push_back(cube_obj);
    }

    scene->render_context->useVBO(std::move(vbo));
    scene->render_context->loadShader("shaders/basic.vert", ShaderType::VERTEX);
    scene->render_context->loadShader("shaders/basic.frag", ShaderType::FRAGMENT);
    scene->render_context->loadTexture("textures/gaga.dds", "texture1");

    scene->use();

    window->loop([scene = std::move(scene)]() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow();

        scene->render();

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
