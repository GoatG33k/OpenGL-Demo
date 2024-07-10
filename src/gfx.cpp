#include <fstream>
#include <chrono>
#include <assert.h>
#include <easylogging++.h>

#include "gfx.hpp"

using namespace std;
using namespace std::chrono;

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
            stringstream err;
            err << "Failed to link shader program: " << infoLog;
            LOG(ERROR) << err.str();
            throw runtime_error(err.str());
        }

        linked = true;
        LOG(INFO) << "Linked ShaderProgram: " << &program;
        return !!success;
    }

    //
    // Shader
    //
    Shader::Shader(const string filePath, ShaderType shaderType) : filePath(filePath), type(shaderType)
    {

        ifstream ifs(filePath);
        string _shaderSource((istreambuf_iterator<char>(ifs)),
                             (istreambuf_iterator<char>()));

        auto startTime = high_resolution_clock::now();
        shader = glCreateShader((GLenum)shaderType);
        shaderSource = (GLchar *)_shaderSource.c_str();
        glShaderSource(shader, 1, &shaderSource, NULL);
        glCompileShader(shader);

        int success;
        GLchar infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            stringstream err;
            err << "[shader] [" << filePath << "] failed to compile: " << infoLog;

            LOG(ERROR) << err.str();
            throw runtime_error(err.str());
        }

        auto endTime = high_resolution_clock::now();
        LOG(INFO) << "[shader] [" << filePath << "] compiled " << strlen(shaderSource)
                  << " bytes in " << duration_cast<milliseconds>(endTime - startTime).count() << "ms";
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
        BufferType bufferType,
        DrawType drawType,
        DataType dataType) : bufferType(bufferType), drawType(drawType), dataType(dataType)
    {
        glGenVertexArrays(1, &this->vao);
        glGenBuffers(1, &this->vbo);
    }

    template <>
    VBO<float>::~VBO()
    {
        glDeleteVertexArrays(1, &this->vao);
        glDeleteBuffers(1, &this->vbo);
    }

    //
    // EBO
    //
    EBO::EBO(const vector<unsigned int> &indices, DrawType drawType)
    {
        glGenBuffers(1, &this->ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], (GLenum)drawType);
    }

    EBO::~EBO()
    {
        glDeleteBuffers(1, &this->ebo);
    }
}