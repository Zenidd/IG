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


class ColumnSphere : public Malla3D
{
   private:
      unsigned int rotation_degrees = 0;
      Esfera * esfera = nullptr;
      Esfera * satelite = nullptr;
   public:
      ColumnSphere(unsigned int initial_rotation);
      void draw();
      void change_rotation(unsigned int degrees = 90);
} ;

#endif
