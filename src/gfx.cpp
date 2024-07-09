#include <fstream>
#include <assert.h>
#include <easylogging++.h>

#include "gfx.hpp"

using namespace std;

namespace goat::gfx
{
    //
    // ShaderProgram
    //
    void ShaderProgram::attachShader(Shader *shader)
    {
        GLuint shaderRef = shader->get_id();
        if (shaderRef == 0)
            throw runtime_error("Shader reference is NULL");

        LOG(DEBUG) << "Attaching shader " << shader->filePath << " to program " << program;
        shader->program = this->program;
        glAttachShader(program, shaderRef);
    }

    bool ShaderProgram::link()
    {
        if (linked)
        {
            LOG(WARNING) << "Attempted to link a ShaderProgram that is already linked: " << program;
            return true;
        }

        int success;
        char infoLog[512];

        glLinkProgram(program);
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(program, 512, NULL, infoLog);
            LOG(ERROR) << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                       << infoLog;
        }

        linked = true;
        LOG(INFO) << "Linked ShaderProgram: " << reinterpret_cast<void *>(program);
        return (bool)success;
    }

    //
    // Shader
    //
    Shader::Shader(const string filePath, GLenum shaderType) : filePath(filePath), type(shaderType)
    {
        if (shaderType != GL_VERTEX_SHADER && shaderType != GL_FRAGMENT_SHADER)
            throw runtime_error("Invalid shader type specified. Must be either GL_VERTEX_SHADER or GL_FRAGMENT_SHADER.");

        shader = glCreateShader(shaderType);

        LOG(INFO) << " [shader] [" << filePath << "] created #" << shader;
        ifstream ifs(filePath);
        string _shaderSource((istreambuf_iterator<char>(ifs)),
                             (istreambuf_iterator<char>()));

        shaderSource = (GLchar *)_shaderSource.c_str();
        LOG(DEBUG) << "[shader] [" << filePath << "] size is " << strlen(shaderSource) << " bytes";

        glShaderSource(shader, 1, &shaderSource, NULL);
        glCompileShader(shader);

        int success;
        GLchar infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            LOG(ERROR) << "ERROR::SHADER::VERTEX::COMPILATION_FAILED - "
                       << infoLog;
            throw runtime_error("Failed to compile shader: " + filePath);
        }
        else
        {
            LOG(DEBUG) << "[shader] [" << filePath << "] compiled!";
        }
    }

    void Shader::setBool(const string &name, bool value) const
    {
        assert(this->program > 0);
        auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
        glUniform1i(uniformAddr, (int)value);
    }

    void Shader::setInt(const string &name, int value) const
    {
        assert(this->program > 0);
        auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
        glUniform1i(uniformAddr, value);
    }

    void Shader::setFloat(const string &name, float value) const
    {
        assert(this->program > 0);
        auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
        glUniform1f(uniformAddr, value);
    }

    template <typename T>
    void Shader::setVector(const string &name, vector<T> value) const
    {
        assert(this->program > 0);
        auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
        size_t count = value.size();
        const T *data = &value[0];

        assert(count > 0 && count <= 4);
        if (count == 1)
            glUniform1fv(uniformAddr, count, data);
        else if (count == 2)
            glUniform2fv(uniformAddr, count, data);
        else if (count == 3)
            glUniform3fv(uniformAddr, count, data);
        else if (count == 4)
            glUniform4fv(uniformAddr, count, data);
    }

    //
    // VBO
    //
    template <>
    VBO<float>::VBO(
        GLenum bufferType,
        GLenum drawType) : bufferType(bufferType), drawType(drawType)
    {
        assert(bufferType == GL_ARRAY_BUFFER || bufferType == GL_ELEMENT_ARRAY_BUFFER);
        assert(drawType == GL_STATIC_DRAW || drawType == GL_DYNAMIC_DRAW);
        glGenVertexArrays(1, &this->vao);
        glGenBuffers(1, &this->vbo);
    }

    template <>
    VBO<float>::~VBO()
    {
        glDeleteVertexArrays(1, &this->vao);
        glDeleteBuffers(1, &this->vbo);
    }

    template <>
    void VBO<float>::bufferData(const vector<float> &points)
    {
        vbo_buffer_data(this->vao, this->vbo, sizeof(float), points, this->bufferType, this->drawType);
    }

    template <>
    void VBO<int, GL_INT>::bufferData(const vector<int> &points)
    {
        vbo_buffer_data(this->vao, this->vbo, sizeof(int), points, this->bufferType, this->drawType);
    }

    template <>
    void VBO<float>::setAttributePointer(unsigned int index,
                                         unsigned int dimensions,
                                         size_t stride, size_t offset)
    {
        assert(4 <= dimensions >= 0);
        assert(stride > 0 && offset >= 0);
        assert(offset < stride);
        vbo_set_attr_pointer(sizeof(float), GL_FLOAT, dimensions, index, stride, offset);
    }

    template <>
    void VBO<int, GL_INT>::setAttributePointer(unsigned int index, unsigned int dimensions,
                                               size_t stride, size_t offset)
    {
        assert(4 <= dimensions >= 0);
        assert(stride > 0 && offset >= 0);
        assert(offset < stride);
        vbo_set_attr_pointer(sizeof(int), GL_INT, dimensions, index, stride, offset);
    }

    //
    // EBO
    //
    EBO::EBO(const vector<unsigned int> &indices, GLenum drawType)
    {
        glGenBuffers(1, &this->ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], drawType);
    }

    EBO::~EBO()
    {
        glDeleteBuffers(1, &this->ebo);
    }
}