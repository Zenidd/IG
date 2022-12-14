// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef COLUMN_H_INCLUDED
#define COLUMN_H_INCLUDED

#include "auxiliar.h"
#include "column_pilar.h"
// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Column
{
   public:
      Column();
      void draw();
   private:
      ColumnPilar * columnpilar = nullptr;
      unsigned int rotation_ring     = 0;
      unsigned int rotation_sphere   = 0;
      unsigned int rotation_satelite = 0;
      enum {UP, DOWN} direction;
} ;

#endif
