#pragma once
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/quaternion_common.hpp>
#include <glm/vec3.hpp>
#include <memory>

namespace goat::camera {

constexpr static float DEFAULT_FOV = 75.0f;
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
    float fov;
    // Current camera view matrix
    glm::mat4 view;
    // Camera world position
    glm::vec3 pos;

    Camera(glm::vec3 pos, float fov = DEFAULT_FOV);
    ~Camera(){};

    inline void redraw() noexcept;
    inline void move(Direction direction, float deltaTime);
    inline glm::mat4 getProjectionMatrix() const;
};

}  // namespace goat::camera

#include "camera.inl"