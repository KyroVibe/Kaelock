#ifndef _BRATVA_RENDERER_BUFFER
#define _BRATVA_RENDERER_BUFFER

#include <GL/glew.h>

class Buffer {
private:
    GLuint _buffer;
    GLenum _usage;
    GLenum _target;
public:

    Buffer() = default;
    Buffer(const Buffer& _) = delete;
    Buffer(GLenum target, GLenum usage);
    ~Buffer();

    void LoadBuffer(size_t size, const void* data);

    void Bind();

};

#endif
