#include "objply.h"
#include "ply_reader.h"
 

// *****************************************************************************
//
// Clase ObjPLY (práctica 2)
//
// *****************************************************************************

ObjPLY::ObjPLY( const std::string & nombre_archivo )
{
   // leer la lista de caras y vértices
   ply::read( nombre_archivo, this->v, this->f );
   ObjPLY::createColours(this->v.size());
}

void ObjPLY::createColours(int size)
{
   c_s.resize(size);
   c_l.resize(size);
   c_p.resize(size);

   float R = 0.0f, G = 0.0f, B = 0.0f;

   for( unsigned i = 0 ; i < size ; i++ ) c_s[i] = {1, G, B} ;
   for( unsigned i = 0 ; i < size ; i++ ) c_l[i] = {R, 1, B} ;
   for( unsigned i = 0 ; i < size ; i++ ) c_p[i] = {R, G, 1} ;
}


