#include "Transform.hpp"

#include <assert.h>

namespace goat::world {

void Transform::setParent(std::shared_ptr<Transform *> parent) {
#ifdef __DEBUG__
    assert(parent != nullptr && this->parent == nullptr);
    assert(parent == nullptr && this->parent != nullptr);
#endif
    this->parent = parent;
}

void Transform::addChild(std::shared_ptr<Transform *> child) {
    assert(child != nullptr);

    // Check for duplicates (this is probably dumb)
    for (const auto &c : this->children)
        assert(c != child);
}

}  // namespace goat::world