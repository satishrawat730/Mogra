#pragma once

#include "StdHeader.h"

namespace Mogra {
  class Shader
  {
  public:
    static std::shared_ptr<Shader> Create(std::string vertexShaderfilePath, std::string fragmentShaderfilePath);

    ~Shader() = default;

    UINT GetShaderProgramID() { return ShaderProgramID; }

  private:
    Shader() = default;
    Shader(std::string vertexShaderfilePath, std::string fragmentShaderfilePath);
    std::string GetShaderCode(std::string filePath);
    UINT CompileShader(unsigned int type, const std::string& source);
    UINT CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
    
    UINT ShaderProgramID;
  };
}
