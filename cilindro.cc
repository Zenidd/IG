#include "auxiliar.h"
#include "malla.h"
#include "cilindro.h"
#include "objrevolucion.h"

Cilindro::Cilindro( const int num_vert_perfil, const int num_instancias_perf, const float altura , const float radio )
{
   // inicializar la tabla de vértices
   createVertex(num_vert_perfil, radio, altura );
   ObjRevolucion(v_inicial, num_instancias_perf);
   std::cout << "Este es mi size final" << v.size() << std::endl;
}

void Cilindro::createVertex(const int num_vert_perfil, const float radio, const float altura )
{
   v_inicial.resize(num_vert_perfil);
   v_inicial[0] = {0.0f, altura, 0.0f};
   for (unsigned int i = 1; i<num_vert_perfil-1; i++ )
      v_inicial[i] = { radio, altura - i*altura/num_vert_perfil, 0.0f};
   v_inicial[num_vert_perfil-1] = {0.0f, 0.0f, 0.0f};
   // for (int i = 0; i < num_vert_perfil; i++)
   //    std::cout << v_inicial[i][X] << "," << v_inicial[i][Y] << "," << v_inicial[i][Z] << std::endl;
}


