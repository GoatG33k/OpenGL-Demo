#pragma once

#include <assert.h>
#include <easylogging++.h>

#include <any>
#include <numeric>
#include <string>
#include <type_traits>
#include <vector>

// clang-format off
#include <glad/glad.h>
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

//
// Shader
//
class Shader {
    friend class ShaderProgram;

   private:
    ShaderType type;
    GLuint handle;
    GLuint program;
    std::string path;

   public:
    Shader(std::string filePath, ShaderType shaderType);
    ~Shader() {
        if (this->handle != 0)
            glDeleteShader(handle);
    }
    GLuint getID() const {
        return this->handle;
    }
    void setBool(const std::string name, bool value) const;
    void setInt(const std::string name, int value) const;
    void setInt(const std::string, unsigned int value) const;
    void setFloat(const std::string name, float value) const;

    template <typename T>
    inline void setVector(const std::string &name, const std::vector<T> value) const {
        assert(this->program > 0);
        size_t count = value.size();
        assert(count > 0 && count <= 4);

        auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
        const T *data = &value[0];
        if constexpr (std::is_floating_point<T>::value) {
            if (count == 1)
                glUniform1fv(uniformAddr, count, data);
            else if (count == 2)
                glUniform2fv(uniformAddr, count, data);
            else if (count == 3)
                glUniform3fv(uniformAddr, count, data);
            else if (count == 4)
                glUniform4fv(uniformAddr, count, data);
        } else if (std::is_unsigned<T>::value && std::is_integral<T>::value) {
            if (count == 1)
                glUniform1uiv(uniformAddr, count, data);
            else if (count == 2)
                glUniform2uiv(uniformAddr, count, data);
            else if (count == 3)
                glUniform3uiv(uniformAddr, count, data);
            else if (count == 4)
                glUniform4uiv(uniformAddr, count, data);
        } else if (std::is_integral<T>::value) {
            if (count == 1)
                glUniform1iv(uniformAddr, count, data);
            else if (count == 2)
                glUniform2iv(uniformAddr, count, data);
            else if (count == 3)
                glUniform3iv(uniformAddr, count, data);
            else if (count == 4)
                glUniform4iv(uniformAddr, count, data);
        } else {
            std::stringstream err;
            err << "Unsupported data type: " << typeid(T).name();
            throw std::runtime_error(err.str());
        }
    }
};

//
// ShaderProgram
//
class ShaderProgram {
   private:
    bool linked;
    GLuint program;
    std::vector<Shader *> bound;

   public:
    ShaderProgram() : linked(false), program(glCreateProgram()) {
    }
    inline ~ShaderProgram() {
        for (auto shader : this->bound)
            delete shader;

        if (this->program != 0)
            glDeleteProgram(this->program);
    }
    inline void use() {
        glUseProgram(this->program);
    }
    inline int getUniform(char *name) {
        return glGetUniformLocation(this->program, name);
    }

    constexpr bool isLinked() {
        return this->linked;
    }
    void attachShader(Shader *shader);
    bool link();
};

//
// VBO
//
template <typename T>
inline void vbo_buffer_data(GLuint vao, GLuint vbo, size_t entry_size, const std::vector<T> &points,
                            BufferType bufferType, DrawType drawType) {
    glBindVertexArray(vao);
    glBindBuffer((GLenum)bufferType, vbo);
    glBufferData((GLenum)bufferType, points.size() * entry_size, &points[0], (GLenum)drawType);
}

struct VAOBound {
    GLuint index;
    size_t data_size;
    unsigned int entries;
};

template <typename T = float>
class VBO {
   private:
    std::vector<VAOBound> bounds = {};
    DataType dataType;
    DrawType drawType;
    BufferType bufferType;
    GLuint vao;
    GLuint vbo;
    GLuint ebo;

   public:
    VBO<>(BufferType bufferType, DrawType drawType, DataType dataType,
          const std::vector<unsigned int> &indices = std::vector<unsigned int>{})
        : dataType(dataType), drawType(drawType), bufferType(bufferType), ebo(0U) {
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
    ~VBO() {
        glDeleteVertexArrays(1, &this->vao);
        glDeleteBuffers(1, &this->vbo);
        if (this->ebo > 0)
            glDeleteBuffers(1, &this->ebo);
    }

    inline void use() {
        if (this->bounds.size() == 0)
            throw std::runtime_error("No attribute bounds set");

        glBindVertexArray(this->vao);
    }

    inline void addAttributeBound(unsigned int index, unsigned int entries, size_t item_size = sizeof(T)) {
        for (auto bound : this->bounds)
            if (bound.index == index)
                throw std::runtime_error("Attribute index already bound");
        this->bounds.push_back({index, item_size, entries});
    }

    inline void applyAttributeBounds(const std::vector<T> &points) {
        if (this->bounds.size() == 0)
            throw std::runtime_error("No attribute bounds set");

        size_t stride = std::accumulate(this->bounds.begin(), this->bounds.end(), 0UL, [](size_t acc, VAOBound bound) {
            return acc + bound.data_size * bound.entries;
        });

        vbo_buffer_data(this->vao, this->vbo, sizeof(T), points, this->bufferType, this->drawType);

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

// EBO
class EBO {
   private:
    GLuint ebo;

   public:
    ~EBO();
    EBO(const std::vector<unsigned int> &indices, DrawType drawType);
};

//
// RenderContext
//

/** @brief A RenderContext is a collection of VBOs and Shaders that are used to
 * render a scene.  */
template <typename T = float>
class RenderContext {
   private:
    unsigned int texture_index = 0;
    std::vector<VBO<T> *> vbos;
    std::vector<ShaderProgram *> shaders;
    std::vector<Texture *> textures;

   public:
    RenderContext(){};
    ~RenderContext() {
        for (auto vbo : this->vbos) {
            delete vbo;
        }
    }

    inline void add(VBO<T> *vbo) {
        this->vbos.push_back(vbo);
    }

    inline void add(ShaderProgram *shader) {
        if (!shader->isLinked())
            shader->link();
        this->shaders.push_back(shader);
    }

    inline void add(Texture *texture) {
        this->textures.push_back(texture);
    }

    inline void render() {
        // TODO: figure out how to draw random functions quickly
    }
};
}  // namespace goat::gfx