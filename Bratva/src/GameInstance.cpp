#include "GameInstance.hpp"

#include "renderer/Triangle.hpp"

GameInstance::GameInstance(float width, float height, const char* title) : 
    _window(Window(width, height, title)) { }

GameInstance::~GameInstance() {
    LOG("Game Instance GC");
}

void GameInstance::run() {

    if (!_window.has_glfw_window()) {
        ERROR("No Window");
        return;
    }

    Triangle tri;

    glClear(GL_COLOR_BUFFER_BIT);
    tri.Draw();
    _window.swap_buffers();

    while (!_window.should_close()) {
        _window.poll_events();
    }

    LOG("End of Runtime");
}
