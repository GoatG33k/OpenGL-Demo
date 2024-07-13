#include "Transform.hpp"

namespace goat::world {

constexpr vec3 Transform::forward() const {
    return vec3(0.0f, 0.0f, -1.0f);
}

constexpr vec3 Transform::right() const {
    return vec3(1.0f, 0.0f, 0.0f);
}

constexpr vec3 Transform::up() const {
    return vec3(0.0f, 1.0f, 0.0f);
}

}