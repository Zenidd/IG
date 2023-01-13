#include "objply.h"
#include "ply_reader.h"
 

// *****************************************************************************
//
// Clase ObjPLY (práctica 2)
//
// *****************************************************************************

ObjPLY::ObjPLY( const std::string & nombre_archivo)
{
   // leer la lista de caras y vértices
   ply::read( nombre_archivo, this->v, this->f );
   createColours(v.size(), {0.7,0.69,0.05}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0});
}

void ObjPLY::createColours(int size, Tupla3f color_s, Tupla3f color_l, Tupla3f color_p)
{
   c_s.resize(size);
   c_l.resize(size);
   c_p.resize(size);


   for( unsigned i = 0 ; i < size ; i++ ) c_s[i] = color_s ;
   for( unsigned i = 0 ; i < size ; i++ ) c_l[i] = color_l ;
   for( unsigned i = 0 ; i < size ; i++ ) c_p[i] = color_p ;
}


