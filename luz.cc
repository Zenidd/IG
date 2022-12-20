#include "auxiliar.h"
#include "luz.h"

// *****************************************************************************
//
// IG_D Clase Luz
//
// *****************************************************************************
// -----------------------------------------------------------------------------

void Luz::activar()
{
  glLightfv(id, GL_AMBIENT, colorAmbiente );
  glLightfv(id, GL_DIFFUSE, colorDifuso);
  glLightfv(id, GL_SPECULAR, colorEspecular );
  glLightfv(id, GL_POSITION, posicion);

  glEnable(id);
}

