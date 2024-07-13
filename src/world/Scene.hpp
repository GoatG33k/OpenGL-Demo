#pragma once
#include <string>
#include <vector>

#include "gfx/RenderContext.hpp"
#include "world/Camera.hpp"
#include "world/GameObject.hpp"

namespace goat::world {

/**
 * @brief A scene contains a collection of objects that are rendered to the screen
 *        using a given camera and render context.
 */
struct Scene {
    const std::shared_ptr<gfx::RenderContext> render_context;
    const std::shared_ptr<world::Camera> camera;
    std::vector<std::shared_ptr<GameObject>> objects{};
    std::string name = "Scene";

    static Scene *create(
        const std::string &name, std::shared_ptr<world::Camera> camera,
        std::shared_ptr<gfx::RenderContext> context = std::shared_ptr<gfx::RenderContext>(new gfx::RenderContext()),
        std::vector<std::shared_ptr<GameObject>> objects = std::vector<std::shared_ptr<GameObject>>());

    void use() const;
    void render() const;
};

}  // namespace goat::world