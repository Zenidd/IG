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
   createColours(v.size(), {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f});
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> vector_perfil, int num_instancias) {
   crearMalla(vector_perfil, num_instancias); 
   createColours(v.size(), {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f});
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
   float angulo;
   // variables de textura
   bool text_activa = false;
   float d, s, t;
   std::vector<float> dist;
   int M = perfil_original.size();
   int N = num_instancias;
   Tupla3f aux;
   if(perfil_original.front()[Y] > perfil_original.back()[Y]){
      std::cout << "Detectado perfil descendente\n";
      std::vector<Tupla3f> aux;
      for(int i=0; i<M; i++){
         aux.push_back(perfil_original.back());
         perfil_original.pop_back();
      }
      perfil_original = aux;
      std::cout << "El perfil es ahora ascedente\n";
   }

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
   M = perfil_original.size();

   if( Malla3D::textura != nullptr){
      // std::cout << "\ntextura activa\n";
      dist.push_back(0);   // d0 = 0
      text_activa = true;
      N++;   // instancia extra necesaria para las coord. de textura 
   }

   // Vector de vertices
   float angle = 0;
   for(unsigned int i = 0; i < N; i++){ //N
      for(unsigned int j = 0; j < perfil_original.size(); j++){ //M
         angle = 2*M_PI*i/N;
         if(i<num_instancias){
            v.push_back({
                        cos(angle)*perfil_original[j][X] + sin(angle)*perfil_original[j][Z],
                        perfil_original[j][Y],
                        cos(angle)*perfil_original[j][Z] - sin(angle)*perfil_original[j][X]
                     
            });
         }
         else{
            v.push_back(v[j]); // instancia extra similar al perfil original en coordenadas pero con diferente coord. textura
         }
         if (i==0 && text_activa && j>0) {
            d = (v[j]-v[j-1]).lengthSq(); // modulo ( v[1]-v[0] )
            d += dist[j-1];               // d1 = 0 + modulo(...)
            dist.push_back(d);   // dj+1
         }    

      }
      if (text_activa) {
         // 's' igual para todos los vertices de cada instancia
         // 't' unica para cada vertice de cada instancia
         s = (float)i/(float)num_instancias;
         for(int j = 0; j < M; j++){
            t = dist[j] / d;
            ct.push_back({ s , t });
            //if(i>=num_instancias-1 || i==0){
            //   std::cout << ct[m*i+j] << "\t--> v[" << m*i+j << "]\n";
            //}
            //std::cout << "t = " << t << "\n";
         }
         //std::cout << "s =" << s << "\n";
      }
   }


   // Vector de caras
   int a = 0,
       b = 0;
   for(unsigned int i = 0; i < num_instancias; i++) //N
      for(unsigned int j = 0; j < perfil_original.size()-1; j++){ //M
         a = perfil_original.size()*i+j;
         b = perfil_original.size()*((i+1) % N ) + j; 
         f.push_back({a, b, b+1});
         f.push_back({a, b+1, a+1});
      }
   int v_tam = v.size();
   // std::cout << "Tam vector v " << v.size() << std::endl;
   // Añadir tapas
   // N = N, perfil_original.size() = M

   if (polo_s){
      v.push_back(v_polo_s);
      if(text_activa) ct.push_back({0,0});
      int iPN = v.size()-1;
      for(unsigned int i = 0; i < num_instancias; i++){ //N
         f.push_back({M*((i+1)%N), M * i  , iPN});
      }
   }
   if (polo_n){
      v.push_back(v_polo_n);
      if(text_activa) ct.push_back({1,1});
      int iPS = v.size()-1;
      for(unsigned int i = 0; i < num_instancias; i++){ //N
         float a = M *(i+1)-1;
         float b = M*((i+1)%N)+M-1;
         float c = iPS;
         f.push_back({ a, b, c});
         // std::cout << "{" << a << "," << b << "," << c << "}" << std::endl;
      }
	}
}

void ObjRevolucion::createColours(int size, Tupla3f color_s, Tupla3f color_l, Tupla3f color_p)
{
   c_s.resize(size);
   c_l.resize(size);
   c_p.resize(size);


   for( unsigned i = 0 ; i < size ; i++ ) c_s[i] = color_s ;
   for( unsigned i = 0 ; i < size ; i++ ) c_l[i] = color_l ;
   for( unsigned i = 0 ; i < size ; i++ ) c_p[i] = color_p ;
}


void ObjRevolucion::calcularCoordTextura()
{

}