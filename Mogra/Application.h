#pragma once
#include "StdHeader.h"
#include "GLWindow.h"

class Application
{
public:
    Application(const std::string& app_name);
    ~Application() = default;

    bool Run();
private:
    std::unique_ptr<Mogra::GLWindow> mWindow;
    std::string AppName;
};

