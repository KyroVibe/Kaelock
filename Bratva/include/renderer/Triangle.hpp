#ifndef _BRATVA_RENDERER_TRAINGLE
#define _BRATVA_RENDERER_TRAINGLE

#include "renderer/Shaders.hpp"
#include "renderer/Buffer.hpp"

class Triangle {
private:
    // If I have them stack allocated, they are created, copied and destroyed, destroying the original programs and data and what not.
    // I could fix this with some ownership hand off but its just easer to heap allocate them for now.
    ShaderProgram<2, 2>* _program;
    Buffer* _vertex_buffer;
    Buffer* _index_buffer;
public:
    Triangle();
    Triangle(const Triangle& _) = delete;
    ~Triangle();

    void Draw();
};

#endif
