#include "texture.hpp"

#include <string>

namespace goat::gfx {
Texture::Texture(std::string _path) : path(std::move(_path)) {
    stbi_set_flip_vertically_on_load(true);

    int width, height, channels;
    unsigned char* imageData = stbi_load(path.c_str(), &width, &height, &channels, 0);

    if (imageData) {
        glGenTextures(1, &this->handle);
        glBindTexture(GL_TEXTURE_2D, this->handle);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTexParameteri(GL_ALPHA, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_ALPHA, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        GLenum format;
        if (channels == 1)
            format = GL_RED;
        else if (channels == 3)
            format = GL_RGB;
        else if (channels == 4)
            format = GL_RGBA;
        else
            throw std::runtime_error("Unsupported number of channels in texture");

        LOG(INFO) << "[texture] [" << path << "] read (" << width << "x" << height << "x" << channels << ")";
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        LOG(ERROR) << "Failed to read texture: " << path;
    }

    stbi_image_free(imageData);
}
}  // namespace goat::gfx