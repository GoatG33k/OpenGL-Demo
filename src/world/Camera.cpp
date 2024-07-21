#include "Camera.hpp"

#include <cglm/cam.h>
#include <easylogging++.h>

#include "constants.hpp"

namespace goat::world {

Camera::Camera() : Camera(DEFAULT_FOV) {}
Camera::Camera(float fov) {
    this->pos = getCameraDefaultPos();
    this->redraw();
}

void Camera::redraw() {
    this->view =
        glms_lookat(this->pos, glms_vec3_add(this->pos, getCameraFrontVec()), getCameraUpVec());
    LOG(DEBUG) << "Camera::redraw(fov=" << this->fov << ")";
}

/** Rotate the camera */
void Camera::turn(Direction direction, float deltaTime) {
    // this->front
}

/** Walk the camera's position */
void Camera::walk(Direction direction, float deltaTime) {
    float speed = BASE_SPEED * deltaTime;
    auto CAMERA_FRONT_VEC = getCameraFrontVec();
    auto CAMERA_UP_VEC = getCameraUpVec();

    if (direction == Direction::FORWARD) {
        vec3s adjust = glms_vec3_mul(CAMERA_FRONT_VEC, vec3s{.x = speed, .y = speed, .z = speed});
        this->pos = glms_vec3_add(this->pos, adjust);
    } else if (direction == Direction::BACKWARD) {
        vec3s adjust = glms_vec3_mul(CAMERA_FRONT_VEC, vec3s{.x = speed, .y = speed, .z = speed});
        this->pos = glms_vec3_sub(this->pos, adjust);
    } else if (direction == Direction::LEFT) {
        vec3s adjust = glms_vec3_cross(CAMERA_FRONT_VEC, CAMERA_UP_VEC);
        adjust = glms_vec3_normalize(adjust);
        adjust = glms_vec3_mul(adjust, vec3s{.x = speed, .y = speed, .z = speed});
        this->pos = glms_vec3_sub(this->pos, adjust);
    } else if (direction == Direction::RIGHT) {
        vec3s adjust = glms_vec3_cross(CAMERA_FRONT_VEC, CAMERA_UP_VEC);
        adjust = glms_vec3_normalize(adjust);
        adjust = glms_vec3_mul(adjust, vec3s{.x = speed, .y = speed, .z = speed});
        this->pos = glms_vec3_add(this->pos, adjust);
    }
    this->redraw();
}

mat4s Camera::getProjectionMatrix() const {
    return glms_perspective(glm_rad(this->fov), 800.f / 600.f, 0.1f, 100.0f);
}

}  // namespace goat::world