#include "auxiliar.h"
#include "objrevolucion.h"
#include "ply_reader.h"




// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias) {
   ply::read_vertices( archivo, v_perfil);
   crearMalla(v_perfil, num_instancias);
   createColours(v.size());
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> vector_perfil, int num_instancias) {
   crearMalla(vector_perfil, num_instancias); 
   createColours(this->v.size());
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
   //Orden descendente 
   //polo_sur
   if (perfil_original.front()[X] == 0.0f && perfil_original.front()[Z] == 0.0f ) {
      v_polo_s = perfil_original[0];
      perfil_original.erase(perfil_original.begin());
      polo_s = true;
   }
   //polo_norte
   if (perfil_original[perfil_original.size()-1][X] == 0.0f && perfil_original[perfil_original.size()-1][Z] == 0.0f ) {
      v_polo_n = perfil_original[perfil_original.size()-1];
      perfil_original.pop_back();
      polo_n = true;
   }
   int M = perfil_original.size();
   int N = num_instancias;
   // Vector de vertices
   float angle = 0;
   for(unsigned int i = 0; i < N; i++) //N
      for(unsigned int j = 0; j < perfil_original.size(); j++){ //M
         angle = 2*M_PI*i/N;
         v.push_back({
                     cos(angle)*perfil_original[j][X] + sin(angle)*perfil_original[j][Z],
                     perfil_original[j][Y],
                     cos(angle)*perfil_original[j][Z] - sin(angle)*perfil_original[j][X]
                  
         });
      }
   // Vector de caras
   int a = 0,
       b = 0;
   for(unsigned int i = 0; i < N; i++) //N
      for(unsigned int j = 0; j < perfil_original.size()-1; j++){ //M
         a = perfil_original.size()*i+j;
         b = perfil_original.size()*((i+1) % N ) + j; 
         f.push_back({a, b, b+1});
         f.push_back({a, b+1, a+1});
      }
   int v_tam = v.size();
   std::cout << "Tam vector v " << v.size() << std::endl;
   // Añadir tapas
   // N = N, perfil_original.size() = M

   if (polo_s){
      v.push_back(v_polo_s);
      int iPN = v.size()-1;
      for(unsigned int i = 0; i < N; i++){ //N
         f.push_back({M*((i+1)%N), M * i  , iPN});
      }
   }
   if (polo_n){
      v.push_back(v_polo_n);
      int iPS = v.size()-1;
      for(unsigned int i = 0; i < N; i++){ //N
         float a = M *(i+1)-1;
         float b = M*((i+1)%N)+M-1;
         float c = iPS;
         f.push_back({ a, b, c});
         // std::cout << "{" << a << "," << b << "," << c << "}" << std::endl;
      }
	}
}

void ObjRevolucion::createColours(int size)
{
   c_s.resize(size);
   c_l.resize(size);
   c_p.resize(size);

   float R = 0.0f, G = 0.0f, B = 0.0f;

   for( unsigned i = 0 ; i < size ; i++ ) c_s[i] = {1, G, B} ;
   for( unsigned i = 0 ; i < size ; i++ ) c_l[i] = {R, 1, B} ;
   for( unsigned i = 0 ; i < size ; i++ ) c_p[i] = {R, G, 1} ;
}