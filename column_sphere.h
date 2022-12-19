// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: ring.h

//
// #############################################################################

#ifndef COLUMN_SPHERE_H_INCLUDED
#define COLUMN_SPHERE_H_INCLUDED

#include "auxiliar.h"
#include "esfera.h"
#include "material.h"


class ColumnSphere : public Malla3D
{
   private:
      bool ccw_rotation = true;
      int rotation_degrees = 0;
      Esfera * esfera = nullptr;
      Esfera * satelite = nullptr;
      Material defecto;

   public:
      ColumnSphere(unsigned int initial_rotation);
      void draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled, bool LightsEnabled);
      void change_rotation(int degrees);
      void set_rotation_sense(bool ccw_rotation_sense);
} ;

#endif
