// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: LUZ.h
// -- declaraciones de clase LUZ (mallas indexadas) y derivados
//
// #############################################################################

#ifndef LUZDIRECCIONAL_H_INCLUDED
#define LUZDIRECCIONAL_H_INCLUDED

#include "auxiliar.h"
#include "luz.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class LuzDireccional : public Luz
{
   protected:
      float alpha;
      float beta;
   public:
      // inicializar la fuente de luz
      LuzDireccional (const Tupla2f orientacion, GLenum idLuzOpenGL, Tupla4f colorA, Tupla4f colorE, Tupla4f colorD ) ;
      // Cambiar ángulo:
      void variarAnguloAlpha ( float incremento ) ;
      void variarAnguloBeta ( float incremento ) ;
      void cambiarAngulo();
};

#endif
