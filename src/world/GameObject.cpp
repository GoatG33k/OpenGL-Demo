#include "GameObject.hpp"

namespace goat::world {

/** @brief Return the model matrix for the object taking its transformations into account */
glm::mat4 GameObject::getModelMatrix() const {
    assert(this->transform != nullptr);

    auto model = mat4(1.0f);
    auto transform = this->transform.get();
    model = glm::translate(model, transform->pos);
    model = glm::rotate(model, glm::radians(transform->rot.x), vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(transform->rot.y), vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(transform->rot.z), vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, transform->scale);
    return model;
}

}  // namespace goat::world