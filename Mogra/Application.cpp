#include "Application.h"

Application::Application(const std::string& app_name):AppName(app_name){
  mWindow = std::make_unique<Mogra::GLWindow>();
}

bool Application::Run(){

  mWindow->Render();

  return true;
}