// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: ring.h

//
// #############################################################################

#ifndef COLUMN_RING_H_INCLUDED
#define COLUMN_RING_H_INCLUDED

#include "auxiliar.h"
#include "anillo.h"
#include "esfera.h"
#include "column_sphere.h"


class ColumnRing : public Malla3D
{
   private:
      bool ccw_rotation = true;
      int rotation_degrees; 
      Anillo * anillo = nullptr;
      ColumnSphere * columnsphere = nullptr;
   public:
      ColumnRing(unsigned int initial_rotation = 0);
      ~ColumnRing();
      void change_rotation(int degrees, int satelital_degrees);
      void draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled, bool LightsEnabled);
      void set_rotation_sense(bool ccw_rotation_sense);
} ;

#endif
