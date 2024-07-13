
#include "gfx.hpp"

namespace goat::gfx {

RenderContext::RenderContext() : uv_count(0U), program(glCreateProgram()), vbos({}), shaders({}), textures({}){};

inline RenderContext::~RenderContext() {
    if (this->program) {
        glDeleteProgram(this->program);
    }
}

/** A RenderContext cannot be modified after it has been "compiled" */
inline void RenderContext::compile() {
    assert(!this->compiled);
    assert(this->vbos.size() > 0);
    assert(this->shaders.size() > 0);

#ifdef __DEBUG__
    LOG(DEBUG) << "RenderContext<" << this << ">::compile() START";
#endif

    // Shrink our memory consumption
    this->vbos.shrink_to_fit();
    this->shaders.shrink_to_fit();
    this->textures.shrink_to_fit();

    for (std::shared_ptr<Shader> shader : this->shaders) {
        glAttachShader(this->program, shader->getHandle());
#ifdef __DEBUG__
        LOG(DEBUG) << " glAttachShader(" << this->program << ", " << shader->getHandle() << ")";
#endif
    }

    int success{};
    char infoLog[512]{};
#ifdef __DEBUG__
    LOG(DEBUG) << " glLinkProgram(" << this->program << ")";
#endif
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
    for (auto texture : this->textures) {
        auto uniform_name = texture->uniform_name;
#ifdef __DEBUG__
        LOG(DEBUG) << "Setting uniform " << texture->uniform_name << " to texture #" << texture->index;
#endif
        this->setInt(texture->uniform_name, texture->index);
    }

    // TODO: I'm sure this will cause problems later
    for (auto shader : this->shaders) {
#ifdef __DEBUG__
        LOG(DEBUG) << " glDeleteShader(" << shader->getHandle() << ")";
#endif
        glDeleteShader(shader->getHandle());
    }

#ifdef __DEBUG__
    LOG(DEBUG) << "RenderContext<" << this << ">::compile() END";
#endif
    this->compiled = true;
}

inline void RenderContext::add(std::shared_ptr<VBO> &vbo) {
    LOG(DEBUG) << "Added VBO " << vbo << " to RenderContext " << this;
    this->vbos.push_back(vbo);
}

inline void RenderContext::add(std::shared_ptr<Shader> &shader) {
    auto pathName = shader->path;
    for (std::shared_ptr<Shader> shader : this->shaders) {
        if (shader->path == pathName)
            throw std::runtime_error("Shader already attached to RenderContext");
    }
    this->shaders.push_back(shader);
}

/**
 * @brief (Internally) register a texture with the render context, and increment the internal UV index
 * @param texture: The texture to bind to this render context
 * @param uniform_name: The name of the texture uniform in the shader program
 */
inline void RenderContext::add(std::shared_ptr<Texture> &texture, std::string uniform_name) {
    auto index = this->uv_count;
    ++this->uv_count;

    for (auto uv : this->textures) {
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
inline void RenderContext::loadTexture(std::string path, std::string uniform_name) {
    auto texture = std::make_shared<Texture>(path);
    this->add(texture, uniform_name);
}

/**
 * @brief Load a shader from a file path and attach it to the render context
 * @param path The path to the shader file
 * @param type The type of shader to load (vertex or fragment)
 */
inline void RenderContext::loadShader(std::string path, const ShaderType type) {
    auto shader = std::make_shared<Shader>(Shader{path, type});
    this->add(shader);
}

/**
 * @brief Return the address for a uniform property
 */
inline GLint RenderContext::getUniform(const std::string &name) const {
    GLint idx = static_cast<GLint>(glGetUniformLocation(this->program, name.c_str()));
#ifdef __DEBUG__
    if (idx <= -1)
        throw std::runtime_error("Uniform of name '" + name + "' was not found");

    LOG(DEBUG) << " glGetUniformLocation(" << this->program << ", \"" << name << "\") resolved to " << idx;
#endif
    return idx;
}

inline void RenderContext::setBool(const std::string &name, bool value) const {
    assert(this->program > 0);
    GLint uniformAddr = static_cast<GLint>(this->getUniform(name));
#ifdef __DEBUG__
    LOG(DEBUG) << " glUniform1i(" << uniformAddr << ", " << value << ") uniform=" << name;
#endif
    glUniform1i(uniformAddr, value);
}

inline void RenderContext::setInt(const std::string &name, int value) const {
    assert(this->program > 0);
    GLint uniformAddr = static_cast<GLint>(this->getUniform(name));
#ifdef __DEBUG__
    LOG(DEBUG) << " glUniform1i(" << uniformAddr << ", " << value << ") uniform=" << name;
#endif
    glUniform1i(uniformAddr, value);
}

inline void RenderContext::setUInt(const std::string &name, uint value) const {
    assert(this->program > 0);
    GLint uniformAddr = static_cast<GLint>(this->getUniform(name));
#ifdef __DEBUG__
    LOG(DEBUG) << " glUniform1ui(" << uniformAddr << ", " << value << ") uniform=" << name;
#endif
    glUniform1ui(uniformAddr, value);
}

inline void RenderContext::setFloat(const std::string &name, float value) const {
    assert(this->program > 0);
    GLint uniformAddr = static_cast<GLint>(this->getUniform(name));
#ifdef __DEBUG__
    LOG(DEBUG) << " glUniform1f(" << uniformAddr << ", " << value << ") uniform=" << name;
#endif
    glUniform1f(uniformAddr, value);
}

template <typename T>
inline void RenderContext::setMatrix(const std::string &name, T *value, size_t count) const {
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

template <typename T>
inline void RenderContext::setVector(const std::string &name, T *value, size_t count) const {
    assert(this->program > 0);
    assert(count > 0 && count <= 4);

    GLint uniformAddr = static_cast<GLint>(this->getUniform(name));
    const T *data = &value[0];
    if constexpr (std::is_floating_point<T>::value) {
#ifdef __DEBUG__
        LOG(DEBUG) << " glUniform" << count << "fv(" << uniformAddr << ", " << count << ", " << data << ")";
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
        LOG(DEBUG) << " glUniform" << count << "uiv(" << uniformAddr << ", " << count << ", " << data << ")";
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
        LOG(DEBUG) << " glUniform" << count << "iv(" << uniformAddr << ", " << count << ", " << data << ")";
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