// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "auxiliar.h"
#include "material.h"
#include "textura.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D
{
   public:
      Material m;
      // función que dibuja el objeto en modo diferido (usando VBOs)
      void setMaterial(Material mat);

      void draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled, bool LightsEnabled) ;
      std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
      std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo

      std::vector<Tupla4f> c;
      std::vector<Tupla3f> nv;


      std::vector<Tupla3f> c_s ; // Array de colores visualizacion solidos
      std::vector<Tupla3f> c_l ; // Array de colores visualizacion lineas
      std::vector<Tupla3f> c_p ; // Array de colores visualizacion puntos


      std::vector<Tupla2f> ct; // Array de coordenadas de texturas

      Textura *textura=nullptr;

      GLuint id_vbo_ver = 0;
      GLuint id_vbo_tri = 0; 

      GLuint id_vbo_c_l = 0;
      GLuint id_vbo_c_p = 0;
      GLuint id_vbo_c_s = 0;

      GLuint id_vbo_n_ver = 0;

      GLuint id_vbo_ct = 0;

      void calcularNormales();
      GLuint CrearVBO( GLuint tipo_vbo, GLuint tam, GLvoid * puntero_ram);
} ;


#endif
