namespace goat::gfx
{
    class VertexBuffer
    {
    public:
        void apply(float *data);
        VertexBuffer(GLsizei size, GLenum _target = GL_ARRAY_BUFFER);
        ~VertexBuffer();

    private:
        GLenum kind;
        GLuint id;
        GLsizei max_size = 0;
    };

    void VertexBuffer::apply(float *data)
    {
        GLsizei size = sizeof(data);
        if (size > max_size)
            throw std::runtime_error("Data size exceeds buffer size");
        glBufferData(kind, size, data, GL_STATIC_DRAW);
    }

    VertexBuffer::VertexBuffer(GLsizei size, GLenum _target)
    {
        max_size = size;
        kind = _target;
        std::cout << "Creating a VertexBuffer of size " << max_size << std::endl;
        glGenBuffers(max_size, &id);
        glBindBuffer(kind, id);
        std::cout << "VertexBuffer=" << id << std::endl;
    }

    VertexBuffer::~VertexBuffer()
    {
        // glDeleteShader(1, &id);
    }
}