#pragma once

#include "constants.hpp"

namespace goat::world {

enum Direction {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
};

class Camera {
   public:
    float fov;
    // Current camera view matrix
    mat4 view;
    // Camera world position
    vec3 pos;

    Camera(vec3 pos, float fov = DEFAULT_FOV);
    ~Camera(){};

    void redraw();
    void move(Direction direction, float deltaTime);
    mat4 getProjectionMatrix() const;
};

}  // namespace goat::world