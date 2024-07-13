#include "Camera.hpp"

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "constants.hpp"
#include "easylogging++.h"

namespace goat::world {

Camera::Camera(glm::vec3 pos, float fov) : fov(fov), pos(pos) {
    this->redraw();
}

void Camera::redraw() {
    this->view = glm::lookAt(this->pos, this->pos + CAMERA_FRONT_VEC, CAMERA_UP_VEC);
#ifdef __DEBUG__
    LOG(DEBUG) << "Camera::redraw(fov=" << this->fov << ")";
#endif
}

void Camera::move(Direction direction, float deltaTime) {
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

glm::mat4 Camera::getProjectionMatrix() const {
    return glm::perspective(glm::radians(this->fov), 800.f / 600.f, 0.1f, 100.0f);
}

}  // namespace goat::world