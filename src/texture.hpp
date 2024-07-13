#pragma once

#include <easylogging++.h>
#include <glad/gl.h>

#include <gli/gli.hpp>
#include <string>

namespace goat::gfx {

/** @brief Handles reading and loading texture (DDS) files into memory/OpenGL */
class Texture {
   private:
    // The file path the texture was loaded from
    std::string path;
    // The OpenGL handle to the texture
    GLuint handle;

   public:
    Texture(std::string _path);
    inline ~Texture();
    inline GLuint getHandle();
    inline std::string getPath() const {
        return this->path;
    }
};

}  // namespace goat::gfx

#include "texture.inl"