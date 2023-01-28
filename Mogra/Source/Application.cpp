#include "Application.h"

namespace Mogra {

  Application::Application(const std::string& app_name) :AppName(app_name) {
    wchar_t buffer[MAX_PATH];  //or wchar_t * buffer;
    GetModuleFileName(NULL, buffer, MAX_PATH);
    //std::cout << buffer;

   // std::filesystem::copy("C:/Users/", "E:/Backup/");

    namespace fs = std::filesystem;

      std::string path = R"(C:\_MyData\Code Projects\Project Mogra\Mogra\Assets\Shaders)";
      for (const auto& entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
    
     mWindow = std::make_unique<Mogra::GLWindow>();
     mWindow->Init();
   
   //LoadShaders();
  }

  bool Application::Run() {

    mWindow->Render();

    return true;
  }

  void Application::LoadShaders() {
    ShaderLibrary::Get()->LoadShaders();
  }

}