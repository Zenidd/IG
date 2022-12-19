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
      int rotation_degrees = 0;
      ColumnRing * columnring = nullptr;
      Cilindro * cilindro = nullptr;
   public:
      ColumnPilar(unsigned int initial_rotation = 0);
      void draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled, bool LightsEnabled);
      void change_rotation(unsigned int ring_degrees, unsigned int sphere_degrees);
      void set_rotation_sense(bool ccw_rotation);
      void ring_movement(unsigned int units);
} ;

#endif
