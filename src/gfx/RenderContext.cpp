#include "RenderContext.hpp"

namespace goat::gfx {

RenderContext::RenderContext() : uv_count(0U) {
    this->program = glCreateProgram();
    this->vbos = std::vector<std::unique_ptr<VBO>>();
    this->shaders = std::vector<std::shared_ptr<Shader>>();
    this->textures = std::vector<std::shared_ptr<BoundTexture>>();
}

RenderContext::~RenderContext() {
    LOG(DEBUG) << "free(RenderContext<" << this << ">)";
    if (this->program) {
        glDeleteProgram(this->program);
    }
}

/// Pack the vectors in memory. A RenderContext should not be modified after it has been "compiled"
void RenderContext::compile() {
    assert(!this->compiled);
    assert(this->vbos.size() > 0);
    assert(this->shaders.size() > 0);
    LOG(DEBUG) << "RenderContext<" << this << ">::compile() START";

    // Shrink our memory consumption
    this->vbos.shrink_to_fit();
    this->shaders.shrink_to_fit();
    this->textures.shrink_to_fit();

    for (const auto &shader : this->shaders) {
        glAttachShader(this->program, shader->getHandle());
        LOG(DEBUG) << " glAttachShader(" << this->program << ", " << shader->getHandle() << ")";
    }

    int success{};
    char infoLog[512]{};
    LOG(DEBUG) << " glLinkProgram(" << this->program << ")";
    glLinkProgram(this->program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::stringstream err;
        err << "Failed to link shader program: " << infoLog;
        LOG(ERROR) << err.str();
        throw std::runtime_error(err.str());
    }

    // (Re-)assign uniforms to textures
    for (const auto &texture : this->textures) {
        auto uniform_name = texture->uniform_name;
        LOG(DEBUG) << "Setting uniform " << texture->uniform_name << " to texture #"
                   << texture->index;
        this->setInt(texture->uniform_name, texture->index);
    }

    // TODO: I'm sure this will cause problems later
    for (const auto &shader : this->shaders) {
        LOG(DEBUG) << " glDeleteShader(" << shader->getHandle() << ")";
        glDeleteShader(shader->getHandle());
    }

    LOG(DEBUG) << "RenderContext<" << this << ">::compile() END";
    this->compiled = true;
}

/**
 * @brief Move a VBO into this render context
 * @private
 */
void RenderContext::add(std::unique_ptr<VBO> &&vbo) {
    LOG(DEBUG) << "Added VBO " << vbo << " to RenderContext " << this;
    this->vbos.push_back(std::move(vbo));
}

void RenderContext::add(const std::shared_ptr<Shader> &&shader) {
    auto pathName = shader->path;
    for (const auto &shader : this->shaders) {
        if (shader->path == pathName)
            throw std::runtime_error("Shader already attached to RenderContext");
    }
    this->shaders.push_back(std::move(shader));
}

/**
 * @brief (Internally) register a texture with the render context, and increment the internal UV
 * index
 * @param texture: The texture to bind to this render context
 * @param uniform_name: The name of the texture uniform in the shader program
 */
void RenderContext::add(const std::shared_ptr<Texture> &&texture, std::string const &uniform_name) {
    auto index = this->uv_count;
    ++this->uv_count;

    for (const auto &uv : this->textures) {
        if (uv->index == index) {
            std::stringstream err;
            err << "Texture already bound to index " << index;
            throw std::runtime_error(err.str());
        }

        if (uv->uniform_name == uniform_name) {
            std::stringstream err;
            err << "Texture already bound to uniform name '" << uniform_name << "'";
            throw std::runtime_error(err.str());
        }
    }

    // Add the texture to the list of known textures
    auto uv = BoundTexture{.index = index, .texture = texture, .uniform_name = uniform_name};
    this->textures.push_back(std::make_shared<BoundTexture>(uv));
}

/**
 * @brief Load a texture from a file path and attach it to the render context.
 *        Additionally, attach it to the `uniform_target` for each available vertex shader
 * @param path The path to the texture file
 * @param uniform_name The name of the texture uniform in the shader program
 */
void RenderContext::loadTexture(std::string const &path, std::string const &uniform_name) {
    this->add(std::make_unique<Texture>(path), uniform_name);
}

/**
 * @brief Load a shader from a file path and attach it to the render context
 * @param path The path to the shader file
 * @param type The type of shader to load (vertex or fragment)
 */
void RenderContext::loadShader(std::string const &path, const ShaderType type) {
    this->add(std::make_shared<Shader>(Shader{path, type}));
}

/**
 * @brief Return the address for a uniform property
 */
GLint RenderContext::getUniform(const std::string &name) const {
    GLint idx = static_cast<GLint>(glGetUniformLocation(this->program, name.c_str()));
    if (idx <= -1) throw std::runtime_error("Uniform of name '" + name + "' was not found");
#ifdef __DEBUG__
    LOG(DEBUG) << " glGetUniformLocation(" << this->program << ", \"" << name << "\") resolved to "
               << idx;
#endif
    return idx;
}

void RenderContext::setBool(const std::string &name, bool value) const {
    assert(this->program > 0);
    GLint uniformAddr = static_cast<GLint>(this->getUniform(name));
#ifdef __DEBUG__
    LOG(DEBUG) << " glUniform1i(" << uniformAddr << ", " << value << ") uniform=" << name;
#endif
    glUniform1i(uniformAddr, value);
}

void RenderContext::setInt(const std::string &name, int value) const {
    assert(this->program > 0);
    GLint uniformAddr = static_cast<GLint>(this->getUniform(name));
#ifdef __DEBUG__
    LOG(DEBUG) << " glUniform1i(" << uniformAddr << ", " << value << ") uniform=" << name;
#endif
    glUniform1i(uniformAddr, value);
}

void RenderContext::setUInt(const std::string &name, uint value) const {
    assert(this->program > 0);
    GLint uniformAddr = static_cast<GLint>(this->getUniform(name));
#ifdef __DEBUG__
    LOG(DEBUG) << " glUniform1ui(" << uniformAddr << ", " << value << ") uniform=" << name;
#endif
    glUniform1ui(uniformAddr, value);
}

void RenderContext::setFloat(const std::string &name, float value) const {
    assert(this->program > 0);
    GLint uniformAddr = static_cast<GLint>(this->getUniform(name));
#ifdef __DEBUG__
    LOG(DEBUG) << " glUniform1f(" << uniformAddr << ", " << value << ") uniform=" << name;
#endif
    glUniform1f(uniformAddr, value);
}

template <typename T>
void RenderContext::setVector(const std::string &name, T *value, size_t count) {
    assert(this->program > 0);
    assert(count > 0 && count <= 4);

    GLint uniformAddr = static_cast<GLint>(this->getUniform(name));
    const T *data = &value[0];
    if constexpr (std::is_floating_point<T>::value) {
#ifdef __DEBUG__
        LOG(DEBUG) << " glUniform" << count << "fv(" << uniformAddr << ", " << count << ", " << data
                   << ")";
#endif
        if (count == 1)
            glUniform1fv(uniformAddr, count, data);
        else if (count == 2)
            glUniform2fv(uniformAddr, count, data);
        else if (count == 3)
            glUniform3fv(uniformAddr, count, data);
        else if (count == 4)
            glUniform4fv(uniformAddr, count, data);
    } else if (std::is_unsigned<T>::value && std::is_integral<T>::value) {
#ifdef __DEBUG__
        LOG(DEBUG) << " glUniform" << count << "uiv(" << uniformAddr << ", " << count << ", "
                   << data << ")";
#endif
        if (count == 1)
            glUniform1uiv(uniformAddr, count, data);
        else if (count == 2)
            glUniform2uiv(uniformAddr, count, data);
        else if (count == 3)
            glUniform3uiv(uniformAddr, count, data);
        else if (count == 4)
            glUniform4uiv(uniformAddr, count, data);
    } else if (std::is_integral<T>::value) {
#ifdef __DEBUG__
        LOG(DEBUG) << " glUniform" << count << "iv(" << uniformAddr << ", " << count << ", " << data
                   << ")";
#endif
        if (count == 1)
            glUniform1iv(uniformAddr, count, data);
        else if (count == 2)
            glUniform2iv(uniformAddr, count, data);
        else if (count == 3)
            glUniform3iv(uniformAddr, count, data);
        else if (count == 4)
            glUniform4iv(uniformAddr, count, data);
    } else {
        std::stringstream err;
        err << "Unsupported data type: " << typeid(T).name();
        throw std::runtime_error(err.str());
    }
}

}  // namespace goat::gfx