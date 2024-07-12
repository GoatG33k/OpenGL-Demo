#pragma once

#include <assert.h>
#include <easylogging++.h>

#include <any>
#include <numeric>
#include <string>
#include <type_traits>
#include <vector>

// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on
#include "texture.hpp"

namespace goat::gfx {

// Enums
enum class ShaderType {
    VERTEX = GL_VERTEX_SHADER,
    FRAGMENT = GL_FRAGMENT_SHADER,
};

enum class BufferType {
    ARRAY = GL_ARRAY_BUFFER,
    ELEMENT = GL_ELEMENT_ARRAY_BUFFER,
};
enum class DrawType {
    STATIC = GL_STATIC_DRAW,
    DYNAMIC = GL_DYNAMIC_DRAW,
};

enum class DataType {
    FLOAT = GL_FLOAT,
    INT = GL_INT,
    UNSIGNED_INT = GL_UNSIGNED_INT,
};

enum class glTarget {
    OPENGL2_0,
    OPENGL3_0,
    OPENGL3_3,
    OPENGL4_0,
    OPENGL4_1,
    OPENGL4_2,
    OPENGL4_3,
    OPENGL4_4,
    OPENGL4_5,
};

enum class glProfile { CORE, COMPAT };

struct EngineConfig {
    glTarget gl_target = glTarget::OPENGL3_3;
    bool compat = false;
    std::vector<std::string> feat_requested;
};

/** @brief Loads and compiles a shader from a given file path.  */
class Shader {
    friend class ShaderProgram;

   private:
    // The file path the shader was loaded from
    std::string path;
    // The OpenGL handle to the shader
    GLuint handle;
    // The `ShaderProgram` that this shader is attached to (can be null)
    GLuint program = 0U;

   public:
    explicit Shader(std::string filePath, ShaderType shaderType);
    inline ~Shader();

    // Retrieve the OpenGL handle of the shader
    inline GLuint getHandle() const;
    // Set a boolean value to a shader uniform (really an int)
    inline void setBool(const std::string &name, bool value) const;
    // Set an integer to a shader uniform
    inline void setInt(const std::string &name, int value) const;
    // Set an unsigned integer to a shader uniform
    inline void setInt(const std::string &name, unsigned int value) const;
    // Set a float to a shader uniform
    inline void setFloat(const std::string &name, float value) const;
    // Set a multi-dimensional array (matrix) to a shader uniform
    template <typename T>
    inline void setMatrix(const std::string &name, T *value, size_t count) const;
    // Set a vector to a shader uniform
    template <typename T>
    inline void setVector(const std::string &name, T *value, size_t count) const;
};

/**
 * @brief A `ShaderProgram` is attached to one or more shaders and used
 *        to apply them in the render loop
 */
class ShaderProgram {
   private:
    // Whether the shader program has been linked to OpenGL
    bool linked;
    // The OpenGL handle to the shader program
    GLuint program;
    // The shaders that are attached to this program
    std::vector<Shader *> bound;

   public:
    ShaderProgram();
    ~ShaderProgram();
    // Use the shader program in a render loop
    inline void use() const;
    // Retrieve the location of a uniform in the shader program
    inline int getUniformLocation(char *name) const;
    // Check if the shader program has been linked
    constexpr inline bool isLinked();
    // Attach a shader to the shader program
    void attachShader(Shader *shader);
    // Link the shader program to OpenGL
    bool link();
};

// A small struct for storing attribute bounds for VBOs
struct VAOBound {
    GLuint index;
    size_t data_size;
    unsigned int entries;
};

/**
 * @brief A Vertex Buffer Object (VBO) is a buffer that contains vertex data that is
 *        used to render individual points into shapes.
 *
 * @note Providing the `&indices` parameter will create an Element Buffer Object (EBO) automatically,
 *       that can be used for rendering indexed vertices.
 */
class VBO {
   private:
    // Registered array sizing data for automatically configuring the VBO and attribute pointers
    std::vector<VAOBound> bounds = {};
    // The type of draw to use
    DrawType drawType;
    // The type of data to store
    DataType dataType;
    // The type of buffer to create
    BufferType bufferType;
    // Internal OpenGL handles for the VAO, VBO, and EBO (optional)
    GLuint vao;
    GLuint vbo;
    GLuint ebo;

   public:
    inline ~VBO();
    explicit VBO(BufferType bufferType, DrawType drawType, DataType dataType,
                 const std::vector<unsigned int> &indices = std::vector<unsigned int>{})
        : drawType(drawType), dataType(dataType), bufferType(bufferType), ebo(0U) {
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
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
        }
    }

    // Apply the vertex buffer in the current frame being rendered
    inline void use();

    /**
     * @brief Configure attribute bounds for passing attributes to shaders from streamed vector data.
     *
     * @param index The index of the attribute in the shader program
     * @param entries The number of entries in the attribute (e.g. 3 for a vec3)
     * @param item_size The size of the item in the array (default is sizeof(T))
     */
    template <typename T = float>
    inline void addAttributeBound(unsigned int index, unsigned int entries, size_t item_size = sizeof(T)) {
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
    inline void applyAttributeBounds(const std::vector<T> &points) {
        if (this->bounds.size() == 0)
            throw std::runtime_error("No attribute bounds set");

        size_t stride = std::accumulate(this->bounds.begin(), this->bounds.end(), 0UL, [](size_t acc, VAOBound bound) {
            return acc + bound.data_size * bound.entries;
        });

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
            offset += bound.entries * bound.data_size;
        }
    }
};

/**
 * @brief A RenderContext contains a collection of VBOs, shader programs, and textures that are used to render a scene.
 */
class RenderContext {
   private:
    std::vector<VBO *> vbos;
    std::vector<ShaderProgram *> shaders;
    std::vector<Texture *> textures;

   public:
    RenderContext() {
    }
    inline ~RenderContext() {
        for (auto vbo : this->vbos) {
            delete vbo;
        }
    }
    // Apply a VBO to the render context
    inline void add(VBO *vbo) {
        this->vbos.push_back(vbo);
    }
    // Apply a shader program to the render context
    inline void add(ShaderProgram *shader) {
        if (!shader->isLinked())
            shader->link();
        this->shaders.push_back(shader);
    }
    // Apply a texture to the render context
    inline void add(Texture *texture) {
        this->textures.push_back(texture);
    }
    // Render the scene from the game loop
    inline void render() {
    }
};
}  // namespace goat::gfx

// Implementations
#include "gfx_shader.inl"
#include "gfx_shaderprogram.inl"
#include "gfx_vbo.inl"