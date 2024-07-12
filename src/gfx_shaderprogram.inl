#include "gfx.hpp"

namespace goat::gfx {

ShaderProgram::ShaderProgram() : linked(false) {
    this->program = glCreateProgram();
};

ShaderProgram::~ShaderProgram() {
    for (auto shader : this->bound)
        delete shader;

    if (this->program != 0)
        glDeleteProgram(this->program);
}

inline void ShaderProgram::use() const {
    glUseProgram(this->program);
}

inline int ShaderProgram::getUniformLocation(char *name) const {
    return glGetUniformLocation(this->program, name);
}

constexpr inline bool ShaderProgram::isLinked() {
    return this->linked;
}

void ShaderProgram::attachShader(Shader *shader) {
    GLuint shaderHandle = shader->getHandle();
    if (shaderHandle == 0)
        throw std::runtime_error("Invalid shader reference provided");

    LOG(DEBUG) << "Attaching shader " << shader->path << " to program " << program;
    shader->program = this->program;
    glAttachShader(program, shaderHandle);
}

bool ShaderProgram::link() {
    if (linked)
        throw std::runtime_error("ShaderProgram is already linked");

    int success;
    char infoLog[512];

    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::stringstream err;
        err << "Failed to link shader program: " << infoLog;
        LOG(ERROR) << err.str();
        throw std::runtime_error(err.str());
    }

    linked = true;
    LOG(INFO) << "Linked ShaderProgram: " << &program;
    return !!success;
}

}  // namespace goat::gfx