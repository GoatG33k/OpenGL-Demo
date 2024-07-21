#pragma once

#include "constants.hpp"
#include "world/Transform.hpp"

namespace goat::world {

enum class Direction {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
};

class Camera {
   public:
    float fov;
    Transform transform;
    mat4s view;
    vec3s pos;

    Camera(float fov);
    Camera();
    ~Camera(){};

    void redraw();
    void turn(const Direction direction, float deltaTime);
    void walk(const Direction direction, float deltaTime);
    mat4s getProjectionMatrix() const;
};

}  // namespace goat::world