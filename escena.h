#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "luz.h"
#include "luzdireccional.h"
#include "luzposicional.h"
#include "cubo.h"
#include "objply.h"
#include "objrevolucion.h"
#include "piramidepentagonal.h"
#include "cilindro.h"
#include "cono.h"
#include "esfera.h"
#include "anillo.h"
#include "column.h"
#include "sun_moon.h"

typedef enum {NADA, SELOBJETO, SELVISUALIZACION, SELILUMINACION, ANIMACION, MANUAL} menu;
typedef enum {SATELITE, ESFERA, ANILLO, EMPTY} gradosLibertad;
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
  void disableLights();
    

   void clear_window();

   menu modoMenu = NADA;
   gradosLibertad gradoslibertad = EMPTY;
   // Luces de le escena
   LuzDireccional * luzdireccional = nullptr;
   LuzPosicional * luzposicional = nullptr;

   // Objetos de la escena
   Ejes ejes;
   Cubo * cubo = nullptr ;

   PiramidePentagonal * piramide= nullptr ;

   ObjPLY * objetoply= nullptr ;
   ObjPLY * mountainPLY= nullptr ;
   ObjPLY * desertPLY = nullptr ;


   ObjRevolucion * objrevolucion = nullptr;
   ObjRevolucion * objrevolucion1 = nullptr;
   ObjRevolucion * objrevolucion2 = nullptr;

   Cilindro * cilindro = nullptr;
   Cilindro * cilindro1 = nullptr;

   Cono * cono0 = nullptr;
   Cono * cono1 = nullptr;
   Cono * cono2 = nullptr;

   Esfera * esfera0 = nullptr;
   Esfera * esfera1 = nullptr;
   Esfera * esfera2 = nullptr;

   Anillo * anillo = nullptr;

  Material *blanco_d = nullptr;
  Material *negro_e = nullptr;

  Column * column = nullptr;
  SunMoon * sunmoon = nullptr;

  bool CubeEnabled = false, PyramidEnabled = false, OplyEnabled=false;
  bool PointsEnabled = false, LinesEnabled = false, SolidEnabled = false;

  bool alpha_l = false, beta_l = false;
  
  bool LightsEnabled = false;

  bool gl_light0_enabled = true;
  bool gl_light1_enabled = true;
  bool gl_light2_enabled = false;
  bool gl_light3_enabled = true;
  bool gl_light4_enabled = true;
  bool gl_light5_enabled = false;
  bool gl_light6_enabled = false;
  bool gl_light7_enabled = false;
  
  float var_a = 0.0f, var_b=0.0f;

  bool animation_enabled = false;
  bool degrees_increment = true;
  unsigned int number_of_degrees = 1;
  unsigned int animation_speed = 5;
  float sun_moon_number_of_degrees = 0.1;

   public:
    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );
  void animarModeloJerarquico();

};
#endif