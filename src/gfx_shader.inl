#include <chrono>
#include <string>

#include "gfx.hpp"

using namespace std::chrono;

namespace goat::gfx {

Shader::Shader(const std::string filePath, ShaderType shaderType) : path(std::move(filePath)) {
    std::ifstream ifs(filePath);
    std::string _shaderSource((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    auto startTime = high_resolution_clock::now();
    this->handle = glCreateShader((GLenum)shaderType);

    auto shaderSource = reinterpret_cast<const GLchar *>(_shaderSource.c_str());
    glShaderSource(this->handle, 1, &shaderSource, nullptr);
    glCompileShader(this->handle);

    int success{};
    GLchar infoLog[512];
    glGetShaderiv(this->handle, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(this->handle, 512, nullptr, infoLog);
        std::stringstream err;
        err << "[shader] [" << filePath << "] failed to compile: " << infoLog;

        LOG(ERROR) << err.str();
        throw std::runtime_error(err.str());
    }

    auto endTime = high_resolution_clock::now();
    LOG(INFO) << "[shader] [" << filePath << "] compiled " << strlen(shaderSource) << " bytes in "
              << duration_cast<milliseconds>(endTime - startTime).count() << "ms";
}

inline Shader::~Shader() {
    if (this->handle != 0)
        glDeleteShader(handle);
}

inline GLuint Shader::getHandle() const {
    return this->handle;
}

inline void Shader::setBool(const std::string &name, bool value) const {
    assert(this->program > 0);
    auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
    glUniform1i(uniformAddr, value);
}

inline void Shader::setInt(const std::string &name, int value) const {
    assert(this->program > 0);
    auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
    glUniform1i(uniformAddr, value);
}

inline void Shader::setInt(const std::string &name, unsigned int value) const {
    assert(this->program > 0);
    auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
    glUniform1ui(uniformAddr, value);
}

inline void Shader::setFloat(const std::string &name, float value) const {
    assert(this->program > 0);
    auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
    glUniform1f(uniformAddr, value);
}

template <typename T>
inline void Shader::setMatrix(const std::string &name, T *value, size_t count) const {
    assert(this->program > 0);
    assert(count > 0 && count <= 4);

    auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
    const T *data = &value[0];
    if constexpr (std::is_floating_point<T>::value) {
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
inline void Shader::setVector(const std::string &name, T *value, size_t count) const {
    assert(this->program > 0);
    assert(count > 0 && count <= 4);

    auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
    const T *data = &value[0];
    if constexpr (std::is_floating_point<T>::value) {
        LOG(DEBUG) << "Setting uniform vector" << count;
        if (count == 1)
            glUniform1fv(uniformAddr, count, data);
        else if (count == 2)
            glUniform2fv(uniformAddr, count, data);
        else if (count == 3)
            glUniform3fv(uniformAddr, count, data);
        else if (count == 4)
            glUniform4fv(uniformAddr, count, data);
    } else if (std::is_unsigned<T>::value && std::is_integral<T>::value) {
        if (count == 1)
            glUniform1uiv(uniformAddr, count, data);
        else if (count == 2)
            glUniform2uiv(uniformAddr, count, data);
        else if (count == 3)
            glUniform3uiv(uniformAddr, count, data);
        else if (count == 4)
            glUniform4uiv(uniformAddr, count, data);
    } else if (std::is_integral<T>::value) {
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