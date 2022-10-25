#include "auxiliar.h"
#include "malla.h"
#include "cono.h"
#include "objrevolucion.h"

Cono::Cono( const int num_vert_perfil, const int num_instancias_perf, const float altura , const float radio )
{   cono_vertex(num_vert_perfil, radio, altura );
   crearMalla(v_perfil, num_vert_perfil); 
   createColours(v.size());
}

void Cono::cono_vertex(const int num_vert_perfil, const float radio, const float altura )
{
   v_perfil.resize(num_vert_perfil);
   for (unsigned int i = 0; i<num_vert_perfil; i++ )
      v_perfil[num_vert_perfil-i] = { (radio*(float)i)/num_vert_perfil, altura - (altura*(float)i)/(num_vert_perfil), 0.0f};
   v_perfil[0]= {radio, 0.0f, 0.0f};
   v_perfil.insert(v_perfil.begin(), {0.0f, 0.0f, 0.0f});
   v_perfil.push_back({0.0f, altura, 0.0f});
   // for (unsigned int i = 0; i<v_perfil.size(); i++ )
   //    std::cout << "{" <<v_perfil[i][X] << "," << v_perfil[i][Y] << "," << v_perfil[i][Z] << "}" << std::endl;
   // std::cout << "Size of Cono vertex is " << v_perfil.size() << std::endl;
}


