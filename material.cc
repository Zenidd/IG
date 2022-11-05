#include "auxiliar.h"
#include "material.h"

// *****************************************************************************
//
// IG_D Clase material
//
// *****************************************************************************
// -----------------------------------------------------------------------------

Material::Material()
{
}


Material::Material(Tupla4f mdifuso, Tupla4f mespecular, Tupla4f mambiente ,float mbrillo )
{
    this->brillo    = mbrillo;
    this->ambiente  = mambiente;
    this->difuso    = mdifuso;
    this->especular = mespecular;
}



void Material::aplicar()
{

// glMaterialfv(CARAS, PROPIEDAD, VALOR);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difuso);
    glMaterialfv(GL_FRONT, GL_SPECULAR, especular);
    glMaterialfv(GL_FRONT, GL_SHININESS, &brillo);
}

