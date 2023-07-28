#ifndef _BRATVA_RENDERER_TRAINGLE
#define _BRATVA_RENDERER_TRAINGLE

#include "renderer/Shaders.hpp"
#include "renderer/VertexBuffer.hpp"
#include "renderer/IndexBuffer.hpp"

class Triangle {
private:
    // If I have them stack allocated, they are created, copied and destroyed, destroying the original programs and data and what not.
    // I could fix this with some ownership hand off but its just easer to heap allocate them for now.
    Bratva::Render::ShaderProgram* _program;
    Bratva::Render::VertexBuffer* _vertex_buffer;
    Bratva::Render::IndexBuffer* _index_buffer;
public:
    Triangle();
    Triangle(const Triangle& _) = delete;
    ~Triangle();

    void Draw();
};

#endif
