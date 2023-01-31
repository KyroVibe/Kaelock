#include "GameInstance.hpp"

#include "renderer/Triangle.hpp"

GameInstance::GameInstance(float width, float height, const char* title) : 
    _window(Window(width, height, title)) { }

GameInstance::~GameInstance() {
    
}

void GameInstance::run() {
    Triangle tri;

    while (!_window.should_close()) {

        glClear(GL_COLOR_BUFFER_BIT);

        tri.Draw();

        _window.swap_buffers();
        _window.poll_events();
    }
}
