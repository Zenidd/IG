#include "auxiliar.h"
#include "malla.h"
#include "cilindro.h"
#include "objrevolucion.h"

Cilindro::Cilindro( const int num_vert_perfil, const int num_instancias_perf, const float altura , const float radio )
{
   cilindro_vertex(num_vert_perfil, radio, altura );
   crearMalla(v_perfil, num_instancias_perf); 
   createColours(v.size(), {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f});
}

void Cilindro::cilindro_vertex(const int num_vert_perfil, const float radio, const float altura )
{
   v_perfil.resize(num_vert_perfil);
   for (unsigned int i = 0; i<num_vert_perfil; i++ )
      v_perfil[i] = { radio, (float)i * altura/(num_vert_perfil), 0.0f};
   v_perfil.insert(v_perfil.begin(), {0.0f, 0.0f, 0.0f});
   v_perfil.push_back({radio, altura, 0.0f});
   v_perfil.push_back({0.0f, altura, 0.0f});
   // for (unsigned int i = 0; i<v_perfil.size(); i++ )
   //    std::cout << "{" <<v_perfil[i][X] << "," << v_perfil[i][Y] << "," << v_perfil[i][Z] << "}" << std::endl;
}


