// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: material.h
// -- declaraciones de clase material
//
// #############################################################################

#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "auxiliar.h"
#include "material.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************


class Material {
   private:
      const Tupla4f amb_dif_defecto = {1.0, 0.5, 0.8, 1.0};
      const Tupla4f esp_defecto = {1.0,0.3,0.3,1.0};
      const Tupla4f dif_defecto = {1.0,0.0,0.0,1.0};
      const float brillo_defecto = 20.0f;
      // const Tupla4f amb_dif_defecto = {0.1, 0.5, 0.8, 1.0};
      // const Tupla4f esp_defecto = {0.3,0.3,0.3,1.0};
      // const Tupla4f dif_defecto = {0.0,0.0,0.0,1.0};
      // const float brillo_defecto = 20.0f;
      Tupla4f ambiente;
      Tupla4f difuso;
      Tupla4f especular;
      GLfloat brillo;
   public:
      Material ();
      Material (const Material &m);
      Material &operator=(const Material &m);
      Material(Tupla4f mdifuso, Tupla4f mespecular, Tupla4f mambiente ,float mbrillo );
      void aplicar();
};

#endif
