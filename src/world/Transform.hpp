#pragma once
#include <memory>
#include <vector>

#include "constants.hpp"

namespace goat::world {

/**
 * @brief Contains position, rotation, and scaling information for an object
 */
struct Transform {
    vec3 pos = vec3(0.0f, 0.0f, 0.0f);
    vec3 rot = vec3(0.0f, 0.0f, 0.0f);
    vec3 scale = vec3(1.0f, 1.0f, 1.0f);
    std::shared_ptr<Transform *> parent = nullptr;
    std::vector<std::shared_ptr<Transform *>> children{};

    // Return the x vector relative to the object
    constexpr vec3 right() const;
    // Return the y vector relative to the object
    constexpr vec3 forward() const;
    // Return the z vector relative to the object
    constexpr vec3 up() const;
};

}  // namespace goat::world