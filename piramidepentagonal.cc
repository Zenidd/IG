#include "auxiliar.h"
#include "malla.h"
#include "piramidepentagonal.h"
#include "math.h"
PiramidePentagonal::PiramidePentagonal(float h, float r)
{
   createVertex(h, r);
   // inicializar la tabla de vértices
   // inicializar la tabla de caras o triángulos:
   createTriangles();
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   // inicializar la/s tabla/s de colores
   createColours();
}

void PiramidePentagonal::createVertex(float h, float r)
{
   float PI = 3.14159265358979323846;
   v.resize(7);
   v[0] = {0.0f, 0.0f, 0.0f};
     
   v[1] = {r, 0.0f, 0.0f};
   v[2] = {r*cos(72*(PI/180)), 0.0f, r*sin(72*(PI/180))};
   v[3] = {r*cos(72*2*(PI/180)), 0.0f, r*sin(72*2*(PI/180))};
   v[4] = {r*cos(72*3*(PI/180)), 0.0f, r*sin(72*3*(PI/180))};
   v[5] = {r*cos(72*4*(PI/180)), 0.0f, r*sin(72*4*(PI/180))};

   v[6] = {0.0f, h, 0.0f};
}


void PiramidePentagonal::createTriangles()
{
   f.resize(10);

   f[0] = {0,2,1};
   f[1] = {0,3,2};
   f[2] = {0,4,3};
   f[3] = {0,5,4};
   f[4] = {0,1,5};

   f[5] = {1,2,6}; 
   f[6] = {2,3,6};
   f[7] = {3,4,6};  
   f[8] = {4,5,6};
   f[9] = {5,1,6};
}

void PiramidePentagonal::createColours()
{
   float R = 0.0f, G = 0.0f, B = 0.0f;
   c_s.resize(7);
   c_l.resize(7);
   c_p.resize(7);

   for( unsigned i = 0 ; i < 8 ; i++ ) c_s[i] = {1, G, B} ;
   for( unsigned i = 0 ; i < 8 ; i++ ) c_l[i] = {R, 1, B} ;
   for( unsigned i = 0 ; i < 8 ; i++ ) c_p[i] = {R, G, 1} ;
}