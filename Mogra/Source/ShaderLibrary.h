#pragma once

#include "StdHeader.h"
#include "Shader.h"

namespace Mogra {
  class ShaderLibrary
  {
  public:
    static std::shared_ptr<ShaderLibrary> Get();
   
    ~ShaderLibrary() = default;
    void LoadShaders();
    std::shared_ptr<Shader> GetShader(std::string shaderName);

  private:
    static std::shared_ptr<ShaderLibrary> mInstance;

    ShaderLibrary() = default;
    void AddShader(std::string shaderName, std::shared_ptr<Shader> shader);

    std::map< std::string, std::shared_ptr<Shader>> Shaders; // shader name and shader object mapping
  };
}

