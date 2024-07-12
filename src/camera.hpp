#pragma once
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/quaternion_common.hpp>
#include <glm/vec3.hpp>
#include <memory>

namespace goat::camera {

constexpr static float BASE_SPEED = 2.5f;
constexpr static glm::vec3 CAMERA_DEFAULT_POS = glm::vec3(0.0f, 0.0f, 3.0f);
constexpr static glm::vec3 CAMERA_FRONT_VEC = glm::vec3(0.0f, 0.0f, -1.0f);
constexpr static glm::vec3 CAMERA_UP_VEC = glm::vec3(0.0, 1.0f, 0.0f);

enum Direction {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
};

class Camera {
   public:
    glm::mat4 view;
    glm::vec3 pos;

    Camera(glm::vec3 _pos);
    ~Camera(){};

    inline void redraw();
    inline void move(Direction direction, float deltaTime);
};

}  // namespace goat::camera

#include "camera.inl"