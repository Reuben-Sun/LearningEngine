#include <iostream>
#include <Windows.h>
#include "Engine.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    Engine::Engine engine = Engine::Engine(800, 600, L"Engine");
    Engine::Application app = Engine::Application(&engine, hInstance, nCmdShow);
    while (app.needUpdate())
    {
        app.onUpdate();
    }
    return 0;
}