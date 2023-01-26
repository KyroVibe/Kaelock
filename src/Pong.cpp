#include "Window.hpp"

#include <iostream>

int main() {
    
    Window w(400, 400);

    while (w.update()) {
        std::cout << "Hello\n";        
    }

    return 0;
}