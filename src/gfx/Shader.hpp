#pragma once
#include <GL/glcorearb.h>

#include <string>

#include "gfx/VBO.hpp"

namespace goat::gfx {

/** @brief Loads and compiles a shader from a given file path.  */
class Shader {
   private:
    // The OpenGL handle to the shader
    GLuint handle;

   public:
    // The file path the shader was loaded from
    std::string path;
    ShaderType type;

    Shader(std::string filePath, ShaderType shaderType);
    Shader(const Shader &) = delete;
    Shader(Shader &&);
    ~Shader();

    Shader &operator=(const Shader &) = delete;
    Shader &operator=(Shader &&);

    // Retrieve the OpenGL handle of the shader
    GLuint getHandle() const;
    // Return the shader try
    ShaderType getShaderType() const;
};

}  // namespace goat::gfx