#include "renderer/Triangle.hpp"

#include "util/Vec4.hpp"

struct Vertex {
        Vec4 position; Vec4 color;
    };

Vertex vertex_data[3] = {
    { Vec4( 0.0,  0.5, 0.0, 1.0), Vec4(1.0, 1.0, 1.0, 1.0) },
    { Vec4( 0.5, -0.5, 0.0, 1.0), Vec4(1.0, 1.0, 1.0, 1.0) },
    { Vec4(-0.5, -0.5, 0.0, 1.0), Vec4(1.0, 1.0, 1.0, 1.0) }
};

unsigned short index_data[3] = {
    0, 1, 2
};

const ShaderSource shaders[2] = {
    { "Res/Shaders/triangle_vs.glsl", GL_VERTEX_SHADER },
    { "Res/Shaders/triangle_fs.glsl", GL_FRAGMENT_SHADER }
};

const AttributePointer pointers[2] = {
    { "a_position", 4, GL_FLOAT, 0 },
    { "a_color", 4, GL_FLOAT, (void*)(sizeof(float) * 4) }
};

Triangle::Triangle() {

    _program = ShaderProgram<2, 2>(shaders, sizeof(Vertex), pointers);

    _vertex_buffer = Buffer(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
    _vertex_buffer.LoadBuffer(sizeof(Vertex) * 3, vertex_data);
    _index_buffer = Buffer(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW);
    _index_buffer.LoadBuffer(sizeof(unsigned short) * 3, index_data);
}

Triangle::~Triangle() { }

void Triangle::Draw() {
    _vertex_buffer.Bind();
    _index_buffer.Bind();

    _program.Enable();

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);

    _program.Disable();
}
