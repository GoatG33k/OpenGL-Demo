
namespace goat::gfx {

inline VBO::~VBO() {
    glDeleteVertexArrays(1, &this->vao);
    glDeleteBuffers(1, &this->vbo);
    if (this->ebo > 0)
        glDeleteBuffers(1, &this->ebo);
}

inline void VBO::use() {
    assert(this->bounds.size() > 0);
    glBindVertexArray(this->vao);
}

}  // namespace goat::gfx