#pragma once
#include "StdHeader.h"
#include "Mesh.h"
#include "Shader.h"

namespace Mogra {
  class MeshRenderer
  {
  public:
    static std::shared_ptr<MeshRenderer> Create(Mesh _mesh, Shader _shader);
    ~MeshRenderer() = default;
    
    void Render();
    Shader mShader;
    Mesh mMesh;

  private:
    MeshRenderer() = default;
    MeshRenderer(Mesh _mesh, Shader _shader) : mMesh( _mesh), mShader( _shader) {}

    void CreateVBO( );
  };
}
