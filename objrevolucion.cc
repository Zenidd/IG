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
   replicas(v_perfil, num_instancias);
   crearMalla(v_perfil, num_instancias);
   createColours(v.size());
   std::cout << "Tam vector perfil_original" <<  v_perfil.size() << std::endl;
   std::cout << "Tam vector vertices" << v.size() << std::endl;
   std::cout << "Tam vector caras" << f.size() << std::endl;
   
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias) {
   // //Orden descendente
   // polos(archivo);
   // if (polo_s) {
   //    v_polo_s = archivo[0];
   //    archivo.erase(archivo.begin());
   // }
   // if (polo_n) {
   //    v_polo_n = archivo[archivo.size()-1];
   //    archivo.pop_back();
   //    // std::cout << archivo[archivo.size()-1]<< std::endl;
   // }
   replicas(archivo, num_instancias);
   crearMalla(archivo, num_instancias); 
   
   // if (polo_s){
   //    archivo.push_back(v_polo_s);
   //    ObjRevolucion::crearTapa(archivo, num_instancias, 's');
   // }
   // if (polo_n){
   //    if (!polo_s) archivo.push_back({0.0f, 0.0f, 0.0f});
   //    archivo.push_back(v_polo_n);
   //    ObjRevolucion::crearTapa(archivo, num_instancias,'n');
   // }
   createColours(v.size());
   std::cout << "Tam vector perfil_original" <<  archivo.size() << std::endl;
   std::cout << "Tam vector vertices" << v.size() << std::endl;
   std::cout << "Tam vector caras" << f.size() << std::endl;
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
   float a = 0.0f,
         b = 0.0f;
   for(unsigned int i = 0; i < num_instancias; i++) //N
      for(unsigned int j = 0; j < perfil_original.size()-1; j++){ //M
         a = perfil_original.size()*i+j;
         b = perfil_original.size()*((i+1) % num_instancias ) + j; 
         f.push_back({a, b, b+1});
         f.push_back({a, b+1, a+1});
      }
}

void ObjRevolucion::replicas(std::vector<Tupla3f> perfil_original,  int num_instancias) {
   float angle = 0;
   for(unsigned int i = 0; i < num_instancias; i++) //N
      for(unsigned int j = 0; j < perfil_original.size(); j++){ //M
         angle = 2*M_PI*i/num_instancias;
         v.push_back({perfil_original[j][Z]*(sin(angle)) + perfil_original[j][X]*(cos(angle)),
                           perfil_original[j][Y],
                           perfil_original[j][Z]*(cos(angle)) - perfil_original[j][X]*(sin(angle))
         });
      }
}


void ObjRevolucion::crearTapa(std::vector<Tupla3f> perfil_original, int num_instancias, char polo) {
   int a = 0,
       b = 0;
      switch (polo)
   {
	   case 's':
      for(unsigned int i = 0; i < num_instancias; i++){ //N
         a = i * perfil_original.size();
         b = (i + 1) * perfil_original.size();
         f.push_back({a, b, num_instancias});
      }
         break;
	   case 'n':
      for(unsigned int i = 0; i < num_instancias - 1; i++){ //N
         a = (i + 1) * perfil_original.size() - 1;
         b = (i + 2) * perfil_original.size() - 1;
         f.push_back({num_instancias+1, b, a});
      }
         break;
	}

}

void ObjRevolucion::polos(std::vector<Tupla3f> archivo) {
   if (archivo.front()[X] == 0.0f && archivo.front()[Z] == 0.0f ) {
      polo_s = true;
   }
   if (archivo[archivo.size()-1][X] == 0.0f && archivo[archivo.size()-1][Z] == 0.0f ) {
      polo_n = true;
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