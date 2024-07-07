#include <cstddef>
#include <GL/glext.h>

#ifdef MACOS
#define PFNGLCOMPILERSHADERPROC PFNGLSPECIALIZESHADERPROC
#endif // MACOS
static PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = NULL;
static PFNGLBINDVERTEXARRAYPROC glBindVertexArray = NULL;
static PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback = NULL;
static PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced = NULL;

#ifdef WIN32
 static PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers = NULL;
 static PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer = NULL;
 static PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D = NULL;
 static PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus = NULL;
 static PFNGLUNIFORM1IPROC glUniform1i = NULL;
 static PFNGLDRAWBUFFERSPROC glDrawBuffers = NULL;
 static PFNGLUNIFORM4FPROC glUniform4f = NULL;
 static PFNGLDELETEPROGRAMPROC glDeleteProgram = NULL;
 static PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = NULL;
 static PFNGLUNIFORM2FPROC glUniform2f = NULL;
 static PFNGLGENBUFFERSPROC glGenBuffers = NULL;
 static PFNGLBINDBUFFERPROC glBindBuffer = NULL;
 static PFNGLBUFFERDATAPROC glBufferData = NULL;
 static PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = NULL;
 static PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = NULL;
 static PFNGLUNIFORM1FPROC glUniform1f = NULL;
 static PFNGLBUFFERSUBDATAPROC glBufferSubData = NULL;
 static PFNGLCREATESHADERPROC glCreateShader = NULL;
 static PFNGLSHADERSOURCEPROC glShaderSource = NULL;
 static PFNGLCOMPILESHADERPROC glCompileShader = NULL;
 static PFNGLGETSHADERIVPROC glGetShaderiv = NULL;
 static PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = NULL;
 static PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
 static PFNGLATTACHSHADERPROC glAttachShader = NULL;
 static PFNGLLINKPROGRAMPROC glLinkProgram = NULL;
 static PFNGLGETPROGRAMIVPROC glGetProgramiv = NULL;
 static PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = NULL;
 static PFNGLDELETESHADERPROC glDeleteShader = NULL;
 static PFNGLUSEPROGRAMPROC glUseProgram = NULL;
static PFNGLACTIVETEXTUREPROC glActiveTexture = NULL;
#endif // WIN32

inline GLFWglproc getProcAddress(const char *name)
{
    GLFWglproc addr = glfwGetProcAddress(name);
    if (addr == NULL)
    {
        throw std::runtime_error("Failed to load OpenGL function " + std::string(name));
    }
    return addr;
}

static void load_gl_extensions(void)
{
    glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)getProcAddress("glGenVertexArrays");
    glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)getProcAddress("glBindVertexArray");
#ifdef WIN32
    // TODO: check for failures?
    // Maybe some of the functions are not available
    glCreateShader = (PFNGLCREATESHADERPROC)getProcAddress("glCreateShader");
    glShaderSource = (PFNGLSHADERSOURCEPROC)getProcAddress("glShaderSource");
    glCompileShader = (PFNGLCOMPILESHADERPROC)getProcAddress("glCompileShader");
    glGetShaderiv = (PFNGLGETSHADERIVPROC)getProcAddress("glGetShaderiv");
    glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)getProcAddress("glGetShaderInfoLog");
    glAttachShader = (PFNGLATTACHSHADERPROC)getProcAddress("glAttachShader");
    glCreateProgram = (PFNGLCREATEPROGRAMPROC)getProcAddress("glCreateProgram");
    glLinkProgram = (PFNGLLINKPROGRAMPROC)getProcAddress("glLinkProgram");
    glGetProgramiv = (PFNGLGETPROGRAMIVPROC)getProcAddress("glGetProgramiv");
    glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)getProcAddress("glGetProgramInfoLog");
    glDeleteShader = (PFNGLDELETESHADERPROC)getProcAddress("glDeleteShader");
    glUseProgram = (PFNGLUSEPROGRAMPROC)getProcAddress("glUseProgram");
    glDeleteProgram = (PFNGLDELETEPROGRAMPROC)getProcAddress("glDeleteProgram");
    glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)getProcAddress("glGetUniformLocation");
    glUniform2f = (PFNGLUNIFORM2FPROC)getProcAddress("glUniform2f");
    glGenBuffers = (PFNGLGENBUFFERSPROC)getProcAddress("glGenBuffers");
    glBindBuffer = (PFNGLBINDBUFFERPROC)getProcAddress("glBindBuffer");
    glBufferData = (PFNGLBUFFERDATAPROC)getProcAddress("glBufferData");
    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)getProcAddress("glEnableVertexAttribArray");
    glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)getProcAddress("glVertexAttribPointer");
    glUniform1f = (PFNGLUNIFORM1FPROC)getProcAddress("glUniform1f");
    glBufferSubData = (PFNGLBUFFERSUBDATAPROC)getProcAddress("glBufferSubData");
    glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)getProcAddress("glGenFramebuffers");
    glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)getProcAddress("glBindFramebuffer");
    glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)getProcAddress("glFramebufferTexture2D");
    glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)getProcAddress("glCheckFramebufferStatus");
    glUniform1i = (PFNGLUNIFORM1IPROC)getProcAddress("glUniform1i");
    glDrawBuffers = (PFNGLDRAWBUFFERSPROC)getProcAddress("glDrawBuffers");
    glUniform4f = (PFNGLUNIFORM4FPROC)getProcAddress("glUniform4f");
    glActiveTexture = (PFNGLACTIVETEXTUREPROC)getProcAddress("glActiveTexture");
#endif // WIN32

    if (glfwExtensionSupported("GL_ARB_debug_output"))
    {
        fprintf(stderr, "INFO: ARB_debug_output is supported\n");
#ifdef WIN32
        glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)glfwGetProcAddress("glDebugMessageCallback");
#endif // WIN32
    }
    else
    {
        fprintf(stderr, "WARN: ARB_debug_output is NOT supported\n");
    }

    if (glfwExtensionSupported("GL_EXT_draw_instanced"))
    {
        fprintf(stderr, "INFO: EXT_draw_instanced is supported\n");
#ifdef WIN32
        glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)glfwGetProcAddress("glDrawArraysInstanced");
#endif // WIN32
    }
    else
    {
        fprintf(stderr, "WARN: EXT_draw_instanced is NOT supported\n");
    }
}