#pragma once

#include <GL/glcorearb.h>
#include <GL/glext.h>
#include <easylogging++.h>

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
    ~Texture();

    uint getHandle() const;
    inline std::string getPath() const { return this->path; }
};

}  // namespace goat::gfx
