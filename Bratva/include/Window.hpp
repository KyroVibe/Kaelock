#ifndef _BRATVA_WINDOW
#define _BRATVA_WINDOW

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
private:
    int _width, _height;
    GLFWwindow* _window;
public:
    Window(int width, int height, const char* title);
    ~Window();

    inline GLFWwindow* get_window() { return _window; }
    inline int get_width() { return _width; }
    inline int get_height() { return _height; }

    void poll_events();
    bool should_close();
    void swap_buffers();
};

#endif
