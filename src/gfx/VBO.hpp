#pragma once

#include <glad/gl.h>

#include <numeric>

#include "constants.hpp"
#include "gfx/structs.hpp"

namespace goat::gfx {

/**
 * @brief A Vertex Buffer Object (VBO) is a buffer that contains vertex data that is
 *        used to render individual points into shapes.
 *
 * @note Providing the `&indices` parameter will create an Element Buffer Object (EBO) automatically,
 *       that can be used for rendering indexed vertices.
 */
class VBO {
   private:
    // Internal OpenGL handles for the VAO, VBO, and EBO (optional)
    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    // The total number of entries
    size_t entry_count;
    // The type of draw to use
    DrawType drawType;
    // The type of data to store
    DataType dataType;
    // The type of buffer to create
    BufferType bufferType;
    // Registered array sizing data for automatically configuring the VBO and attribute pointers
    std::vector<VAOBound> bounds = {};

    // Calculate the total size of the array buffer
    size_t stride() const {
        return std::accumulate(this->bounds.begin(), this->bounds.end(), static_cast<size_t>(0UL),
                               [](size_t acc, VAOBound bound) { return acc + bound.data_size * bound.entries; });
    }

   public:
    VBO(BufferType bufferType, DrawType drawType, DataType dataType,
        const std::vector<uint> &indices = std::vector<uint>{});
    VBO(const VBO &) = delete;
    VBO(VBO &&);
    ~VBO();

    VBO &operator=(const VBO &) = delete;
    VBO &operator=(VBO &&);

    GLuint getVBO() const;
    GLuint getEBO() const;

    // Apply the vertex buffer in the current frame being rendered
    void use() const;

    // Draw the vertex buffer in the current frame being rendered
    void draw() const;

    // Returns the number of elements to render for this VBO
    size_t size() const {
        return this->entry_count;
    }

    /**
     * @brief Configure attribute bounds for passing attributes to shaders from streamed vector data.
     *
     * @param index The index of the attribute in the shader program
     * @param entries The number of entries in the attribute (e.g. 3 for a vec3)
     * @param item_size The size of the item in the array (default is sizeof(T))
     */
    template <typename T = float>
    void addAttributeBound(uint index, uint entries, size_t item_size = sizeof(T)) {
        for (auto bound : this->bounds)
            if (bound.index == index)
                throw std::runtime_error("Attribute index already bound");
        this->bounds.push_back({index, item_size, entries});
    }

    /**
     * @brief Apply the registered attribute bounds to OpenGL by automatically calculating the total stride
     *        of each entry, the offset of each attribute index, and then streaming the vector data to the VBO.
     */
    template <typename T = float>
    void applyAttributeBounds(const std::vector<T> &points) {
        if (this->bounds.size() == 0)
            throw std::runtime_error("No attribute bounds set");

        this->use();
        uint elements_per_entry = 0U;
        for (auto bound : this->bounds)
            elements_per_entry += bound.entries;

        assert(this->bounds.size() > 0 && elements_per_entry > 0);
        this->entry_count = points.size() / elements_per_entry;
        size_t stride = this->stride();

        glBindVertexArray(this->vao);
        glBindBuffer(static_cast<GLenum>(this->bufferType), this->vbo);
        glBufferData(static_cast<GLenum>(this->bufferType), points.size() * sizeof(T), &points[0],
                     static_cast<GLenum>(drawType));

        size_t offset{};
        for (auto bound : this->bounds) {
            LOG(INFO) << "Applying attribute bound (i=" << bound.index
                      << ") (stride=" << (bound.data_size * bound.entries) << ") (offset=" << offset << ")";
            // vbo_set_attr_pointer(this->dataType, bound.entries, bound.index, stride, offset);
            glVertexAttribPointer(bound.index, bound.entries, (GLenum)this->dataType, GL_FALSE, stride, (void *)offset);
            glEnableVertexAttribArray(bound.index);
#ifdef __DEBUG__
            LOG(DEBUG) << "glVertexAttribPointer(" << bound.index << ", " << bound.entries << ", "
                       << (GLenum)this->dataType << ", GL_FALSE, " << stride << ", (void *)" << offset << ")";
            LOG(DEBUG) << "glEnableVertexAttribArray(" << bound.index << ")";
#endif
            offset += bound.entries * bound.data_size;
        }
    }
};

}  // namespace goat::gfx