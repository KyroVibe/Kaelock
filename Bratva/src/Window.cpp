#include "Window.hpp"

#include <iostream>

Window::Window(int width, int height, const char* title) {

    _width = width;
    _height = height;

    /* Initialize the library */
    if (!glfwInit())
        return;

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
}

Window::~Window() {
    glfwTerminate();
}

bool Window::update() {
    glfwPollEvents();

    return !glfwWindowShouldClose(this->_window);
}
