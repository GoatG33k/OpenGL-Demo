#pragma once

#include <string>
#include <vector>
#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>

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
    private:
        GLchar *shaderSource;
        GLenum type;
        GLuint shader;

    public:
        std::string filePath;

        Shader(const std::string filePath, GLenum shaderType);
        ~Shader()
        {
            if (shader != 0)
                glDeleteShader(shader);
        }
        constexpr GLuint get_id() { return shader; }
    };

    //
    // ShaderProgram
    //
    class ShaderProgram
    {
    private:
        bool linked = false;
        GLuint program;

    public:
        ShaderProgram()
        {
            program = glCreateProgram();
        }
        inline ~ShaderProgram()
        {
            if (program != 0)
                glDeleteProgram(program);
        }

        constexpr GLuint get_id() { return this->program; }
        inline void use() { glUseProgram(this->program); }
        void attachShader(Shader *shader);
        bool link();
    };

    // VBO
    class VBO
    {
    private:
        GLenum bufferType;
        GLenum drawType;
        GLuint vao;
        GLuint vbo;

    public:
        ~VBO();
        VBO(
            GLenum bufferType,
            const std::vector<float> &points,
            GLenum drawType);
        constexpr GLuint get_vao() { return this->vao; }
        inline void use() { glBindVertexArray(this->vao); }
    };
}