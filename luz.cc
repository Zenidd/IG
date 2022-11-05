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
  // glLightfv(LUZ,PARAMETRO,VALOR);
  glLightfv(id, GL_AMBIENT, colorAmbiente );
  glLightfv(id, GL_DIFFUSE, colorDifuso);
  glLightfv(id, GL_SPECULAR, colorEspecular );


  glEnable(id);
}

