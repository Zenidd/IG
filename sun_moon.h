// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef SUN_MOON_H_INCLUDED
#define SUN_MOON_H_INCLUDED

#include "auxiliar.h"
#include "esfera.h"
#include "luz.h"
#include "luzposicional.h"
// #include "tuplasg.h"
// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class SunMoon
{
   public:
      SunMoon();
      void draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled, bool LightsEnabled);
      void change_rotation(float units);
   private:

      LuzPosicional * luzposicionalsol = nullptr;
      LuzPosicional * luzposicionalmoon = nullptr;
      Esfera * sun = nullptr;
      Esfera * moon = nullptr;
      float rotation     = 0;
} ;

#endif
