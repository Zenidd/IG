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
    float x = cos(orientacion[X])*sin(orientacion[Y]);
    float y = sin(orientacion[X]);
    float z = cos(orientacion[X])*cos(orientacion[Y]);
    this->posicion       = {x, y, z, 0.0f};
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

void LuzDireccional::cambiarAngulo ()
{
    // std::cout << "Valor de Alpha es " << alpha  << "Valor de beta es " << beta << std::endl;
    glRotatef(alpha,0.0,1.0,0.0);
    glRotatef(beta,1.0,0.0,0.0);
}