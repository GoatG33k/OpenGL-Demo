#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "camera.hpp"

namespace goat::camera {

Camera::Camera(glm::vec3 _pos, float _fov) : pos(std::move(_pos)), fov(std::move(_fov)) {
    this->redraw();
}

inline void Camera::redraw() noexcept {
    this->view = glm::lookAt(this->pos, this->pos + CAMERA_FRONT_VEC, CAMERA_UP_VEC);
#if DEBUG
    LOG(DEBUG) << "Camera::redraw(fov=" << this->fov << ")";
#endif
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

inline glm::mat4 Camera::getProjectionMatrix() const {
    return glm::perspective(glm::radians(this->fov), 800.f / 600.f, 0.1f, 100.0f);
}

}  // namespace goat::camera