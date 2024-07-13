#pragma once

#include <chrono>
#include <string>
#include <vector>

#include "constants.hpp"
#include "gfx/Shader.hpp"
#include "gfx/VBO.hpp"
#include "world/Camera.hpp"

namespace goat::gfx {

/**
 * @brief A RenderContext contains a collection of VBOs, shader programs, and textures that are used to render a scene.
 *        Each object added to the context is visible and can/will be associated with any other objects
 */
class RenderContext {
   private:
    bool compiled = false;
    uint uv_count = 0U;
    GLuint program = 0U;
    std::vector<std::shared_ptr<VBO>> vbos;
    std::vector<std::shared_ptr<Shader>> shaders;
    std::vector<std::shared_ptr<BoundTexture>> textures;

    // Apply a VBO to the render context
    void add(const std::shared_ptr<VBO> &vbo);
    // Apply a texture to the render context
    void add(const std::shared_ptr<Texture> &texture, const std::string uniform_name);
    // Apply a shader program to the render context
    void add(const std::shared_ptr<Shader> &shader);
    // Swap the active shader program to this one if it is not already active

   public:
    RenderContext();
    ~RenderContext();

    void compile();

    // Load a texture from a file path and attach it to the render context
    void loadTexture(std::string path, std::string uniform_target);

    // Load a shader from a file path and attach it to the render context
    void loadShader(std::string path, const ShaderType type);

    void useVBO(std::shared_ptr<VBO> &vbo) {
        this->add(vbo);
    }

    // Return the location of a uniform in the shader program
    int getUniform(const std::string &name) const;

    // Render the scene from the game loop
    void render(world::Camera *camera) {
#ifdef __DEBUG__
        auto startTime = std::chrono::high_resolution_clock::now();
#endif

        // Draw polygons!
        for (const auto &vbo : this->vbos) {
            vbo->use();
            vbo->draw();
            // glBindVertexArray(0);
        }

#ifdef __DEBUG__
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(endTime - startTime);
        LOG(DEBUG) << "RenderContext::render() took " << duration.count() << " μs (" << this->vbos.size() << " VBOs)";
#endif
    }

    // Use the shader program for this frame
    void use() const {
#ifdef __DEBUG__
        LOG(DEBUG) << "RenderContext<" << this << ">::use()";
#endif
        glUseProgram(this->program);

        // Apply texture indices
        for (const auto &bound_texture : this->textures) {
            assert(bound_texture->index <= 31);
            auto texture = bound_texture->texture.get();
            glActiveTexture(static_cast<GLenum>(GL_TEXTURE0 + bound_texture->index));
            glBindTexture(GL_TEXTURE_2D, texture->getHandle());
#ifdef __DEBUG__
            LOG(DEBUG) << " glActiveTexture(GL_TEXTURE" << bound_texture->index << ") path=" << texture->getPath();
            LOG(DEBUG) << " glBindTexture(GL_TEXTURE_2D, " << texture->getHandle() << ")";
#endif
        }
#ifdef __DEBUG__
        LOG(DEBUG) << " glUseProgram(" << this->program << ")";
#endif
    }

    // Set a boolean value to a shader uniform (really an int)
    void setBool(const std::string &name, bool value) const;
    // Set an integer to a shader uniform
    void setInt(const std::string &name, int value) const;
    // Set an unsigned integer to a shader uniform
    void setUInt(const std::string &name, uint value) const;
    // Set a float to a shader uniform
    void setFloat(const std::string &name, float value) const;
    // Set a multi-dimensional array (matrix) to a shader uniform

    template <typename T = const float>
    void setMatrix(const std::string &name, T *value, size_t count) {
        assert(this->program > 0);
        assert(count > 0 && count <= 4);

        GLint uniformAddr = static_cast<GLint>(this->getUniform(name));
        const T *data = &value[0];
        if (std::is_floating_point<T>::value) {
#ifdef __DEBUG__
            LOG(DEBUG) << " glUniformMatrix" << count << "fv(" << uniformAddr << ", 1, GL_FALSE, " << data << ")";
#endif

            if (count == 2)
                glUniformMatrix2fv(uniformAddr, 1, GL_FALSE, data);
            else if (count == 3)
                glUniformMatrix3fv(uniformAddr, 1, GL_FALSE, data);
            else if (count == 4)
                glUniformMatrix4fv(uniformAddr, 1, GL_FALSE, data);
        } else {
            std::stringstream err;
            err << "Unsupported data type: " << typeid(T).name();
            throw std::runtime_error(err.str());
        }
    }
    // Set a vector to a shader uniform
    template <typename T = const float>
    void setVector(const std::string &name, T *value, size_t count);
};

}  // namespace goat::gfx