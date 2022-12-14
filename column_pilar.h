// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: ring.h

//
// #############################################################################

#ifndef COLUMN_PILAR_H_INCLUDED
#define COLUMN_PILAR_H_INCLUDED

#include "auxiliar.h"
#include "cilindro.h"
#include "column_ring.h"


class ColumnPilar : public Malla3D
{
   private:

      unsigned int columnring_current_height = 70;
      unsigned int columnring_max_height = 4;
      unsigned int columnring_min_height = 4;
      unsigned int rotation_degrees = 0;
      ColumnRing * columnring = nullptr;
      Cilindro * cilindro = nullptr;
   public:
      ColumnPilar(unsigned int initial_rotation = 0);
      void draw();
      void change_rotation(unsigned int degrees = 1, unsigned int ring_degrees = 1, unsigned int sphere_degrees = 1);
      void change_height(unsigned int height);
} ;

#endif
