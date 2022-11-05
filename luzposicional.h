// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: LUZ.h
// -- declaraciones de clase LUZ (mallas indexadas) y derivados
//
// #############################################################################

#ifndef LUZPOSICIONAL_H_INCLUDED
#define LUZPOSICIONAL_H_INCLUDED

#include "auxiliar.h"
#include "luz.h"
// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class LuzPosicional : public Luz {
   public:
      LuzPosicional ( const Tupla3f pos, GLenum idLuzOpenGL, Tupla4f colorA, Tupla4f colorE, Tupla4f colorD  ) ;
};

#endif
