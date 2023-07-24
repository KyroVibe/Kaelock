#ifndef _BRATVA_DEBUG
#define _BRATVA_DEBUG

#include <iostream>
#include <GL/glew.h>
#include <string>

#define LOG(x) std::cout << "[LOG] " << x << " [END]\n"
#define ERROR(x) std::cout << "[ERROR] " << x << " [END]\n"

class Debug {
public:
    static void WHAT(std::string source) {
        GLenum error;
        while ((error = glGetError()) != GL_NO_ERROR) {
            printf("Error from '%s': x%x\n", source.c_str(), error);
        }
    }
};

#endif
