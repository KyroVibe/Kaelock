#include <iostream>

#include "GameInstance.hpp"

int main() {
    
    std::cout << "Pong\n";

    GameInstance instance = GameInstance(800, 600, "Pong");
    instance.run();

    return 0;
}