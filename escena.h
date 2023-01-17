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
#include "cuadro.h"
#include "camera.h"
typedef enum {NADA, SELOBJETO, SELVISUALIZACION, SELILUMINACION, ANIMACION, MANUAL, CAMARA} menu;
typedef enum {SATELITE, ESFERA, ANILLO, EMPTY} gradosLibertad;
typedef enum {MOVIENDO_CAMARA_FIRSTPERSON, NO_MOVIENDO_CAMARA_FIRSTPERSON, ZOOM_IN, ZOOM_OUT} estadoRaton;
// typedef enum {IZQUIERDO, DERECHO} botonRaton;

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
   estadoRaton estadoraton = NO_MOVIENDO_CAMARA_FIRSTPERSON;

   // Luces de le escena
   LuzDireccional * luzdireccional = nullptr;
   LuzPosicional * luzposicional = nullptr;

   // Camaras de la escena
   std::vector<Camara *> camaras;
   int camaraActiva = 0;
   int xant = 0, yant = 0;
   Camara * camara0 = nullptr;
   Camara * camara1 = nullptr;
   Camara * camara2 = nullptr;

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
  
   Esfera * bola_mundo = nullptr;

   Anillo * anillo = nullptr;

  Material *blanco_d = nullptr;
  Material *negro_e = nullptr;

  Column * column = nullptr;
  SunMoon * sunmoon = nullptr;

  Cuadro * cuadro = nullptr;

  bool CubeEnabled = false, PyramidEnabled = false, OplyEnabled=false;
  bool PointsEnabled = false, LinesEnabled = false, SolidEnabled = false;

  bool alpha_l = false, beta_l = false;
  
  bool LightsEnabled = true;

  bool gl_light0_enabled = true;
  bool gl_light1_enabled = false;
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
    void clickRaton( int boton , int estado , int x, int y );
    void ratonMovido( int x, int y );
    void custom_change_observer ();
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