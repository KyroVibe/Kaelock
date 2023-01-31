//
// Made this a really long time ago and just keep reusing it
//

#ifndef _BRATVA_RENDERER_SHADERS
#define _BRATVA_RENDERER_SHADERS

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <string>
#include <vector>

typedef struct { std::string file; GLenum type; } ShaderSource;
typedef struct { std::string name; unsigned int size; GLenum type; void* offset; } AttributePointer;

void ShaderErrorCheck(GLuint shader);
void ProgramErrorCheck(GLuint program);
const char* ReadFile(const char* path);

template<unsigned int num_shaders, unsigned int num_pointers>
class ShaderProgram {
private:
    GLuint _program;
    GLuint _attributes[num_pointers];
public:
    
    // template<unsigned int num_shaders, unsigned int num_pointers>
    ShaderProgram() = default;
    ShaderProgram(const ShaderProgram<num_shaders, num_pointers>& _) = delete;
    ShaderProgram(
        const ShaderSource* sources,
        unsigned int element_stride,
        const AttributePointer* pointers)
    {

        GLuint shaderIds[num_shaders];

        _program = glCreateProgram();
        for (int i = 0; i < num_shaders; ++i) {
            GLuint shaderId = glCreateShader(sources[i].type);
            const char* source = ReadFile(sources[i].file.c_str());
            std::cout << "Source:\n" << source << "\n\n";
            glShaderSource(shaderId, 1, &source, NULL);
            glCompileShader(shaderId);
            ShaderErrorCheck(shaderId);
            shaderIds[i] = shaderId;
            glAttachShader(_program, shaderId); // Is this wrong?
        }

        glLinkProgram(_program);
        ProgramErrorCheck(_program);

        for (int i = 0; i < num_shaders; ++i) {
            glDeleteShader(shaderIds[i]);
        }

        // Attributes

        _attributes[num_pointers];

        for (int i = 0; i < num_pointers; ++i) {
            GLuint attrib = glGetAttribLocation(_program, pointers[i].name.c_str());
            _attributes[i] = attrib;
            glEnableVertexAttribArray(attrib);
            glVertexAttribPointer(attrib, pointers[i].size, pointers[i].type, GL_FALSE, element_stride, pointers[i].offset);
            glDisableVertexAttribArray(attrib);
        }

    }
    ~ShaderProgram() {
        glDeleteProgram(_program);
    }

    void Enable() {
        glUseProgram(_program);
        for (int i = 0; i < num_pointers; ++i) {
            glEnableVertexAttribArray(_attributes[i]);
        }
    }
    void Disable() {
        for (int i = 0; i < num_pointers; ++i) {
            glDisableVertexAttribArray(_attributes[i]);
        }
    }

    // inline GLuint get_program() { return _program; }

    // static ShaderProgram* FromFiles(int num_shaders, Shader* shaders);
};

// struct AttributePointer {
// public:
//     std::string attribute_name;
//     int size;
//     GLenum type;
//     void* offset;
// };

// class VertexAttributes {
// public:
//     size_t stride;
//     std::vector<AttributePointer> pointers;
//     std::vector<unsigned int> indexes;

// 	VertexAttributes() { }
//     VertexAttributes(size_t stri, std::vector<AttributePointer> ptrs);
//     ~VertexAttributes();

//     void enable();
//     void disable();
//     void init(ShaderProgram* program);
// };

#endif // _BRATVA_RENDERER_SHADERS
