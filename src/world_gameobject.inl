#include <glm/ext/matrix_transform.hpp>

namespace goat::world {

/** @brief Return the model matrix for the object taking its transformations into account */
constexpr inline glm::mat4 GameObject::getModelMatrix() const {
    assert(this->transform != nullptr);

    glm::mat4 model = glm::mat4(1.0f);
    auto transform = this->transform.get();
    model = glm::translate(model, transform->pos);
    model = glm::rotate(model, glm::radians(transform->rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(transform->rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(transform->rot.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, transform->scale);
    return model;
}

}  // namespace goat::world