#pragma once
#include "StdHeader.h"

namespace Mogra {

  class Mesh{
  public:
    Mesh() = default;
    Mesh(std::vector<glm::vec3> _position) : positionv(_position) {}
    Mesh(std::vector<float> _position) : position(_position) {}
    ~Mesh() = default;

    std::vector<glm::vec3> GetPositionVec() {return positionv;}
    std::vector<float> GetPosition() {return position;}

    UINT VBO{0};
    
  private:
    std::vector<glm::vec3> positionv;
    std::vector<float> position;
    //std::vector<unsigned int> index;
    //std::vector<glm::vec2> texCoord;
    //std::vector<glm::vec3> normals;
  };

}
