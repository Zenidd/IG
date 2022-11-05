#include "auxiliar.h"
#include "luzdireccional.h"

// *****************************************************************************
//
// IG_D Clase luzdireccional
//
// *****************************************************************************
// -----------------------------------------------------------------------------


LuzDireccional::LuzDireccional(const Tupla2f orientacion, GLenum idLuzOpenGL, Tupla4f colorA, Tupla4f colorE, Tupla4f colorD )
{
    this->posicion       = {orientacion[X], orientacion[Y], 0.0f, 0.0f };
    this->id             = idLuzOpenGL;
    this->colorAmbiente  = colorA;
    this->colorDifuso    = colorD;
    this->colorEspecular = colorE;
}

void LuzDireccional::variarAnguloAlpha(float incremento)
{
    alpha += incremento;
}

void LuzDireccional::variarAnguloBeta(float incremento)
{
    beta  += incremento;
}
