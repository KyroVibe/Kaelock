#include "renderer/Triangle.hpp"

#include "util/Vec4.hpp"
#include "Debug.hpp"

struct Vertex {
        Vec4 position; Vec4 color;
    };

Vertex vertex_data[3] = {
    { Vec4( 0.0,  0.5, 0.0, 1.0), Vec4(1.0, 0.0, 0.0, 1.0) },
    { Vec4( 0.5, -0.5, 0.0, 1.0), Vec4(0.0, 1.0, 0.0, 1.0) },
    { Vec4(-0.5, -0.5, 0.0, 1.0), Vec4(0.0, 0.0, 1.0, 1.0) }
};

unsigned int index_data[3] = {
    0, 1, 2
};

const Bratva::Render::ShaderSource shaders[2] = {
    { "Res/Shaders/triangle_vs.glsl", GL_VERTEX_SHADER },
    { "Res/Shaders/triangle_fs.glsl", GL_FRAGMENT_SHADER }
};

const Bratva::Render::AttributePointer pointers[2] = {
    { 0, 4, GL_FLOAT, 0 },
    { 1, 4, GL_FLOAT, (void*)(sizeof(float) * 4) }
};

Triangle::Triangle() {

    LOG("Red: " << vertex_data[0].color.to_string());

    Debug::WHAT("Triangle Start");

    // LOG("Creating Vertex Buffer");
    _vertex_buffer = new Bratva::Render::VertexBuffer(sizeof(Vertex) * 3, vertex_data);

    Debug::WHAT("Post Vertex Buffer");

    // LOG("Creating Index Buffer");
    _index_buffer = new Bratva::Render::IndexBuffer(index_data, 3);

    Debug::WHAT("Post Index Buffer");

    // LOG("Compiling Shader Program");
    _program = new Bratva::Render::ShaderProgram(
        std::vector<Bratva::Render::ShaderSource>(shaders, shaders + 2)
    );
}

Triangle::~Triangle() {
    delete _program;

    delete _vertex_buffer;
    delete _index_buffer;

    LOG("Triangle GC");
}

void Triangle::Draw() {

    // _vertex_buffer->Bind();

    LOG("Enabling Program");
    _program->Enable();

    LOG("Binding Buffers");
    _vertex_buffer->Bind();
    _index_buffer->Bind();

    Debug::WHAT("Bound Buffers");

    LOG("Drawing Elements");
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

    Debug::WHAT("Drawn Elements");

    LOG("Disabling Program");
    _program->Disable();
}
