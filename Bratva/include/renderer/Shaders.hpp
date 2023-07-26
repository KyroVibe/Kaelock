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

#include "Debug.hpp"

namespace Bratva {
    namespace Render {

        struct ShaderSource { std::string file; GLenum type; };
        struct AttributePointer { GLuint location; unsigned int size; GLenum type; void* offset; };

        void ShaderErrorCheck(GLuint shader, const char* sourcePath);
        void ProgramErrorCheck(GLuint program);
        const char* ReadFile(const char* path);

        class ShaderProgram {
        private:
            GLuint  _program;
            GLuint  _vao;
            GLuint* _attributes;
            size_t  _attribute_count;
        public:
            
            ShaderProgram(const ShaderProgram& _) = delete;

            ShaderProgram(
                std::vector<ShaderSource> sources,
                unsigned int element_stride,
                std::vector<AttributePointer> pointers
            );
            ~ShaderProgram();

            void Enable();
            void Disable();

        };

    }
}

#endif // _BRATVA_RENDERER_SHADERS
