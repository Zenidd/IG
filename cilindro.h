// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"
#include "malla.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************

class Cilindro : public ObjRevolucion {
   public:
      Cilindro( const int num_vert_perfil ,
      const int num_instancias_perf ,
      const float altura , const float radio );
      void createVertex(int num_vert_perfil, float radio, float altura );
   private:
      std::vector<Tupla3f> v_inicial;
};




#endif
