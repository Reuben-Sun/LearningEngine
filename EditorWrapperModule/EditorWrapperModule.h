#pragma once

namespace EditorWrapperModule
{
    class EditorEngine
    {
    public:
        EditorEngine() 
        {
            
        };
        ~EditorEngine() {};

        int x = 1;
        int getX() const { return x; }
    };
}