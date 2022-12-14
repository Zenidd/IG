// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef ANILLO_H_INCLUDED
#define ANILLO_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"
#include "malla.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************

class Anillo : public ObjRevolucion {
   public:
      Anillo( const int num_vert_perfil ,
      const int num_instancias_perf ,
      const float altura , const float radio );
      void anillo_vertex(int num_vert_perfil, float radio, float altura );
};




#endif
