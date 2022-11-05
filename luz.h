// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: LUZ.h
// -- declaraciones de clase LUZ (mallas indexadas) y derivados
//
// #############################################################################

#ifndef LUZ_H_INCLUDED
#define LUZ_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Luz
{
   public:
      void activar() ;
      GLenum id;
      Tupla4f posicion; // w == 0 direccional, w =! 0 posicional
      Tupla4f colorAmbiente;
      Tupla4f colorDifuso;
      Tupla4f colorEspecular;
} ;


#endif
