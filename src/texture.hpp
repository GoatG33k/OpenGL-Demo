#pragma once

#include <easylogging++.h>
#include <glad/gl.h>

#include <gli/gli.hpp>
#include <string>

namespace goat::gfx {

class Texture {
   private:
    std::string path;
    GLuint handle;

   public:
    Texture(std::string _path);
    inline ~Texture() {
        if (this->handle > 0)
            glDeleteTextures(1, &this->handle);
    }
    inline GLuint getID() {
        return this->handle;
    }
};
}  // namespace goat::gfx