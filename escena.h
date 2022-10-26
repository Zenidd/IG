#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "objply.h"
#include "objrevolucion.h"
#include "piramidepentagonal.h"
#include "cilindro.h"
#include "cono.h"
#include "esfera.h"

typedef enum {NADA, SELOBJETO, SELVISUALIZACION} menu;

class Escena
{

   private:
 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
       // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;


   GLfloat Scale;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection( const float ratio_xy );
	void change_observer();
    

   void clear_window();

   menu modoMenu=NADA;
   // Objetos de la escena
   Ejes ejes;
   Cubo * cubo = nullptr ;
   PiramidePentagonal * piramide= nullptr ;
   ObjPLY * objetoply= nullptr ;
   ObjRevolucion * objrevolucion = nullptr;
   ObjRevolucion * objrevolucion1 = nullptr;
   ObjRevolucion * objrevolucion2 = nullptr;
   Cilindro * cilindro = nullptr;
   Cilindro * cilindro1 = nullptr;
   Cono * cono = nullptr;
   Cono * cono1 = nullptr;
   Cono * cono2 = nullptr;
   Esfera * esfera = nullptr;
   Esfera * esfera1 = nullptr;
   Esfera * esfera2 = nullptr;

   bool CubeEnabled = false, PyramidEnabled = false, OplyEnabled=false;
   bool PointsEnabled = false, LinesEnabled = false, SolidEnabled = false;
   
   public:
    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );

};
#endif
