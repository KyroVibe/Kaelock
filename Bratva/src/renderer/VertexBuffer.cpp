#include "renderer/VertexBuffer.hpp"

namespace Bratva::Render {

    VertexBuffer::VertexBuffer(const size_t size, const void* data) {

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

        // Vertex Position @ Location 0
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 8, 0);
        // Vertex Color @ Location 1
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 8, (void*)(sizeof(GL_FLOAT) * 4));
    }

    VertexBuffer::~VertexBuffer() {
        Unbind();
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
    }

    void VertexBuffer::Bind() const {
        glBindVertexArray(vao);
    }

    void VertexBuffer::Unbind() const {
        glBindVertexArray(0);
    }

}
