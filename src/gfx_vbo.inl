
namespace goat::gfx {

inline VBO::~VBO() {
    glDeleteVertexArrays(1, &this->vao);
    glDeleteBuffers(1, &this->vbo);
    if (this->ebo > 0)
        glDeleteBuffers(1, &this->ebo);
}

inline void VBO::use() const {
#ifdef __DEBUG__
    assert(this->bounds.size() > 0);
    LOG(DEBUG) << " glBindVertexArray(" << this->vao << ")";
#endif
    glBindVertexArray(this->vao);
}

inline void VBO::draw() const {
#ifdef __DEBUG__
    assert(this->bounds.size() > 0);
    assert(this->entry_count > 0);
#endif

    if (false && this->ebo > 0) {
        // TODO: GL_UNSIGNED_INT not always accurate
        glDrawElements(GL_TRIANGLES, this->entry_count, GL_UNSIGNED_INT, 0);
#ifdef __DEBUG__
        LOG(DEBUG) << " glDrawElements(GL_TRIANGLES, " << this->entry_count << ", GL_UNSIGNED_INT, 0)";
#endif
    } else {
        glDrawArrays(GL_TRIANGLES, 0, this->entry_count);
#ifdef __DEBUG__
        LOG(DEBUG) << " glDrawArrays(GL_TRIANGLES, 0, " << this->entry_count << ")";
#endif
    }
}

inline GLuint VBO::getVBO() const {
    return this->vbo;
}

inline GLuint VBO::getEBO() const {
    return this->ebo;
}

}  // namespace goat::gfx