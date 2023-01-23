#pragma once
#include "StdHeader.h"
#include "GLWindow.h"

#include "ShaderLibrary.h"

namespace Mogra {

  class Application
  {
  public:
    Application(const std::string& app_name);
    ~Application() = default;

    bool Run();
  private:
    void LoadShaders();

    std::unique_ptr<Mogra::GLWindow> mWindow;
    std::string AppName;
  };

}
