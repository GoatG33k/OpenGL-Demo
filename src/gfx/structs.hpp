#pragma once
#include "Texture.hpp"
#include "gfx/constants.hpp"

namespace goat::gfx {

struct EngineConfig {
    gl::glAPI gl_target = gl::glAPI::OPENGL3_3;
    bool compat = false;
    std::vector<std::string> feat_requested;
};

struct BoundTexture {
    uint index;
    const std::shared_ptr<Texture> texture;
    const std::string uniform_name;
};

// A small struct for storing attribute bounds for VBOs
struct VAOBound {
    GLuint index;
    size_t data_size;
    uint entries;
};

}  // namespace goat::gfx