
namespace goat::gfx
{
    class VertexArray
    {
    public:
        VertexArray(GLenum _kind, unsigned int attribIndex = 0)
        {
            kind = _kind;
            glGenVertexArrays(1, &id);
            glBindBuffer(kind, id);
            glEnableVertexAttribArray(attribIndex);
            glBindVertexArray(id);
        };

        void apply(float *data)
        {
            glBufferData(kind, sizeof(data), data, GL_STATIC_DRAW);
        };

        GLuint get_id() { return id; };

    private:
        GLuint id;
        GLuint size;
        GLenum kind;
        ~VertexArray();
    };
}