#pragma once
#include "StdHeader.h"
#include "MeshRenderer.h"

namespace Mogra {
    class GLWindow
    {
    public:
        GLWindow();
        ~GLWindow();
        
        bool Init();
        void Render();

    private:
        GLFWwindow* window = nullptr;
        std::shared_ptr<MeshRenderer> objTriangle = nullptr;
        UINT shader;
    };
}
