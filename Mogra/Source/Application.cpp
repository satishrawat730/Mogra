#include "Application.h"

namespace Mogra {

  Application::Application(const std::string& app_name) :AppName(app_name) {
    wchar_t buffer[MAX_PATH];  //or wchar_t * buffer;
    GetModuleFileName(NULL, buffer, MAX_PATH);
    //std::cout << buffer;

   // std::filesystem::copy("C:/Users/", "E:/Backup/");

    mWindow = std::make_unique<Mogra::GLWindow>();
    LoadShaders();
  }

  bool Application::Run() {

    mWindow->Render();

    return true;
  }

  void Application::LoadShaders() {
    ShaderLibrary::Get()->LoadShaders();
  }

}