// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: material.h
// -- declaraciones de clase material
//
// #############################################################################

#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "auxiliar.h"
#include "material.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************


class Material {
   public:
      Tupla4f ambiente= { 0.7, 0.7, 0.7, 1.0 };
      Tupla4f difuso=  { 0.1, 0.5, 0.8, 1.0 };
      Tupla4f especular=  { 0.5, 0.5, 0.5, 0.5 };
      GLfloat brillo= 50.0f;
      // Tupla4f ambiente;
      // Tupla4f difuso;
      // Tupla4f especular;
      // GLfloat brillo;
   public:
      Material();
      Material(Tupla4f mdifuso, Tupla4f mespecular, Tupla4f mambiente ,float mbrillo );
      void aplicar();
};

#endif
