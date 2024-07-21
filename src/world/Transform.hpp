#pragma once
#include <memory>
#include <vector>

#include "constants.hpp"

namespace goat::world {

/**
 * @brief Contains position, rotation, and scaling information for an object
 */
struct Transform {
    vec3s pos;
    vec3s rot;
    vec3s scale;
    std::shared_ptr<Transform *> parent = nullptr;
    std::vector<std::shared_ptr<Transform *>> children;

    constexpr static vec3s forward{{0.0f, 0.0f, -1.0f}};
    constexpr static vec3s right{{1.0f, 0.0f, 0.0f}};
    constexpr static vec3s up{{0.0f, 1.0f, 0.0f}};

    void setParent(std::shared_ptr<Transform *> parent);
    void addChild(std::shared_ptr<Transform *> child);

    static std::shared_ptr<Transform> create(
        vec3s pos = vec3s{0.0f, 0.0f, 0.0f},
        vec3s rot = vec3s{0.0f, 0.0f, 0.0f},
        vec3s scale = vec3s{1.0f, 1.0f, 1.0f},
        std::shared_ptr<Transform *> parent = nullptr,
        std::vector<std::shared_ptr<Transform *>> children = {}) {
        return std::make_shared<Transform>(Transform{
          .pos = std::move(pos),
          .rot = std::move(rot),
          .scale = std::move(scale),
          .parent = parent,
          .children = std::move(children),
        });
    }
};

}  // namespace goat::world