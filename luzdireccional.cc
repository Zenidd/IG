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
    alpha = orientacion[X];
    beta  = orientacion[Y];
    float x = cos(alpha)*sin(beta);
    float y = sin(alpha);
    float z = cos(alpha)*cos(beta);
    // float x = cos(orientacion[X])*sin(orientacion[Y]);
    // float y = sin(orientacion[X]);
    // float z = cos(orientacion[X])*cos(orientacion[Y]);
    this->posicion       = {x, y, z, 0.0f};
    this->id             = idLuzOpenGL;
    this->colorAmbiente  = colorA;
    this->colorDifuso    = colorD;
    this->colorEspecular = colorE;
}

void LuzDireccional::calcular_posicion()
{
    float x = cos(alpha)*sin(beta);
    float y = sin(alpha);
    float z = cos(alpha)*cos(beta);
    this->posicion       = {x, y, z, 0.0f};
}

void LuzDireccional::aumentarAnguloAlpha(float incremento)
{
    alpha+= 0.0174533;
    calcular_posicion();
    // std::cout << "Alpha ahora vale " << alpha << std::endl;
}

void LuzDireccional::aumentarAnguloBeta(float incremento)
{
    beta+= 0.0174533;
    calcular_posicion();
    // std::cout << "beta ahora vale " << beta << std::endl;
}

void LuzDireccional::disminuirAnguloAlpha(float incremento)
{
    alpha-= 0.0174533;
    calcular_posicion();
    // std::cout << "Alpha ahora vale " << alpha << std::endl;
}

void LuzDireccional::disminuirAnguloBeta(float incremento)
{
    beta-= 0.0174533;
    calcular_posicion();
    // std::cout << "beta ahora vale " << beta << std::endl;
}
