#include <iostream>
#include <Windows.h>
#include "Engine.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    Engine::Engine engine = Engine::Engine(800, 600, L"Engine");
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}