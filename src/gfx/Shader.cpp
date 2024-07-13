#include "Shader.hpp"

#include <chrono>
#include <string>

#include "constants.hpp"

using namespace std::chrono;

namespace goat::gfx {

Shader::Shader(std::string filePath, ShaderType shaderType)
    : handle(glCreateShader(static_cast<GLenum>(shaderType))), path(std::move(filePath)) {
    std::ifstream ifs(path);
    std::string _shaderSource((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    if (_shaderSource.empty())
        throw std::runtime_error("Shader '" + path + "' is empty");

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
        err << "[shader] [" << path << "] failed to compile: " << infoLog;

        LOG(ERROR) << err.str();
        throw std::runtime_error(err.str());
    }

    auto endTime = high_resolution_clock::now();
    LOG(INFO) << "[shader] [" << path << "] compiled " << _shaderSource.size() << " bytes in "
              << duration_cast<milliseconds>(endTime - startTime).count() << "ms";
}

Shader::~Shader() {
    LOG(DEBUG) << "free(Shader<" << this << ">)";
    if (this->handle != 0)
        glDeleteShader(handle);
}

Shader::Shader(Shader &&other) : path(std::move(other.path)), type(other.type), handle(other.handle) {
    other.handle = 0;
}

Shader &Shader::operator=(Shader &&other) {
    if (this == &other)
        return *this;

    path = std::move(other.path);
    type = other.type;
    handle = other.handle;

    other.handle = 0;
    return *this;
}

GLuint Shader::getHandle() const {
    return this->handle;
}

ShaderType Shader::getShaderType() const {
    return this->type;
}

}  // namespace goat::gfx