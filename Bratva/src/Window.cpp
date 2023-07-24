#include "Window.hpp"

#include <iostream>

void glfwError(int id, const char* desc) {
    printf("[%i] %s\n", id, desc);
}

void GLAPIENTRY MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}

Window::Window(int width, int height, const char* title) {

    _width = width;
    _height = height;

    glfwSetErrorCallback(glfwError);

    /* Initialize the library */
    if (!glfwInit())
        return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!_window) {
        glfwTerminate();
        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(_window);

    GLenum glewResult = glewInit();
    if (glewResult != GLEW_OK) {
        std::cout << glewGetErrorString(glewResult) << std::endl;
        glfwTerminate();
        return;
    }

    // glEnable(GL_DEBUG_OUTPUT);
    // glDebugMessageCallback(MessageCallback, 0);

    const char* version = (char*)glGetString(GL_VERSION);
    printf("OpenGL Version: %s\n", version);
}

Window::~Window() {
    glfwTerminate();
}

void Window::poll_events() {
    glfwPollEvents();
}

void Window::swap_buffers() {
    glfwSwapBuffers(_window);
}

bool Window::should_close() { return glfwWindowShouldClose(_window); }
