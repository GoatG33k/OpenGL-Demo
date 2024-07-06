
namespace goat::gfx
{
    static const int DEFAULT_SCREEN_WIDTH = 1600;
    static const int DEFAULT_SCREEN_HEIGHT = 900;

    auto load_shader_from_file(const std::string filePath, GLenum shaderType)
    {
        if (shaderType != GL_VERTEX_SHADER && shaderType != GL_FRAGMENT_SHADER)
            throw std::runtime_error("Invalid shader type specified. Must be either GL_VERTEX_SHADER or GL_FRAGMENT_SHADER.");

        LOG(DEBUG) << "Read shader from file: " << filePath;
        std::ifstream ifs(filePath);
        std::string shaderSource((std::istreambuf_iterator<char>(ifs)),
                                 (std::istreambuf_iterator<char>()));
        GLchar *shaderSourceCStr = (GLchar *)shaderSource.c_str();

        int success;
        char infoLog[512];

        auto shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(shader, 1, &shaderSourceCStr, NULL);
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            LOG(ERROR) << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                       << infoLog;
        }
    }
}

#include <VertexBuffer.cpp>
#include <VertexArray.cpp>