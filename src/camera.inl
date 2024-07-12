#include <glm/ext/matrix_transform.hpp>

#include "camera.hpp"

namespace goat::camera {

Camera::Camera(glm::vec3 _pos) : pos(std::move(_pos)) {
    this->redraw();
}

inline void Camera::redraw() {
    this->view = glm::lookAt(this->pos, this->pos + CAMERA_FRONT_VEC, CAMERA_UP_VEC);
}

inline void Camera::move(Direction direction, float deltaTime) {
    float speed = BASE_SPEED * deltaTime;
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

}  // namespace goat::camera