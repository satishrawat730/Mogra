#include "MeshRenderer.h"
namespace Mogra {

  std::shared_ptr<MeshRenderer> MeshRenderer::Create(Mesh _mesh, Shader _shader)
  {
    if( (_mesh.GetPositionVec().empty() || !_shader.GetShaderProgramID()) ) {
      return nullptr;
    }
    else {
      auto meshRenderer = std::shared_ptr<MeshRenderer>(new MeshRenderer( _mesh, _shader));
      meshRenderer->CreateVBO();
      return meshRenderer;
    }
  }

  void MeshRenderer::CreateVBO(){
    glGenBuffers(1, &mMesh.VBO);
    glBindBuffer(GL_ARRAY_BUFFER, mMesh.VBO);

    //glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mMesh.GetPosition().size(), &mMesh.GetPosition()[0], GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * mMesh.GetPositionVec().size(), &mMesh.GetPositionVec()[0], GL_STATIC_DRAW);

    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)(0 * sizeof(float)));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3) , (void*)(0 * sizeof(glm::vec3)));
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  void MeshRenderer::Render() {
    glUseProgram(mShader.GetShaderProgramID());
    glBindVertexArray(mMesh.VBO);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawArrays(GL_TRIANGLES, 0, mMesh.GetPositionVec().size());
  }
}