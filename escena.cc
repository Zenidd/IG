
#include "auxiliar.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include <unistd.h>

#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....
#include "luz.h"

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{
   Front_plane       = 50.0;
   Back_plane        = 3000.0;
   Observer_distance = 8*Front_plane;
   Observer_angle_x  = 0.0 ;
   Observer_angle_y  = 0.0 ;
   Scale             = 1.0 ; 

   // EJES
   ejes.changeAxisSize( 5000 );

   // LUCES
   Tupla3f posicionLuz = Tupla3f(0.0f, -200.0f, 600.0f);
   Tupla4f ambiental(0.0, 0.0, 0.0, 0.0);
   Tupla4f difusa(1.0,1.0,1.0,1.0);
   Tupla4f especular(1.0,1.0,1.0,1.0);
   this->luzposicional = new LuzPosicional(posicionLuz, GL_LIGHT0, ambiental, especular, difusa);

   Tupla2f orientacion(0.0f, 0.0f);
   Tupla4f d_ambiental(0.0, 0.0, 0.0, 0.0);
   Tupla4f d_difusa(0.0, 0.0, 1.0, 1.0);
   Tupla4f d_especular(0.0, 0.0, 1.0, 0.5);
   this->luzdireccional = new LuzDireccional(orientacion, GL_LIGHT1, d_ambiental, d_especular, d_difusa);

   // COLORES MATERIALES
   Material defecto;

   Tupla4f m_ambiental(1.0, 1.0, 1.0, 1.0);
   Tupla4f m_difusa(1.0, 1.0, 1.0, 1.0);
   Tupla4f m_especular(0.0, 0.0, 0.0, 0.0);
   Material blanco_d(m_ambiental, m_especular, m_difusa ,64.0);

   m_ambiental       = {0.2, 0.2, 0.2, 1.0};
   m_difusa          = {0.2, 0.2, 0.2, 0.3};
   m_especular       = {1.0, 1, 1, 1.0};
   Material negro_e(m_ambiental, m_especular, m_difusa, 40.0);

   m_ambiental       = {0.38,0.39,0.35, 0.1};
   m_difusa          = {0.38,0.39,0.35,0.5};
   m_especular       = {0.38,0.39,0.35,1.0};
   Material egypt_m(m_ambiental, m_especular, m_difusa, 50.0);

   m_ambiental       = {0.7, 0.0, 0.0, 0.1};
   m_difusa          = {0.940, 0.0564, 0.0564, 0.5};
   m_especular       = {0.940, 0.0564, 0.0564, 1.0};
   Material sun0(m_ambiental, m_especular, m_difusa, 50.0);

   m_ambiental       = {0.0, 0.0, 0.0, 0.1};
   m_difusa          = {1.00, 0.785, 0.0800, 0.5};
   m_especular       = {1.00, 0.785, 0.0800, 1.0};
   Material sun1(m_ambiental, m_especular, m_difusa, 50.0);

   m_ambiental       = {0.00604, 0.00120, 0.0100, 1.0};
   m_difusa          = {0.00604, 0.00120, 0.0100, 1.0};
   m_especular       = {0.00604, 0.00120, 0.0100, 1.0};
   Material sun2(m_ambiental, m_especular, m_difusa, 50.0);

   m_ambiental       = {0.76,0.7,0.5, 1.0};
   m_difusa          = {0.66,0.6,0.4, 1.0};
   m_especular       = {0.66,0.6,0.4, 0.7};
   Material floor(m_ambiental, m_especular, m_difusa, 50.0);

   m_ambiental       = {0.76,0.7,0.5, 1.0};
   m_difusa          = {0.76,0.7,0.5, 1.0};
   m_especular       = {0.76,0.7,0.5, 1.0};
   Material sphinx(m_ambiental, m_especular, m_difusa, 50.0);


   m_ambiental       = {0.43,0.33,0.33, 1.0};
   m_difusa          = {0.43,0.33,0.33, 1.0};
   m_especular       = {0.43,0.33,0.33, 1.0};
   Material muro(m_ambiental, m_especular, m_difusa, 50.0);

   // OBJETOS
   falcon            = new ObjPLY("./plys/falcon.ply");
   gates             = new ObjPLY("./plys/big_gates.ply");
   big_gates         = new ObjPLY("./plys/door.ply");
   obelisk           = new ObjPLY("./plys/obelisk.ply");
   desertPLY         = new ObjPLY("./plys/desertfinal_decimated.ply");
   skeksil           = new ObjPLY("./plys/chambelan_decimated.ply");
   skektek           = new ObjPLY("./plys/cientifico_decimated.ply");

   esfera0           = new Esfera(30, 50, 20);
   esfera1           = new Esfera(30, 50, 20);
   esfera2           = new Esfera(30, 50, 20);

   cil_atrio         = new Cilindro(30, 10, 10, 10);

   cubo              = new Cubo(1);
   murallas          = new Cubo(1);
   sunmoon           = new SunMoon();
   column            = new Column();

   cono0             = new Cono(10, 4, 1, 1, "./textures/pyramid.jpeg");
   cono1             = new Cono(10, 4, 1, 1, "./textures/pyramid.jpeg");
   cono2             = new Cono(10, 4, 1, 1, "./textures/pyramid.jpeg");
   bola_mundo        = new Esfera(30, 50, 20, "./textures/world_texture.jpeg");
   cuadro            = new Cuadro(100);

   // MATERIALES
   this->esfera0->setMaterial(sun0);
   this->esfera1->setMaterial(sun1);
   this->esfera2->setMaterial(negro_e);


   this->cuadro->setMaterial(blanco_d);
   this->bola_mundo->setMaterial(blanco_d);

   this->falcon->setMaterial(floor);
   this->obelisk->setMaterial(egypt_m);

   this->gates->setMaterial(egypt_m);
   this->big_gates->setMaterial(egypt_m);

   // Personajes
   this->skeksil->setMaterial(blanco_d);
   this->skektek->setMaterial(blanco_d);

   this->desertPLY->setMaterial(floor);
   

   // Piramides
   this->cono0->setMaterial(egypt_m);
   this->cono1->setMaterial(egypt_m);
   this->cono2->setMaterial(egypt_m);

   this->cubo->setMaterial(negro_e);
   this->murallas->setMaterial(muro);

   // CAMARAS
   // CAMARA 0
   float aux_height        = Height/10;
   float aux_widht         = Width/10;
   float ratioxy           = float(aux_height)/float(aux_widht); // xy
   float ratioyx           = float(aux_widht)/float(aux_height); // yx

   Tupla3f eye             = Tupla3f(0.0f, 400.0f, 1350.0f);
   Tupla3f at              = Tupla3f(0.0f, 0.0f, 0.0f);
   Tupla3f up              = Tupla3f(0.0f, 1.0f, 0.0f);
   float UI_window_width   = 700;
   float UI_window_height  = 700;
   int camera_type         = 0;
   float camera_left       = -aux_height*ratioxy;
   float camera_right      = aux_height*ratioxy;
   float camera_bottom     = -aux_widht*ratioyx;
   float camera_top        = aux_widht*ratioyx;
   float camera_near       = 200;
   float camera_far        = 3000;
   camara0                 = new Camara(eye, at, up, camera_type, camera_left, camera_right,
                              camera_bottom, camera_top ,camera_near, camera_far);
   camaras.push_back(camara0);

   // CAMARA 1
   // eye = Tupla3f(0.0f, 300.0f, -1000.0f);
   eye                     = Tupla3f(0.0f, 50.0f, 800.0f);
   at                      = Tupla3f(0.0f, 130.0f, 0.0f);
   up                      = Tupla3f(0.0f, 1.0f, 0.0f);
   camera_type             = 0;
   camara1                 = new Camara(eye, at, up, camera_type, camera_left, camera_right,
                              camera_bottom, camera_top ,camera_near, camera_far);
   camaras.push_back(camara1);


   // CAMARA 2
   eye                     = Tupla3f(-400.0f, 800.0f, 900.0f);
   at                      = Tupla3f(80.0f, -120.0f, 100.0f);
   up                      = Tupla3f(0.0f, 1.0f, 0.0f);
   camera_type             = 1;
   camera_near             = 50;
   camera_far              = 5000;
   camara2                 = new Camara(eye, at, up, camera_type, camera_left, camera_right,
                              camera_bottom, camera_top ,camera_near, camera_far);
   camaras.push_back(camara2);

   // CAMARA 3
   eye                     = Tupla3f(150.0f, 200.0f, 300.0f);
   at                      = Tupla3f(0.0f, 0.0f, 600.0f);
   up                      = Tupla3f(0.0f, 1.0f, 0.0f);
   camera_type             = 1;
   camera_near             = 50;
   camera_far              = 5000;
   camara3                 = new Camara(eye, at, up, camera_type, camera_left, camera_right,
                              camera_bottom, camera_top ,camera_near, camera_far);
   camaras.push_back(camara3);

}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor(0.139, 0.193, 0.340, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer
	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );

	glViewport( 0, 0, UI_window_width, UI_window_height );

   // glEnable(GL_CULL_FACE);
   glEnable(GL_NORMALIZE); // Añadido para evitar que las normales varien con glScalef
   glShadeModel(GL_SMOOTH);
   // glShadeModel(GL_FLAT);
}


// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujar()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
   custom_change_observer();
   glPushMatrix();
      if (LightsEnabled) glDisable(GL_LIGHTING);
      ejes.draw();
      if (LightsEnabled) glEnable(GL_LIGHTING);
   glPopMatrix();
   glScalef(Scale,Scale,Scale);

   // LUCES
   glPushMatrix();
      luzdireccional->activar();
   glPopMatrix();

   glPushMatrix();
      luzposicional->activar();
   glPopMatrix();

   // SOL Y LUNA
   glPushMatrix ();
      sunmoon -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Interruptores Luces
   if(LightsEnabled) disableLights();

   // Modelo jerarquico
   glPushMatrix ();
      switch (gradoslibertad){
         case ANILLO:
            if (degrees_increment){
               column -> ring_movement(number_of_degrees);
            } 
            else {
               column -> ring_movement(-number_of_degrees);
            }
            number_of_degrees = 0;
            break;
         case ESFERA:
            if (degrees_increment){
               column -> change_rotation(0, number_of_degrees);
               column -> set_rotation_sense(true);
            } 
            else {
               column -> change_rotation(0, number_of_degrees);
               column -> set_rotation_sense(false);
            }
            number_of_degrees = 0;
            break;
         case SATELITE:
            if (degrees_increment){
               column -> change_rotation(number_of_degrees, 0);
               column -> set_rotation_sense(true);
            } 
            else {
               column -> change_rotation(number_of_degrees, 0);
               column -> set_rotation_sense(false);
            }
            number_of_degrees = 0;
            break;
         case EMPTY:
            break;
      }
      glTranslatef(0.0, 0.0, 540.0);
      glScalef(1,1,1);
      column -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   //Atrio modelo jerarquico 
   glPushMatrix ();
      glTranslatef(0.0, 0.0, 540.0);
      glScalef(5.0f, 1.0f, 5.0f);
      cil_atrio -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef(0.0, 2.0, 540.0);
      glScalef(2.5f, 1.0f, 2.5f);
      cil_atrio -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Gates 
   glPushMatrix ();
      glTranslatef(-120.0, 0.0, 750.0);
      glScalef(6, 6, 6);
      glRotatef(-90, 1,0,0);
      gates -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef(120.0, 0.0, 750.0);
      glScalef(6, 6, 6);
      glRotatef(-90, 1,0,0);
      gates -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef(-24.0, 32.0, 830.0);
      glScalef(3, 3, 3);
      big_gates -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Personajes
   glPushMatrix ();
      glTranslatef(-8, 10.0, 580.0f);
      glScalef(1.0f, 1.0f, 1.0f);
      glRotatef(-90, 1, 0, 0);
      skektek -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef(8, 10.0, 580.0f);
      glScalef(1.0f, 1.0f, 1.0f);
      glTranslatef(0, -10, 0);
      glRotatef(-90, 1, 0, 0);
      skeksil -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Cuadro piramides
   glPushMatrix ();
      glTranslatef(0, -150, 200);
      cuadro -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Bola mundo
   glPushMatrix ();
      glTranslatef(0, -250, 200);
      glScalef(3,3,3);
      bola_mundo -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Landscape
   glPushMatrix ();
      glRotatef(60, 0.0f, 1.0f, 0.0f);
      glTranslatef(1200.0f, -50.0f, -1200.0f);
      glScalef(0.8, 1, 0.8);
      desertPLY -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Estatuas
   glPushMatrix ();
      glTranslatef(-120, 10.0f, 320.0f);
      glRotatef(-90, 1, 0, 0);
      glScalef(2,2,2);
      falcon -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef(120.0f, 10.0f, 320.0f);
      glRotatef(-90, 1, 0, 0);
      glScalef(2,2,2);
      falcon -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   //Atrio
   glPushMatrix ();
      glTranslatef(-32.0f, 220.0f, -250.0f);
      glRotatef(90, 0, 1, 0);
      glScalef(32, 128, 2);
      cubo -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();
   glPushMatrix ();
      glTranslatef(32.0f, 220.0f, -250.0f);
      glRotatef(90, 0, 1, 0);
      glScalef(32, 128, 2);
      cubo -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   //Muros flotantes traseros
   glPushMatrix ();
      glTranslatef(-32.0f, 220.0f, -250.0f);
      glRotatef(90, 0, 1, 0);
      glScalef(32, 128, 2);
      cubo -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();
   glPushMatrix ();
      glTranslatef(32.0f, 220.0f, -250.0f);
      glRotatef(90, 0, 1, 0);
      glScalef(32, 128, 2);
      cubo -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef(-32.0f, 110.0f, -125.0f);
      glRotatef(90, 0, 1, 0);
      glScalef(32, 128, 2);
      cubo -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();
   glPushMatrix ();
      glTranslatef(32.0f, 110.0f, -125.0f);
      glRotatef(90, 0, 1, 0);
      glScalef(32, 128, 2);
      cubo -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();


   glPushMatrix ();
      glTranslatef(0.0f, 0.0f, -64.0f);
      glScalef(32, 128, 2);
      cubo -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Lineas
   glPushMatrix ();
      glTranslatef(-120, 0.0f, 200.0f);
      glScalef(16, 10, 256);
      cubo -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef(120.0f, 0.0f, 200.0f);
      glScalef(16, 10, 256);
      cubo -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();


   //Muralla
   //Muralla trasera
   glPushMatrix ();
      glTranslatef(0.0f, 0.0f, -190.0f);
      glScalef(820, 60, 16);
      murallas -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   //Murallas laterales
   glPushMatrix ();
      glTranslatef(-403.0f, 0.0f, 280.0f);
      glScalef(16, 60, 935);
      murallas -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();
   glPushMatrix ();
      glTranslatef(403.0f, 0.0f, 280.0f);
      glScalef(16, 60, 935);
      murallas -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();


   // Murallas delanteras
   glPushMatrix ();
      glTranslatef(-275.0f, 0.0f, 750.0f);
      glScalef(260, 60, 16);
      murallas -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();
   glPushMatrix ();
      glTranslatef(275.0f, 0.0f, 750.0f);
      glScalef(260, 60, 16);
      murallas -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Murallas delanteras pequeñas
   glPushMatrix ();
      glTranslatef(-62.0f, 0.0f, 750.0f);
      glScalef(80, 60, 16);
      murallas -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();
   glPushMatrix ();
      glTranslatef(62.0f, 0.0f, 750.0f);
      glScalef(80, 60, 16);
      murallas -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Murallas delanteras rotadas
   glPushMatrix ();
      glTranslatef(-30.0f, 0.0f, 795.0f);
      glScalef(16, 60, 80);
      murallas -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef(30.0f, 0.0f, 795.0f);
      glScalef(16, 60, 80);
      murallas -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Piramides
   glPushMatrix ();
      glTranslatef(0.0f, 0.0f, 0.0f);
      glScalef(128, 128, 128);
      cono2 -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();
   glPushMatrix ();
      glTranslatef(0.0f, 0.0f, 200.0f);
      glScalef(64, 64, 64);
      cono1 -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();
   glPushMatrix ();
      glTranslatef(0.0f, 0.0f, 330.0f);
      glScalef(32, 32, 32);
      cono0 -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();
}

void Escena::disableLights(){
  if (!gl_light0_enabled) glDisable(GL_LIGHT0);
  if (!gl_light1_enabled) glDisable(GL_LIGHT1);
  if (!gl_light2_enabled) glDisable(GL_LIGHT2);
  if (!gl_light3_enabled) glDisable(GL_LIGHT3);
  if (!gl_light4_enabled) glDisable(GL_LIGHT4);
  if (!gl_light5_enabled) glDisable(GL_LIGHT5);
  if (!gl_light6_enabled) glDisable(GL_LIGHT6);
  if (!gl_light7_enabled) glDisable(GL_LIGHT7);
}
//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   using namespace std ;
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   bool salir=false;

   if ( modoMenu == ZOOM ){
      cout << "MODO ZOOM" << endl;
      switch( toupper(tecla) ){
         case 'Q' :
            modoMenu=NADA; 
            break ;
         case '+':
            std::cout << "Zoom cámara " << camaraActiva << " ++ " << std::endl;
            camaras[camaraActiva]->zoom(-0.1);
            change_projection(1);
            break;
         case '-':
            std::cout << "Zoom cámara " << camaraActiva << " -- " << std::endl;
            camaras[camaraActiva]->zoom(+0.1);
            change_projection(1);
            break;
      }
   } else if ( modoMenu == CAMARA ){
      cout << "MODO CAMARA" << endl;
      switch( toupper(tecla) ){
         case 'Q' :
            modoMenu=NADA; 
            break ;
         case '0':
            std::cout << "CAMARA 0 ACTIVA" << std::endl;
            camaraActiva = 0;
            change_projection(1);
            break;
         case '1':
            std::cout << "CAMARA 1 ACTIVA" << std::endl;
            camaraActiva = 1;
            change_projection(1);
            break;
         case '2':
            std::cout << "CAMARA 2 ACTIVA" << std::endl;
            camaraActiva = 2;
            change_projection(1);
            break;
         case '3':
            std::cout << "CAMARA 3 ACTIVA" << std::endl;
            camaraActiva = 3;
            change_projection(1);
            break;
      }
   } else if ( modoMenu == MANUAL ){
      switch( toupper(tecla) ){
         case 'Q' :
            modoMenu=NADA; 
            gradoslibertad=EMPTY;           
            break ;
         case '0':
            std::cout << "ROTACION SATELITE" << std::endl;
            gradoslibertad = SATELITE;
            break;
         case '1':
            std::cout << "ROTACION ESFERA" << std::endl;
            gradoslibertad = ESFERA;
            break;
         case '2':
            std::cout << "TRASLACION ANILLO" << std::endl;
            gradoslibertad = ANILLO;
            break;
         case '+':
            std::cout << "MODO MANUAL INCREMENTO" << std::endl;
            degrees_increment = true;
            number_of_degrees = 10;
            break;
         case '-':
            std::cout << "MODO MANUAL DECREMENTO" << std::endl;
            degrees_increment = false;
            number_of_degrees = 10;
            break;
      }
   }else if ( modoMenu == ANIMACION ){
      switch( toupper(tecla) ){
         case 'A' :
            animation_enabled = !animation_enabled;  
            break ;
         case 'Q' :
            modoMenu=NADA;            
            break ;
         case '+':
            if(modoMenu==ANIMACION){
               cout << "MODO ANIMACION: AUMENTO VELOCIDAD " << animation_speed << endl;
               if (animation_speed <50 ) animation_speed+= 1;
            }
            break;
         case '-':
            if(modoMenu==ANIMACION){
               cout << "MODO ANIMACION: DISMINUCION VELOCIDAD " << animation_speed <<endl;
               if (animation_speed >0 ) animation_speed-= 1;
            }
            break;
      }
   }
   else if ( modoMenu == SELVISUALIZACION || modoMenu == SELILUMINACION ) {
      switch( toupper(tecla) )
      {
         case 'Q' :
               modoMenu=NADA;            
            break ;     
         case 'P' :
            if (modoMenu==SELVISUALIZACION){
               PointsEnabled = !PointsEnabled;
               LightsEnabled = false;
            }
            else {
               cout << "Primero activa modo de visualizacion (V)" << endl;
            }
            break ;
         case 'L' :
            if (modoMenu==SELVISUALIZACION){
               LinesEnabled = !LinesEnabled;
               LightsEnabled = false;
            }
            else {
               cout << "Primero activa modo de visualizacion (V)" << endl;
            }
            break ;
         case 'S' :
            if (modoMenu==SELVISUALIZACION){
               SolidEnabled = !SolidEnabled;
               LightsEnabled = false;
            }
            else {
               cout << "Primero activa modo de visualizacion (V)" << endl;
            }
            break ;
         case 'I' :
            if (modoMenu==SELVISUALIZACION){
               LightsEnabled = true;
               LinesEnabled = false;
               PointsEnabled = false;
               SolidEnabled = false;
               modoMenu = SELILUMINACION;
            }
            else {
               cout << "Primero activa modo de visualizacion (V)" << endl;
            }
            break ;
         case 'A':
            if(modoMenu==SELILUMINACION){
               alpha_l = true;
               beta_l = false;
               cout << "Activada variación ángulo alpha" << endl;
            }
            break;
         case 'B':
            if(modoMenu==SELILUMINACION){
               alpha_l = false;
               beta_l = true;
               cout << "Activada variación ángulo beta" << endl;
            }
            break;
         case '>':
            if(modoMenu==SELILUMINACION && alpha_l)
               luzdireccional -> aumentarAnguloAlpha(1);
            if(modoMenu==SELILUMINACION && beta_l)
               luzdireccional -> aumentarAnguloBeta(1);
            break;
         case '<':
            if(modoMenu==SELILUMINACION && alpha_l)
               luzdireccional -> disminuirAnguloBeta(1);
            if(modoMenu==SELILUMINACION && beta_l)
               luzdireccional -> disminuirAnguloBeta(1);
            break;
         case '0':
            if(modoMenu==SELILUMINACION){
               gl_light0_enabled = !gl_light0_enabled;
            }
            break;
         case '1':
            if(modoMenu==SELILUMINACION){
               gl_light1_enabled = !gl_light1_enabled;
            }
            break;
         case '2':
            if(modoMenu==SELILUMINACION){
               gl_light2_enabled = !gl_light2_enabled;
            }
            break;
         case '3':
            if(modoMenu==SELILUMINACION){
               gl_light3_enabled = !gl_light3_enabled;
            }
            break;
         case '4':
            if(modoMenu==SELILUMINACION){
               gl_light4_enabled = !gl_light4_enabled;
            }
            break;
         case '5':
            if(modoMenu==SELILUMINACION){
               gl_light5_enabled = !gl_light5_enabled;
            }
            break;
         case '6':
            if(modoMenu==SELILUMINACION){
               gl_light6_enabled = !gl_light6_enabled;
            }
            break;
         case '7':
            if(modoMenu==SELILUMINACION){
               gl_light7_enabled = !gl_light7_enabled;
            }
            break;
         // COMPLETAR con los diferentes opciones de teclado 
      }
   }
   else if (modoMenu == NADA){
      switch( toupper(tecla) )
      {
         case 'Q' :
            salir=true ;
            cout << "FIN DE PROGRAMA" << endl;
            break ;
         case 'V' :
            modoMenu=SELVISUALIZACION;
            break ;
         case 'A' :
            cout << "MODO ANIMACION" << endl;
            modoMenu=ANIMACION;
            animation_enabled = !animation_enabled;
            break ; 
         case 'M' :
            cout << "MODO MANUAL" << endl;
            modoMenu=MANUAL;
            animation_enabled = false;
            break ;
         case 'C' :
            cout << "MODO CAMARA" << endl;
            modoMenu=CAMARA;
            break ; 
         case 'Z' :
            cout << "MODO ZOOM" << endl;
            modoMenu=ZOOM;
            break ; 
         default:
            break;
      }
   }
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         Observer_angle_y-- ;
         Observer_angle_y-- ;
         break;
	   case GLUT_KEY_RIGHT:
         Observer_angle_y++ ;
         Observer_angle_y++ ;
         break;
	   case GLUT_KEY_UP:
         Observer_angle_x-- ;
         Observer_angle_x-- ;
         break;
	   case GLUT_KEY_DOWN:
         Observer_angle_x++ ;
         Observer_angle_x++ ;
         break;
	   case GLUT_KEY_PAGE_UP:
         Observer_distance *=1.2 ;
         break;
	   case GLUT_KEY_PAGE_DOWN:
         Observer_distance /= 1.2 ;
         break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   const float wx = float(Height)*ratio_xy ;
   camaras[camaraActiva]->setProyeccion();
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   for (unsigned int i = 0; i < camaras.size(); i++){
      camaras[i]->updateVisualizationVolume(newWidth, newHeight);
   }
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}



//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef( 0.0, 0.0, -Observer_distance );
   glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
   glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );
}


void Escena::animarModeloJerarquico()
{
   if(animation_enabled){
      luzdireccional-> cambiar_color();
      sunmoon -> change_rotation(0.6);
      sunmoon -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
      column -> ring_movement(animation_speed);
      column -> change_rotation(animation_speed,animation_speed);
      column -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   }
}

void Escena::clickRaton( int boton , int estado , int x, int y )
{
   std::cout << "Button " << boton << "  Status " << estado << " X "<< x << " Y "<< y << std::endl;
   if ( boton == 2 ){
      if ( estado == 0 ){ //Estado 0 == boton pulsado
         // Se pulsa el botón, por lo que se entra en el estado ’moviendo cámara’
         estadoraton = MOVIENDO_CAMARA_FIRSTPERSON;
         std::cout << "Moviendo cámara... " << std::endl;
         xant = x;
         yant = y;
      }
      else{  //Estado 1 == boton no pulsado
         // Se levanta el botón, por lo que se sale del estado ’moviendo cámara’
         estadoraton = NO_MOVIENDO_CAMARA_FIRSTPERSON;
         std::cout << "Dejando de mover cámara... " << std::endl;
      }
   }
}


void Escena::ratonMovido( int x, int y )
{
   std::cout << "( "<< x << " , "<<  y << " ) "<< std::endl;
   if (estadoraton == MOVIENDO_CAMARA_FIRSTPERSON ) {
      camaras[camaraActiva]->girar(x-xant ,y-yant);
      xant = x;
      yant = y;
   }
}

void Escena::custom_change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   camaras[camaraActiva]->setObserver();
}

