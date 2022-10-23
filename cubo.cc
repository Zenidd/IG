#include "auxiliar.h"
#include "malla.h"
#include "cubo.h"

   //   7-------6
   //  /|      /|
   // 3-+-----2 | 
   // | |     | |   y
   // | 4-----+-5   | z
   // |/      |/    |/
   // 0-------1     +--x

Cubo::Cubo(float lado)
{
   // inicializar la tabla de vértices
   createVertex(lado);
   createTriangles();
   createColours();
}

void Cubo::createVertex(float lado)
{
   v.resize(8);
   //Centrado en el origen
   v[0] = {-lado/2, 0, lado/2};
   v[1] = {lado/2, 0, lado/2};
   v[2] = {lado/2, lado, lado/2};
   v[3] = {-lado/2, lado, lado/2};

   v[4] = {-lado/2, 0, -lado/2};
   v[5] = {lado/2, 0, -lado/2};
   v[6] = {lado/2, lado, -lado/2};
   v[7] = {-lado/2, lado, -lado/2};
}

void Cubo::createTriangles()
{
   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   f.resize(12);

   f[0] = {2,0,1};
   f[1] = {0,2,3};

   f[2] = {6,1,5};
   f[3] = {1,6,2};

   f[4] = {7,5,4};
   f[5] = {5,7,6}; 

   f[6] = {3,4,0};
   f[7] = {4,3,7};  

   f[8] = {6,3,2};
   f[9] = {3,6,7};

   f[10] = {1,4,5};
   f[11] = {4,1,0};
}





void Cubo::createColours()
{
   c_s.resize(8);
   c_l.resize(8);
   c_p.resize(8);

   float R = 0.0f, G = 0.0f, B = 0.0f;

   for( unsigned i = 0 ; i < 8 ; i++ ) c_s[i] = {1, G, B} ;
   for( unsigned i = 0 ; i < 8 ; i++ ) c_l[i] = {R, 1, B} ;
   for( unsigned i = 0 ; i < 8 ; i++ ) c_p[i] = {R, G, 1} ;
}

