#include <iostream>
#include <Windows.h>
#include "Engine.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    Engine::Engine engine;
    int x = engine.getTest();
    std::cout << "Hello, World!" << std::endl;
    std::cout << "x = " << x << std::endl;
    return 0;
}