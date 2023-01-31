#include "renderer/Buffer.hpp"

Buffer::Buffer(GLenum target, GLenum usage): _target(target), _usage(usage) {
    glGenBuffers(1, &_buffer);
}

Buffer::~Buffer() {
    glDeleteBuffers(1, &_buffer);
}

void Buffer::Bind() {
    glBindBuffer(_target, _buffer);
}

void Buffer::LoadBuffer(size_t size, const void* data) {
    Bind();
    glBufferData(_target, size, data, _usage);
}
