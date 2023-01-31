//
// Created by hunte on 12/10/2021.
//

#include "renderer/Shaders.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void ShaderErrorCheck(GLuint shader) {
    GLint vertex_compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &vertex_compiled);
    if (vertex_compiled != GL_TRUE) {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(shader, 1024, &log_length, message);
        // Write the error to a log
        std::cout << "Error: \n" << message << std::endl;
    }
}

void ProgramErrorCheck(GLuint program) {
    GLint program_linked;
    glGetProgramiv(program, GL_LINK_STATUS, &program_linked);
    if (program_linked != GL_TRUE) {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(program, 1024, &log_length, message);
        std::cout << "Error: \n" << message << std::endl;
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

ShaderProgram::ShaderProgram(unsigned int num_shaders, ShaderSource* sources) {

    std::vector<GLuint> shaderIds;

    program = glCreateProgram();
    // Shaders
    for (int i = 0; i < num_shaders; ++i) {
        GLuint shaderId = glCreateShader(sources[i].type);
        const char* source = ReadFile(sources[i].file.c_str());
        // std::cout << "Source: \n" << source << std::endl;
        glShaderSource(shaderId, 1, &source, NULL);
        glCompileShader(shaderId);
        ShaderErrorCheck(shaderId);
        shaderIds.push_back(shaderId);
    }
    for (auto iter = shaderIds.begin(); iter != shaderIds.end(); iter++) {
        glAttachShader(program, *iter);
    }

    glLinkProgram(program);

    ProgramErrorCheck(program);

    for (auto iter = shaderIds.begin(); iter != shaderIds.end(); iter++) {
        glDeleteShader(*iter); // I think that's how you iter?
    }
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(program);
}

VertexAttributes::VertexAttributes(size_t stri, std::vector<AttributePointer> ptrs) {
    pointers = ptrs;
    stride = stri;
}

VertexAttributes::~VertexAttributes() { }

void VertexAttributes::enable() {
    for (auto iter = indexes.begin(); iter != indexes.end(); iter++) {
        glEnableVertexAttribArray(*iter);
    }
}

void VertexAttributes::disable() {
    for (auto iter = indexes.begin(); iter != indexes.end(); iter++) {
        glDisableVertexAttribArray(*iter);
    }
}

void VertexAttributes::init(ShaderProgram* program) {
    indexes.clear();
    for (int i = 0; i < pointers.size(); ++i) {
        auto attrib = glGetAttribLocation(program->get_program(), pointers.at(i).attribute_name.c_str());
        indexes.push_back(attrib);
        glEnableVertexAttribArray(attrib);
        glVertexAttribPointer(attrib, pointers.at(i).size, pointers.at(i).type, GL_FALSE, stride, pointers.at(i).offset);
        glDisableVertexAttribArray(attrib);
    }
}
