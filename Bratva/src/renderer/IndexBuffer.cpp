#include "renderer/IndexBuffer.hpp"

namespace Bratva::Render {

    IndexBuffer::IndexBuffer(const unsigned int* data, const size_t num_indices) {
        glGenBuffers(1, &ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * num_indices, data, GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer() {
        Unbind();
        glDeleteBuffers(1, &ibo);
    }

    void IndexBuffer::Bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    }

    void IndexBuffer::Unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

}