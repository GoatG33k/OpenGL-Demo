#include "GameObject.hpp"

#include <assert.h>
#include <cglm/affine.h>

namespace goat::world {

/** @brief Return the model matrix for the object taking its transformations into account */
mat4s& GameObject::getModelMatrix() const {
    assert(this->transform != nullptr);

    mat4s model = mat4s{
      {{1.0f, 1.0f, 1.0f, 1.0f},
       {1.0f, 1.0f, 1.0f, 1.0f},
       {1.0f, 1.0f, 1.0f, 1.0f},
       {1.0f, 1.0f, 1.0f, 1.0f}},
    };
    model = glms_translate(model, this->transform->pos);
    glms_rotate(model, glm_rad(this->transform->rot.x), vec3s{{1.0f, 0.0f, 0.0f}});
    glms_rotate(model, glm_rad(this->transform->rot.y), vec3s{{0.0f, 1.0f, 0.0f}});
    glms_rotate(model, glm_rad(this->transform->rot.z), vec3s{{0.0f, 0.0f, 1.0f}});
    glms_scale(model, this->transform->scale);
    return model;
}

}  // namespace goat::world