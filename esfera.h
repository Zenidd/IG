// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: ESFERA.h

//
// #############################################################################

#ifndef ESFERA_H_INCLUDED
#define ESFERA_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"
#include "malla.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************

class Esfera : public ObjRevolucion {
   public:
      Esfera( const int num_vert_perfil, const int num_instancias_perf, const float radio );
      void esfera_vertex(int num_vert_perfil, float radio);
};


#endif
