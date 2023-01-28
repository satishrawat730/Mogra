#pragma once
#include "StdHeader.h"
#include "Mesh.h"

namespace Mogra {
  class Primitives
  {
  public:
    static Mesh CreateTriangle()
    {
      Mesh _mesh({
          {-1.0f, -1.0f, 0.0f},
        {1.0f, -1.0f, 0.0f},
        {0.f, 1.f, 0.0f} });

      return _mesh;
    }
  };
}
