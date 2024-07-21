#pragma once
#include <GL/glcorearb.h>

namespace goat::gfx {
// goat::gfx

// Default screen dimensions
constexpr unsigned int DEFAULT_SCREEN_WIDTH = 1600U;
constexpr unsigned int DEFAULT_SCREEN_HEIGHT = 900U;

enum class ShaderType {
    VERTEX = GL_VERTEX_SHADER,
    FRAGMENT = GL_FRAGMENT_SHADER,
};

enum class BufferType {
    ARRAY = GL_ARRAY_BUFFER,
    ELEMENT = GL_ELEMENT_ARRAY_BUFFER,
};

enum class DrawType {
    STATIC = GL_STATIC_DRAW,
    DYNAMIC = GL_DYNAMIC_DRAW,
};

enum class DataType {
    FLOAT = GL_FLOAT,
    INT = GL_INT,
    UNSIGNED_INT = GL_UNSIGNED_INT,
};

enum class ObjectLifetime {
    STATIC,
    SCENE,
    OBJECT,
    FRAME,
};

namespace gl {
// goat::gfx::gl
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
}  // namespace gl

}  // namespace goat::gfx