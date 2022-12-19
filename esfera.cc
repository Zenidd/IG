#include "auxiliar.h"
#include "malla.h"
#include "esfera.h"
#include "objrevolucion.h"

Esfera::Esfera( const int num_vert_perfil, const int num_instancias_perf, const float radio )
{   esfera_vertex(num_vert_perfil, radio);
   crearMalla(v_perfil, num_instancias_perf); 
   createColours(v.size(), {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f} );
}

void Esfera::esfera_vertex(const int num_vert_perfil, const float radio)
{
   v_perfil.resize(num_vert_perfil);
   float aux;
   for (unsigned int i = 0; i<num_vert_perfil; i++ ){
      aux = (float)(i*M_PI)/num_vert_perfil;
      v_perfil[i] = { (float)sin(aux)*radio, (float)-cos(aux)*radio, 0.0f};
   }
   v_perfil.push_back({0.0f, radio, 0.0f});
   // for (unsigned int i = 0; i<v_perfil.size(); i++ )
   //    std::cout << "{" <<v_perfil[i][X] << "," << v_perfil[i][Y] << "," << v_perfil[i][Z] << "}" << std::endl;
   // std::cout << "Size of Cono vertex is " << v_perfil.size() << std::endl;
}


