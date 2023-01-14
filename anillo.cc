#include "auxiliar.h"
#include "malla.h"
#include "anillo.h"
#include "objrevolucion.h"

Anillo::Anillo( const int num_vert_perfil, const int num_instancias_perf, const float altura , const float radio )
{
   textura = new Textura("./textures/ring.jpeg");
   anillo_vertex(num_vert_perfil, radio, altura );
   crearMalla(v_perfil, num_instancias_perf); 
   createColours(v.size(), {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f});
}

void Anillo::anillo_vertex(const int num_vert_perfil, const float radio, const float altura )
{
   v_perfil.resize(num_vert_perfil);
   for (unsigned int i = 0; i<num_vert_perfil; i++ )
      v_perfil[i] = { radio, (float)i * altura/(num_vert_perfil), 0.0f};
   v_perfil.push_back({radio, altura, 0.0f});

}


