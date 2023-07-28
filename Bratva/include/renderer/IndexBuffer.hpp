#pragma once

#include <GL/glew.h>

namespace Bratva::Render {

    class IndexBuffer {
    private:
        GLuint ibo;
    public:
        IndexBuffer(const unsigned int* data, const size_t num_indices);
        IndexBuffer(const IndexBuffer& _) = delete;
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;
    };

}
