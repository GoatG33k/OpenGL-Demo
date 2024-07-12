#pragma once
#include <opengl/gl.h>
#include <opengl/gl3.h>

namespace goat::gfx::gl {

enum class glAPI {
    OPENGL2_0,
    OPENGL3_0,
    OPENGL3_3,
    OPENGL4_0,
    OPENGL4_1,
    OPENGL4_2,
    OPENGL4_3,
    OPENGL4_4,
    OPENGL4_5,
};

enum class glFeature {
    DEPTH_TESTING = GL_DEPTH_TEST,
};

enum class glProfile { CORE, COMPAT };

}