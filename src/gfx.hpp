#pragma once

#include <string>
#include <GLFW/glfw3.h>

#ifdef MACOS
#include <OpenGL/gl3.h>
#endif // MACOS

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
        ~ShaderProgram()
        {
            if (program != 0)
                glDeleteProgram(program);
        }

        constexpr GLuint get_id() { return program; }
        constexpr void use() { glUseProgram(program); }
        void attachShader(Shader *shader);
        bool link();
    };

    // VBO
    class VBO
    {
    private:
        GLenum bufferType;
        GLenum drawType;

    public:
        GLuint vao;
        GLuint vbo;

        ~VBO();
        VBO(
            GLenum bufferType,
            const std::vector<float> &points,
            uint dims = 3,
            GLenum drawType = GL_STATIC_DRAW);
        constexpr void use() { glBindVertexArray(vao); }
    };
}