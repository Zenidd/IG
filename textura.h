// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: material.h
// -- declaraciones de clase material
//
// #############################################################################

#ifndef TEXTURA_H_INCLUDED
#define TEXTURA_H_INCLUDED

#include "auxiliar.h"
#include "textura.h"
#include "jpg_imagen.hpp"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************


class Textura {
   private:
      bool nuevo=true;
   public:
      Textura (std::string archivo);
      void activar();
      GLuint idTex = 0;
      jpg::Imagen * pimg = NULL ;
      std::vector<unsigned char> data;
      int width = 0;
      int height = 0;
      unsigned char * texels=nullptr;
};

#endif
