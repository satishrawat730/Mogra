#pragma once
#include "StdHeader.h"

namespace Mogra {
    class GLWindow
    {
    public:
        GLWindow();
        ~GLWindow();
        
        void Init();

        void Render();

    private:
        GLFWwindow* window = nullptr;
    };
}
