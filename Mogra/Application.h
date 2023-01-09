#pragma once
#include "StdHeader.h"

class Application
{
public:
    Application(const std::string& app_name);
    ~Application() = default;
private:
    std::string AppName;
};

