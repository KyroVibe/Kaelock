#include <iostream>

#include "GameInstance.hpp"
#include "NeuralNetwork.hpp"

int main() {

    GameInstance game(600, 600, "Some game");
    game.run();

    return 0;
}