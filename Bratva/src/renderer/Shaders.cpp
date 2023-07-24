//
// Made this a really long time ago and just keep reusing it
//

#include "renderer/Shaders.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

void ShaderErrorCheck(GLuint shader, const char* sourcePath) {
    GLint vertex_compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &vertex_compiled);
    if (vertex_compiled != GL_TRUE) {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(shader, 1024, &log_length, message);
        // Write the error to a log
        printf("Error in '%s' Shader:\n%s\n", sourcePath, message);
    }
}

void ProgramErrorCheck(GLuint program) {
    GLint program_linked;
    glGetProgramiv(program, GL_LINK_STATUS, &program_linked);
    if (program_linked != GL_TRUE) {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(program, 1024, &log_length, message);
        std::cout << "Error in GPU Program:\n" << message << std::endl;
    }
}

const char* ReadFile(const char* path) {
    std::ifstream vert_file;
    vert_file.open(path, std::ifstream::in);
    std::string contents;
    char c;
    while (vert_file.get(c)) {
        contents.push_back(c);
    }
    char* c_str = new char[contents.size() + 1]; // Not really the size because debug bs but it's whatever
    contents.copy(c_str, contents.size(), 0);
    c_str[contents.size()] = '\0';
    vert_file.close();
    return c_str;
}

//ShaderProgram* ShaderProgram::FromFiles(const char *vert, const char *frag) {
//    return new ShaderProgram(ReadFile(vert), ReadFile(frag));
//}

// template<unsigned int num_shaders, unsigned int num_pointers>
// ShaderProgram<num_shaders, num_pointers>::ShaderProgram(const ShaderSource* sources, unsigned int element_stride, const AttributePointer* pointers) {

//     // Shaders

//     GLuint shaderIds[num_shaders];

//     _program = glCreateProgram();
//     for (int i = 0; i < num_shaders; ++i) {
//         GLuint shaderId = glCreateShader(sources[i].type);
//         const char* source = ReadFile(sources[i].file.c_str());
//         glShaderSource(shaderId, 1, &source, NULL);
//         glCompileShader(shaderId);
//         ShaderErrorCheck(shaderId);
//         shaderIds[i] = shaderId;
//         glAttachShader(_program, shaderId); // Is this wrong?
//     }

//     glLinkProgram(_program);
//     ProgramErrorCheck(_program);

//     for (int i = 0; i < num_shaders; ++i) {
//         glDeleteShader(shaderIds[i]);
//     }

//     // Attributes

//     _attributes[num_pointers];

//     for (int i = 0; i < num_pointers; ++i) {
//         GLuint attrib = glGetAttribLocation(_program, pointers[i].name.c_str());
//         _attributes[i] = attrib;
//         glEnableVertexAttribArray(attrib);
//         glVertexAttribPointer(attrib, pointers[i].size, pointers[i].type, GL_FALSE, element_stride, pointers[i].offset);
//         glDisableVertexAttribArray(attrib);
//     }

// }

// template<unsigned int num_shaders, unsigned int num_pointers>
// ShaderProgram<num_shaders, num_pointers>::~ShaderProgram() {
//     glDeleteProgram(_program);
// }

// template<unsigned int num_shaders, unsigned int num_pointers>
// void ShaderProgram<num_shaders, num_pointers>::Enable() {
//     glUseProgram(_program);
//     for (int i = 0; i < _num_pointers; ++i) {
//         glEnableVertexAttribArray(_attributes[i]);
//     }
// }

// template<unsigned int num_shaders, unsigned int num_pointers>
// void ShaderProgram<num_shaders, num_pointers>::Disable() {
//     for (int i = 0; i < num_pointers; ++i) {
//         glDisableVertexAttribArray(_attributes[i]);
//     }
// }
