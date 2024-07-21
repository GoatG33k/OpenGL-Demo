#pragma once
#include <cglm/struct.h>

#include "../constants.hpp"

namespace goat::world {

constexpr static float DEFAULT_FOV = 75.0f;
constexpr static float BASE_SPEED = 2.5f;

constexpr static vec3s getCameraDefaultPos() { return {{0.0f, 0.0f, 3.0f}}; }
constexpr static vec3s getCameraFrontVec() { return {{0.0f, 0.0f, -1.0f}}; }
constexpr static vec3s getCameraUpVec() { return {{0.0, 1.0f, 0.0f}}; }

}  // namespace goat::world