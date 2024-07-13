#pragma once
#include <glm/ext/matrix_transform.hpp>

#include "constants.hpp"
#include "gfx/constants.hpp"
#include "world/Transform.hpp"

namespace goat::world {

/**
 * @brief The `GameObject` struct binds all of the information necessary
 *        to render an object to the screen. This includes the VAO, VBO, EBO,
 *        drawing details, and transformation information.
 */
struct GameObject {
    bool active = true;
    vec3 world_pos = vec3(0.0f, 0.0f, 0.0f);
    const gfx::ObjectLifetime lifetime = gfx::ObjectLifetime::SCENE;
    const std::shared_ptr<Transform> transform{};

    static std::shared_ptr<GameObject> create(
        vec3 world_pos = vec3(0.0f, 0.0f, 0.0f), gfx::ObjectLifetime lifetime = gfx::ObjectLifetime::SCENE,
        std::shared_ptr<Transform> transform = std::shared_ptr<Transform>(new Transform()), bool active = true) {
        return std::make_shared<GameObject>(GameObject{
            .active = active,
            .world_pos = world_pos,
            .lifetime = lifetime,
            .transform = transform,
        });
    }
    // Return if the object is rendered using EBO/indices instead of VBO/vertices
    bool hasEBO() const;
    // Return the model matrix for the object taking its transformations into account
    glm::mat4 getModelMatrix() const;
    // Apply texture details to related shader uniforms
    void applyUniformData() const;
};

}  // namespace goat::world