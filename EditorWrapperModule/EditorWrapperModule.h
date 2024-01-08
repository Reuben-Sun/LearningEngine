#pragma once
#include "Engine.h"

namespace EditorWrapperModule
{
    class EditorEngine
    {
    public:
        EditorEngine() 
        {
            /*Engine::Engine engine;
            x = engine.getTest();*/
        };
        ~EditorEngine() {};

        int x = 1;
        int getX() const { return x; }
    };
}