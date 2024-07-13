#include "VBO.hpp"

#include <assert.h>
#include <easylogging++.h>
#include <glad/gl.h>

namespace goat::gfx {

VBO::VBO(BufferType bufferType, DrawType drawType, DataType dataType, const std::vector<uint> &indices)
    : ebo(0U), entry_count(0UL), drawType(drawType), dataType(dataType), bufferType(bufferType) {
    assert(bufferType == BufferType::ARRAY || bufferType == BufferType::ELEMENT);
    assert(dataType == DataType::FLOAT || dataType == DataType::INT || dataType == DataType::UNSIGNED_INT);
    assert(drawType == DrawType::STATIC || drawType == DrawType::DYNAMIC);

    glGenVertexArrays(1, &this->vao);
    glGenBuffers(1, &this->vbo);

    if (indices.size() > 0) {
        LOG(DEBUG) << "Creating element buffer for VBO " << &this->vbo;
        glGenBuffers(1, &this->ebo);
        glBindVertexArray(this->vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint), &indices[0], GL_STATIC_DRAW);
    }
}

VBO::~VBO() {
    glDeleteVertexArrays(1, &this->vao);
    glDeleteBuffers(1, &this->vbo);
    if (this->ebo > 0)
        glDeleteBuffers(1, &this->ebo);
}

VBO::VBO(VBO &&other)
    : vao(other.vao),
      vbo(other.vbo),
      ebo(other.ebo),
      entry_count(other.entry_count),
      drawType(other.drawType),
      dataType(other.dataType),
      bufferType(other.bufferType),
      bounds(other.bounds) {
    other.vao = 0U;
    other.vbo = 0U;
    other.ebo = 0U;
    other.entry_count = 0UL;
}

VBO &VBO::operator=(VBO &&other) {
    if (this == &other)
        return *this;

    vao = other.vao;
    vbo = other.vbo;
    ebo = other.ebo;
    entry_count = other.entry_count;
    drawType = other.drawType;
    dataType = other.dataType;
    bufferType = other.bufferType;
    bounds = std::move(other.bounds);

    other.vao = 0;
    other.vbo = 0;
    other.ebo = 0;
    other.entry_count = 0;
    return *this;
};

void VBO::use() const {
#ifdef __DEBUG__
    assert(this->bounds.size() > 0);
    LOG(DEBUG) << " glBindVertexArray(" << this->vao << ")";
#endif
    glBindVertexArray(this->vao);
}

void VBO::draw() const {
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

GLuint VBO::getVBO() const {
    return this->vbo;
}

GLuint VBO::getEBO() const {
    return this->ebo;
}

}  // namespace goat::gfx