// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: cono.h

//
// #############################################################################

#ifndef CONO_H_INCLUDED
#define CONO_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"
#include "malla.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************

class Cono : public ObjRevolucion {
   public:
      Cono( const int num_vert_perfil ,
      const int num_instancias_perf ,
      const float altura , const float radio );
      void cono_vertex(int num_vert_perfil, float radio, float altura );
};




#endif
