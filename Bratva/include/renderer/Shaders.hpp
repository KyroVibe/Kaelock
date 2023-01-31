//
// Created by hunte on 12/10/2021.
//

#ifndef _BRATVA_RENDERER_SHADERS
#define _BRATVA_RENDERER_SHADERS

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <vector>

typedef struct { std::string file; GLenum type; } ShaderSource;

class ShaderProgram {
private:
    GLuint program;
public:
    ShaderProgram(unsigned int num_shaders, ShaderSource* sources);
    ~ShaderProgram();

    inline GLuint get_program() { return program; }

    // static ShaderProgram* FromFiles(int num_shaders, Shader* shaders);
};

struct AttributePointer {
public:
    std::string attribute_name;
    int size;
    GLenum type;
    void* offset;
};

class VertexAttributes {
public:
    size_t stride;
    std::vector<AttributePointer> pointers;
    std::vector<unsigned int> indexes;

	VertexAttributes() { }
    VertexAttributes(size_t stri, std::vector<AttributePointer> ptrs);
    ~VertexAttributes();

    void enable();
    void disable();
    void init(ShaderProgram* program);
};

#endif // _BRATVA_RENDERER_SHADERS
