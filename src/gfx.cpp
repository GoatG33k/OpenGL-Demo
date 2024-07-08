#include <fstream>
#include <assert.h>
#include <easylogging++.h>
#include <GLFW/glfw3.h>

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

    //
    // VBO
    //

    VBO::VBO(
        GLenum bufferType,
        const vector<float> &points,
        uint dims,
        GLenum drawType) : bufferType(bufferType), drawType(drawType)
    {
        assert(bufferType == GL_ARRAY_BUFFER || bufferType == GL_ELEMENT_ARRAY_BUFFER);
        assert(drawType == GL_STATIC_DRAW || drawType == GL_DYNAMIC_DRAW);
        assert(dims > 0 && dims <= 4);

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        glGenBuffers(1, &vbo);

        uint vertPoints = points.size();
        uint entries = (vertPoints / dims) + (vertPoints % dims != 0); // divide + round up
        LOG(DEBUG) << "# of points  = " << vertPoints;
        LOG(DEBUG) << "# of dims    = " << dims;
        LOG(DEBUG) << "# of entries = " << entries;

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertPoints, points.data(), drawType);

        // Set index 0
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, dims, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    VBO::~VBO()
    {
        // Nothing to do really, OpenGL will clean up vertex arrays and buffers
        // (I hope)
    }
}