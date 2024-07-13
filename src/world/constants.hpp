#pragma once
#include "../constants.hpp"

namespace goat::world {

constexpr static float DEFAULT_FOV = 75.0f;
constexpr static float BASE_SPEED = 2.5f;

constexpr static vec3 CAMERA_DEFAULT_POS = vec3(0.0f, 0.0f, 3.0f);
constexpr static vec3 CAMERA_FRONT_VEC = vec3(0.0f, 0.0f, -1.0f);
constexpr static vec3 CAMERA_UP_VEC = vec3(0.0, 1.0f, 0.0f);

}