#ifndef _BRATVA_GAME_INSTANCE
#define _BRATVA_GAME_INSTANCE

#include "Window.hpp"

class GameInstance {
private:
    Window _window;
public:
    GameInstance(float width, float height, const char* title);
    ~GameInstance();

    void run();
};

#endif
