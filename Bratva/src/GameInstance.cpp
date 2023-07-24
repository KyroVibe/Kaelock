#include "GameInstance.hpp"

#include <chrono>

#include "renderer/Triangle.hpp"
#include "Debug.hpp"

GameInstance::GameInstance(float width, float height, const char* title) : 
    _window(Window(width, height, title)) { }

GameInstance::~GameInstance() {
    LOG("Game Instance GC");
}

#define RENDER_LOOP_FPS (1.0 / 60.0)

void GameInstance::run() {
    Triangle tri;

    auto lastUpdate = std::chrono::system_clock::now();
    std::chrono::duration<double> deltaT;

    while (!_window.should_close()) {

        _window.poll_events();
        deltaT = std::chrono::system_clock::now() - lastUpdate;

        if (deltaT.count() < RENDER_LOOP_FPS) {
            continue;
        }

        lastUpdate = std::chrono::system_clock::now();

        tri.Update(deltaT);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
        tri.Draw();
        _window.swap_buffers();
    }

    LOG("End of Runtime");
}
