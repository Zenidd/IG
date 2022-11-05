#include "auxiliar.h"
#include "luzposicional.h"

// *****************************************************************************
//
// IG_D Clase luzposicional
//
// *****************************************************************************
// -----------------------------------------------------------------------------


LuzPosicional::LuzPosicional(const Tupla3f pos, GLenum idLuzOpenGL, Tupla4f colorA, Tupla4f colorE, Tupla4f colorD )
{

    posicion       = {pos[X], pos[Y], pos[Z], 1.0f };
    id             = idLuzOpenGL;
    colorAmbiente  = colorA;
    colorDifuso    = colorD;
    colorEspecular = colorE;
}
