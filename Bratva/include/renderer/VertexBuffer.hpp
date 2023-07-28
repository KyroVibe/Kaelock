#pragma once

#include <GL/glew.h>

namespace Bratva::Render {

    class VertexBuffer {
    private:
        GLuint vao;
        GLuint vbo;
    public:
        VertexBuffer(const size_t size, const void* data);
        VertexBuffer(const VertexBuffer& _) = delete;
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;
    };

}
