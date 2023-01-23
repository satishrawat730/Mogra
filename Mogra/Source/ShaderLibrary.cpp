#include "ShaderLibrary.h"

namespace Mogra {

  std::shared_ptr<ShaderLibrary> ShaderLibrary::mInstance = nullptr;

  std::shared_ptr<ShaderLibrary> ShaderLibrary::Get(){
    if (mInstance == nullptr)
      mInstance = std::shared_ptr<ShaderLibrary>(new ShaderLibrary());
    return mInstance; 
  }

  void ShaderLibrary::LoadShaders() {

    std::string vertexShader = R"(C:\_MyData\Code Projects\Project Mogra\Mogra\Assets\Shaders\BasicShader.vert)";
    std::string fragmentShader = R"(C:\_MyData\Code Projects\Project Mogra\Mogra\Assets\Shaders\BasicShader.frag)";
    
    auto shader =  Shader::Create(vertexShader, fragmentShader);
    if(shader != nullptr)
      AddShader("Basic", shader);
  }

  void ShaderLibrary::AddShader(std::string shaderName, std::shared_ptr<Shader> _shader) {
   
    if (Shaders.find(shaderName) != Shaders.end())
      return;
    
    Shaders[shaderName] = _shader;
  }

  std::shared_ptr<Shader> ShaderLibrary::GetShader(std::string shaderName) {
    auto shaderPtr = Shaders.find(shaderName);

    if (shaderPtr != Shaders.end())
      return shaderPtr->second;
    else
      return nullptr;
  }

}