#include <chrono>
#include <string>

#include "gfx.hpp"

using namespace std::chrono;

namespace goat::gfx {

Shader::Shader(const std::string filePath, const ShaderType shaderType)
    : path(std::move(filePath)), handle(glCreateShader(static_cast<GLenum>(shaderType))) {
    std::ifstream ifs(path);
    std::string _shaderSource((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    if (_shaderSource.size() == 0)
        throw std::runtime_error("Shader '" + filePath + "' is empty");

    auto startTime = high_resolution_clock::now();
    auto shaderSource = reinterpret_cast<const GLchar *>(_shaderSource.c_str());
    glShaderSource(this->handle, 1, &shaderSource, nullptr);
    glCompileShader(this->handle);

    int success{};
    GLchar infoLog[512]{};
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

inline ShaderType Shader::getShaderType() const {
    return this->type;
}

}  // namespace goat::gfx