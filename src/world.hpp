#pragma once
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "window.hpp"

namespace goat {

namespace world {

class World {};

}  // namespace world

namespace camera {
constexpr static float CAMERA_SPEED = 2.5f;
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

    Camera(glm::vec3 _pos) : pos(std::move(_pos)) {
        this->redraw();
    }
    ~Camera() {
    }

    inline void redraw() {
        this->view = glm::lookAt(this->pos, this->pos + CAMERA_FRONT_VEC, CAMERA_UP_VEC);
    }

    inline void move(Direction direction, float deltaTime) {
        float speed = CAMERA_SPEED * deltaTime;
        if (direction == Direction::FORWARD) {
            this->pos += speed * CAMERA_FRONT_VEC;
        } else if (direction == Direction::BACKWARD) {
            this->pos -= speed * CAMERA_FRONT_VEC;
        } else if (direction == Direction::LEFT) {
            this->pos -= glm::normalize(glm::cross(CAMERA_FRONT_VEC, CAMERA_UP_VEC)) * speed;
        } else if (direction == Direction::RIGHT) {
            this->pos += glm::normalize(glm::cross(CAMERA_FRONT_VEC, CAMERA_UP_VEC)) * speed;
        }
        this->redraw();
    }
};

}  // namespace camera

}  // namespace goat