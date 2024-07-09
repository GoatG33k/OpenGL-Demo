#pragma once

#include <string>
#include <vector>
#include <assert.h>

#include <easylogging++.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <any>

namespace goat::gfx
{
    // Constants
    static const int DEFAULT_SCREEN_WIDTH = 1600;
    static const int DEFAULT_SCREEN_HEIGHT = 900;

    //
    // Shader
    //
    class Shader
    {
        friend class ShaderProgram;

    private:
        GLchar *shaderSource;
        GLenum type;
        GLuint shader;
        GLuint program;

    public:
        std::string filePath;

        Shader(const std::string filePath, GLenum shaderType);
        ~Shader()
        {
            if (shader != 0)
                glDeleteShader(shader);
        }
        GLuint get_id() const { return this->shader; }
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
        template <typename T>
        void setVector(const std::string &name, std::vector<T> value) const;
    };

    //
    // ShaderProgram
    //
    class ShaderProgram
    {
    private:
        bool linked = false;
        GLuint program;
        std::vector<Shader *> bound;

    public:
        ShaderProgram()
        {
            this->program = glCreateProgram();
        }
        inline ~ShaderProgram()
        {
            for (auto shader : this->bound)
                delete shader;

            if (this->program != 0)
                glDeleteProgram(this->program);
        }
        inline void use() { glUseProgram(this->program); }
        inline int getUniform(char *name) { return glGetUniformLocation(this->program, name); }

        void attachShader(Shader *shader);
        bool link();
    };

    //
    // VBO
    //
    template <typename T>
    inline void vbo_buffer_data(GLuint vao, GLuint vbo,
                                size_t entry_size,
                                const std::vector<T> &points,
                                GLenum bufferType,
                                GLenum drawType)
    {
        assert(bufferType == GL_ARRAY_BUFFER || bufferType == GL_ELEMENT_ARRAY_BUFFER);
        assert(drawType == GL_STATIC_DRAW || drawType == GL_DYNAMIC_DRAW);

        glBindVertexArray(vao);
        glBindBuffer(bufferType, vbo);
        glBufferData(bufferType, points.size() * entry_size, &points[0], drawType);
    }

    inline void vbo_set_attr_pointer(size_t dataSize, GLenum dataType,
                                     unsigned int dimensions, unsigned int index,
                                     size_t stride, size_t offset = 0)
    {
        assert(dataSize > 0);
        assert(index >= 0 && index <= 15); // technically incorrect
        assert(offset < stride);

        glVertexAttribPointer(index, dimensions, dataType, GL_FALSE, stride, (void *)offset);
        glEnableVertexAttribArray(index);
    }

    struct VAOBound
    {
        GLuint index;
        size_t data_size;
        unsigned int entries;
    };

    template <typename T, GLenum V = GL_FLOAT>
    class VBO
    {
    private:
        std::vector<VAOBound> bounds = {};
        GLenum drawType;
        GLenum bufferType;
        GLuint vao;
        GLuint vbo;

    public:
        ~VBO();
        VBO<>(GLenum bufferType, GLenum drawType);
        inline void use() { glBindVertexArray(this->vao); }
        inline void addAttributeBound(unsigned int index, size_t data_size, unsigned int entries)
        {
            for (auto bound : this->bounds)
                if (bound.index == index)
                    throw std::runtime_error("Attribute index already bound");
            this->bounds.push_back({index, data_size, entries});
        }
        inline void applyAttributeBounds()
        {

            size_t stride = accumulate(
                this->bounds.begin(), this->bounds.end(), 0,
                [](size_t acc, VAOBound bound)
                { return acc + bound.data_size * bound.entries; });

            size_t offset = 0;
            for (auto bound : this->bounds)
            {
                LOG(INFO) << "Applying attribute bound (i=" << bound.index
                          << ") (stride=" << (bound.data_size * bound.entries)
                          << ") (offset=" << offset << ")";
                vbo_set_attr_pointer(bound.data_size, V, bound.entries, bound.index, stride, offset);
                offset += bound.entries * bound.data_size;
            }
        }

        void setAttributePointer(unsigned int index, unsigned int dimensions, size_t stride, size_t offset = 0);
        void bufferData(const std::vector<T> &points);
    };

    // EBO
    class EBO
    {
    private:
        GLuint ebo;

    public:
        ~EBO();
        EBO(const std::vector<unsigned int> &indices, GLenum drawType);
    };
}