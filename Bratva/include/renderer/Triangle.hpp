#ifndef _BRATVA_RENDERER_TRAINGLE
#define _BRATVA_RENDERER_TRAINGLE

#include "renderer/Shaders.hpp"
#include "renderer/Buffer.hpp"

class Triangle {
private:
    ShaderProgram<2, 2> _program;
    Buffer _vertex_buffer;
    Buffer _index_buffer;
public:
    Triangle();
    Triangle(const Triangle& _) = delete;
    ~Triangle();

    void Draw();
};

#endif
