#include "auxiliar.h"
#include "malla.h"
#include "cuadro.h"

   //   7-------6
   //  /|      /|
   // 3-+-----2 | 
   // | |     | |   y
   // | 4-----+-5   | z
   // |/      |/    |/
   // 0-------1     +--x

Cuadro::Cuadro(float lado)
{
   // inicializar la tabla de vértices
   createVertex(lado);
   createTriangles();
   createColours();
   textura = new Textura("./piramides.jpeg");
   createTexCoordinates();
}

void Cuadro::createVertex(float lado)
{
   v.resize(4);
   //Centrado en el origen
   v[0] = {-lado, 0, 0};
   v[1] = {lado, 0, 0};
   v[2] = {lado, lado, 0};
   v[3] = {-lado, lado, 0};
}

void Cuadro::createTexCoordinates()
{
   ct.resize(4);
   //Centrado en el origen
   // (0, 0)    (1, 0)
   // 3-------2  
   // |       |    
   // |       | 
   // |       |   
   // 0-------1   
   // (0, 1)  (1, 1)
   // ct[0] = {0.0, 1.0};
   // ct[1] = {1.0, 1.0};
   // ct[2] = {1.0, 0.0};
   // ct[3] = {0.0, 0.0};

   ct[0] = {0.0, 0.0};
   ct[1] = {1.0, 0.0};
   ct[2] = {1.0, 1.0};
   ct[3] = {0.0, 1.0};
}

void Cuadro::createTriangles()
{
   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   f.resize(2);

   f[0] = {2,0,1};
   f[1] = {0,2,3};
}


void Cuadro::createColours()
{
   unsigned int colours_number = 4;
   c_s.resize(colours_number);
   c_l.resize(colours_number);
   c_p.resize(colours_number);

   float R = 0.0f, G = 0.0f, B = 0.0f;

   for( unsigned i = 0 ; i < colours_number ; i++ ) c_s[i] = {1, G, B} ;
   for( unsigned i = 0 ; i < colours_number ; i++ ) c_l[i] = {R, 1, B} ;
   for( unsigned i = 0 ; i < colours_number ; i++ ) c_p[i] = {R, G, 1} ;
}

