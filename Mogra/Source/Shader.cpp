#include "Shader.h"

namespace Mogra {

  std::shared_ptr<Shader> Shader::Create(std::string vertexShaderfilePath, std::string fragmentShaderfilePath)
  {
    if (vertexShaderfilePath.empty() || fragmentShaderfilePath.empty()) {
      return nullptr;
    }
    else {
          std::shared_ptr<Shader> shader = std::shared_ptr<Shader>(new Shader(vertexShaderfilePath, fragmentShaderfilePath));
      return shader;
    }
  }

  Shader::Shader(std::string vertexShaderfilePath, std::string fragmentShaderfilePath) {
    
      std::string vertexShaderCode = GetShaderCode(vertexShaderfilePath);
      std::string fragmentShaderCode = GetShaderCode(fragmentShaderfilePath);

      if (!(vertexShaderCode.empty() || fragmentShaderCode.empty())) {
        ShaderProgramID = CreateShader(vertexShaderCode, fragmentShaderCode);
      }
  }

  std::string Shader::GetShaderCode(std::string shaderfilePath) {
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
      shaderFile.open(shaderfilePath);
      std::stringstream sStream;
      sStream << shaderFile.rdbuf();

      return sStream.str();
    }
    catch (const std::exception& ex)
    {
      std::cout << "ERROR: Exception occured while reading Shader File: "<< shaderfilePath << ". " << ex.what();
      return "";
    }
  }

  unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (!result) {
      int length;
      glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
      char* message = (char*) _malloca(length * sizeof(char));
      glGetShaderInfoLog(id, length, &length, message);
      std::cout << "Failed to compile "
        << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") << " shader";
      std::cout << "\n" << message << std::endl;
     }

    return id;
  }

  unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {

    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
  }

}