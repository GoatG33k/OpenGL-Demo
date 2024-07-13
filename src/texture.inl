#include <GLFW/glfw3.h>

#include <string>

#include "texture.hpp"

namespace goat::gfx {

Texture::Texture(std::string path) : path(path), handle(0U) {
    gli::texture texture = gli::load(path);
    assert(!texture.empty());

    gli::gl GL(gli::gl::PROFILE_GL33);
    gli::gl::format const format = GL.translate(texture.format(), texture.swizzles());
    GLenum target = GL.translate(texture.target());

    glGenTextures(1, &this->handle);
    glBindTexture(target, this->handle);

    glTexParameteri(target, GL_TEXTURE_BASE_LEVEL, 0);
    glTexParameteri(target, GL_TEXTURE_MAX_LEVEL, static_cast<GLint>(texture.levels() - 1));

    gli::tvec3<GLsizei> const extent(texture.extent());
    auto levels = static_cast<GLint>(texture.levels());
    switch (texture.target()) {
        case gli::TARGET_2D:
        case gli::TARGET_CUBE:
            glTexStorage2D(target, levels, format.Internal, extent.x, extent.y);
            break;
        case gli::TARGET_3D:
        case gli::TARGET_CUBE_ARRAY:
            glTexStorage3D(target, levels, format.Internal, extent.x, extent.y, extent.z);
            break;
        default:
            assert(0);
            break;
    }

    for (std::size_t Layer = 0; Layer < texture.layers(); ++Layer)
        for (std::size_t Face = 0; Face < texture.faces(); ++Face)
            for (std::size_t Level = 0; Level < texture.levels(); ++Level) {
                GLsizei const LayerGL = static_cast<GLsizei>(Layer);
                glm::tvec3<GLsizei> Extent(texture.extent(Level));
                target = gli::is_target_cube(texture.target())
                             ? static_cast<GLenum>(GL_TEXTURE_CUBE_MAP_POSITIVE_X + Face)
                             : target;

                switch (texture.target()) {
                    case gli::TARGET_2D:
                    case gli::TARGET_CUBE:
                        if (gli::is_compressed(texture.format()))
                            glCompressedTexSubImage2D(target, static_cast<GLint>(Level), 0, 0, Extent.x, Extent.y,
                                                      format.Internal, static_cast<GLsizei>(texture.size(Level)),
                                                      texture.data(Layer, Face, Level));
                        else
                            glTexSubImage2D(target, static_cast<GLint>(Level), 0, 0, Extent.x, Extent.y,
                                            format.External, format.Type, texture.data(Layer, Face, Level));
                        break;
                    case gli::TARGET_3D:
                    case gli::TARGET_CUBE_ARRAY:
                        if (gli::is_compressed(texture.format()))
                            glCompressedTexSubImage3D(target, static_cast<GLint>(Level), 0, 0, 0, Extent.x, Extent.y,
                                                      Extent.z, format.Internal,
                                                      static_cast<GLsizei>(texture.size(Level)),
                                                      texture.data(Layer, Face, Level));
                        else
                            glTexSubImage3D(target, static_cast<GLint>(Level), 0, 0, 0, Extent.x, Extent.y,
                                            texture.target() == gli::TARGET_3D ? Extent.z : LayerGL, format.External,
                                            format.Type, texture.data(Layer, Face, Level));
                        break;
                    default:
                        assert(0);
                        break;
                }
            }
}

inline Texture::~Texture() {
    if (this->handle != 0)
        glDeleteTextures(1, &this->handle);
}

inline GLuint Texture::getHandle() {
    return this->handle;
}

}  // namespace goat::gfx