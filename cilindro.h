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
      const float altura , const float radio, 
      std::string texture_name = "none" );
      void cilindro_vertex(int num_vert_perfil, float radio, float altura );
};




#endif
