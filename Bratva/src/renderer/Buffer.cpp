#include "renderer/Buffer.hpp"

#include "Debug.hpp"

namespace Bratva::Render {

    Buffer::Buffer(GLenum target, GLenum usage, bool isVertexArray): _target(target), _usage(usage), _isVertexArray(isVertexArray) {
        glGenBuffers(1, &_buffer);
        Debug::WHAT("Gen Buffers");
    }

    Buffer::~Buffer() {
        glDeleteBuffers(1, &_buffer);

        LOG("Buffer GC");
    }

    void Buffer::Bind() {
        glBindBuffer(_target, _buffer);
        Debug::WHAT("Binding Buffer");
    }

    void Buffer::Unbind() {
        glBindBuffer(_target, 0);
    }

    void Buffer::LoadBuffer(size_t size, const void* data) {
        Bind();
        glBufferData(_target, size, data, _usage);
        Unbind();
        Debug::WHAT("Loading Buffer with Data");
    }

}
