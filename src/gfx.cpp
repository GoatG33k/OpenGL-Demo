#include "gfx.hpp"

#include <assert.h>
#include <easylogging++.h>

#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

namespace goat::gfx {

//
// ShaderProgram
//
void ShaderProgram::attachShader(Shader *shader) {
    GLuint shaderHandle = shader->getID();
    if (shaderHandle == 0)
        throw runtime_error("Invalid shader reference provided");

    LOG(DEBUG) << "Attaching shader " << shader->path << " to program " << program;
    shader->program = this->program;
    glAttachShader(program, shaderHandle);
}

bool ShaderProgram::link() {
    if (linked) {
        LOG(WARNING) << "Attempted to link a ShaderProgram that is already linked: " << program;
        return true;
    }

    int success;
    char infoLog[512];

    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        stringstream err;
        err << "Failed to link shader program: " << infoLog;
        LOG(ERROR) << err.str();
        throw runtime_error(err.str());
    }

    linked = true;
    LOG(INFO) << "Linked ShaderProgram: " << &program;
    return !!success;
}

//
// Shader
//
Shader::Shader(const string filePath, ShaderType shaderType) : path(std::move(filePath)), type(shaderType) {
    ifstream ifs(filePath);
    string _shaderSource((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));

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
        stringstream err;
        err << "[shader] [" << filePath << "] failed to compile: " << infoLog;

        LOG(ERROR) << err.str();
        throw runtime_error(err.str());
    }

    auto endTime = high_resolution_clock::now();
    LOG(INFO) << "[shader] [" << filePath << "] compiled " << strlen(shaderSource) << " bytes in "
              << duration_cast<milliseconds>(endTime - startTime).count() << "ms";
}

void Shader::setBool(const string name, bool value) const {
    assert(this->program > 0);
    auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
    glUniform1i(uniformAddr, value);
}

void Shader::setInt(const string name, int value) const {
    assert(this->program > 0);
    auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
    glUniform1i(uniformAddr, value);
}

void Shader::setFloat(const string name, float value) const {
    assert(this->program > 0);
    auto uniformAddr = glGetUniformLocation(this->program, name.c_str());
    glUniform1f(uniformAddr, value);
}

//
// EBO
//
EBO::EBO(const vector<unsigned int> &indices, DrawType drawType) {
    glGenBuffers(1, &this->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], (GLenum)drawType);
}

EBO::~EBO() {
    glDeleteBuffers(1, &this->ebo);
}
}  // namespace goat::gfx