#include <iostream>
#include "Engine.h"

int main()
{
    Engine::Engine engine;
    int x = engine.getTest();
    std::cout << "Hello, World!" << std::endl;
    std::cout << "x = " << x << std::endl;
    return 0;
}