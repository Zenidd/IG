
#include "auxiliar.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....
#include "luz.h"

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{

   Front_plane       = 50.0;
   Back_plane        = 2000.0;
   Observer_distance = 6*Front_plane;
   Observer_angle_x  = 0.0 ;
   Observer_angle_y  = 0.0 ;
   Scale             = 1.0 ; 


   // EJES
   ejes.changeAxisSize( 5000 );

   // LUCES
   Tupla3f posicionLuz = Tupla3f(0.0f, 90.0f, -110.0f);
   Tupla4f ambiental(0.0, 0.0, 0.0, 0.0);
   Tupla4f difusa(0.84,0,0.9,1.0);
   Tupla4f especular(0.84,0,0.9,1.0);

   this->luzposicional = new LuzPosicional(posicionLuz, GL_LIGHT0, ambiental, especular, difusa);


   Tupla2f orientacion(0.0f, 0.0f);\
   Tupla4f d_ambiental(0.0, 0.0, 0.0, 0.0);
   Tupla4f d_difusa(1.0,1.0,1.0,1.0);
   Tupla4f d_especular(1.0,1.0,1.0,1.0);

   this->luzdireccional = new LuzDireccional(orientacion, GL_LIGHT1, d_ambiental, d_especular, d_difusa);

   // MATERIALES

   Material defecto;

   Tupla4f m_ambiental(1.0, 1.0, 1.0, 1.0);
   Tupla4f m_difusa(1.0, 1.0, 1.0, 1.0);
   Tupla4f m_especular(0.0, 0.0, 0.0, 0.0);
   Material blanco_d(m_ambiental, m_especular, m_difusa ,64.0);


   m_ambiental = {0.2, 0.2, 0.2, 1.0};
   m_difusa = {0.2, 0.2, 0.2, 0.3};
   m_especular = {1.0, 1, 1, 1.0};
   Material negro_e(m_ambiental, m_especular, m_difusa, 40.0);


   m_ambiental = {0.38,0.39,0.35, 0.1};
   m_difusa = {0.38,0.39,0.35,0.5};
   m_especular = {0.38,0.39,0.35,1.0};
   Material egypt_m(m_ambiental, m_especular, m_difusa, 50.0);

   m_ambiental = {0.7, 0.0, 0.0, 0.1};
   m_difusa = {0.940, 0.0564, 0.0564, 0.5};
   m_especular = {0.940, 0.0564, 0.0564, 1.0};
   Material sun0(m_ambiental, m_especular, m_difusa, 50.0);

   m_ambiental = {0.0, 0.0, 0.0, 0.1};
   m_difusa = {1.00, 0.785, 0.0800, 0.5};
   m_especular = {1.00, 0.785, 0.0800, 1.0};
   Material sun1(m_ambiental, m_especular, m_difusa, 50.0);

   m_ambiental = {0.00604, 0.00120, 0.0100, 1.0};
   m_difusa = {0.00604, 0.00120, 0.0100, 1.0};
   m_especular = {0.00604, 0.00120, 0.0100, 1.0};
   Material sun2(m_ambiental, m_especular, m_difusa, 50.0);

   m_ambiental = {0.76,0.7,0.5, 1.0};
   m_difusa = {0.76,0.7,0.5, 1.0};
   m_especular = {0.76,0.7,0.5, 1.0};
   Material floor(m_ambiental, m_especular, m_difusa, 50.0);


   // OBJETOS
   objrevolucion = new ObjRevolucion("./plys/peon.ply", 80);
   objrevolucion1 = new ObjRevolucion("./plys/peon.ply", 80);
   
   objetoply = new ObjPLY("./plys/untitled.ply");
   mountainPLY = new ObjPLY("./plys/mountain.ply");

   cono0 = new Cono(10, 4, 40, 40);
   cono1 = new Cono(10, 4, 50, 50);
   cono2 = new Cono(10, 4, 60, 60);

   esfera0 = new Esfera(30, 50, 20);
   esfera1 = new Esfera(30, 50, 20);
   esfera2 = new Esfera(30, 50, 20);

   cilindro = new Cilindro(30, 20, 4, 1000);

   column = new Column();

   sunmoon = new SunMoon();

   this->esfera0->setMaterial(sun0);
   this->esfera1->setMaterial(sun1);
   this->esfera2->setMaterial(sun2);

   this->cilindro->setMaterial(floor);

   this->objetoply->setMaterial(egypt_m);
   this->mountainPLY->setMaterial(egypt_m);

   this->objrevolucion->setMaterial(blanco_d);
   this->objrevolucion1->setMaterial(negro_e);


   this->cono0->setMaterial(egypt_m);
   this->cono1->setMaterial(egypt_m);
   this->cono2->setMaterial(egypt_m);



}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 0.591, 0.767, 0.910, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
	// glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

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
	change_observer();
   glPushMatrix();
      if (LightsEnabled) glDisable(GL_LIGHTING);
      ejes.draw();
      if (LightsEnabled) glEnable(GL_LIGHTING);
   glPopMatrix();
   glScalef(Scale,Scale,Scale);
   if (LightsEnabled) glEnable(GL_LIGHTING); 
   else glDisable(GL_LIGHTING); 


   // \ivación luces
   luzposicional->activar();
   glPushMatrix();
      if(alpha_l){
         luzdireccional->variarAnguloAlpha(var_a);
         var_a = 0;
      }
      if(beta_l){
         luzdireccional->variarAnguloBeta(var_b);
         var_b = 0;
      } 
      luzdireccional->cambiarAngulo();
      luzdireccional->activar();
   glPopMatrix();


   // Interruptores Luces
   if(LightsEnabled) disableLights();

   // glPushMatrix ();
   //    glTranslatef(-70.0f, 35.0f, 70.0f);
   //    glScalef(20.0f, 20.0f, 20.0f);
   //    objrevolucion -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   // glPopMatrix ();

   glPushMatrix ();
      sunmoon -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();


   // Testing
   glPushMatrix ();
      glTranslatef(0.0, 0.0, -50.0);
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
      column -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // glPushMatrix ();
   //    glTranslatef(70.0f, 35.0f, 70.0f);
   //    glScalef(20.0f, 20.0f, 20.0f);
   //    objrevolucion1 -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   // glPopMatrix ();


   glPushMatrix ();
      glTranslatef(0.0f, -3.0f, 0.0f);
      cilindro -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // //Soles 
   // glPushMatrix ();
   //    glTranslatef(0.0f, 90.0f, -110.0f);
   //    esfera0 -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   // glPopMatrix ();

   // glPushMatrix ();
   //    glTranslatef(0.0f, 130.0f, 0.0f);
   //    esfera1 -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   // glPopMatrix ();

   // glPushMatrix ();
   //    glTranslatef(0.0f, 160.0f, 110.0f);
   //    esfera2 -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   // glPopMatrix ();



   // Mountain
    glPushMatrix ();
      glTranslatef(0.0f, 80.0f, -300.0f);
      glScalef(150.0f, 150.0f, 150.0f);
      glRotatef(90, 0.0f, 1.0f, 0.0f);
      glRotatef(-90, 1.0f, 0.0f, 0.0f);
      mountainPLY -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();  


    glPushMatrix ();
      glTranslatef(140.0f, 80.0f, -300.0f);
      glScalef(150.0f, 150.0f, 150.0f);
      glRotatef(90, 0.0f, 1.0f, 0.0f);
      glRotatef(-90, 1.0f, 0.0f, 0.0f);
      mountainPLY -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();  


    glPushMatrix ();
      glTranslatef(-140.0f, 80.0f, -300.0f);
      glScalef(150.0f, 150.0f, 150.0f);
      glRotatef(90, 0.0f, 1.0f, 0.0f);
      glRotatef(-90, 1.0f, 0.0f, 0.0f);
      mountainPLY -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();  

   // Estatuas
   glPushMatrix ();
      glTranslatef(-100.0f, 0.0f, -70.0f);
      objetoply -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef(100.0f, 0.0f, -70.0f);
      objetoply -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   // Piramides
   glPushMatrix ();
      glTranslatef(0.0f, 0.0f, 40.0f);
      cono0 -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();


   glPushMatrix ();
      glTranslatef(0.0f, 0.0f, 150.0f);
      cono1 -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef(0.0f, 0.0f, 260.0f);
      cono2 -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
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


   if ( modoMenu == MANUAL ){
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
               cout << "MODO ANIMACION: AUMENTO VELOCIDAD" << endl;
            }
            break;
         case '-':
            if(modoMenu==ANIMACION){
               cout << "MODO ANIMACION: DISMINUCION VELOCIDAD" << endl;
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
         // case 'V' :
         //    cout << "MODO VISUALIZACION" << endl;
         //    modoMenu=SELVISUALIZACION;
         //    break ;     
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
               var_a=4;
            if(modoMenu==SELILUMINACION && beta_l)
               var_b=4;
            break;
         case '<':
            if(modoMenu==SELILUMINACION && alpha_l)
               var_a= -4;
            if(modoMenu==SELILUMINACION && beta_l)
               var_b= -4;
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
         case 'Z' :
            Scale+=2;
            cout << "Scale equal to " << Scale << endl;
            break ;
         case 'X' :
            Scale-=2;
            cout << "Scale equal to " << Scale << endl;
            break ;
         // COMPLETAR con los diferentes opciones de teclado 
      }
   }
   else if (modoMenu == NADA){
      switch( toupper(tecla) )
      {
         case 'Q' :
            salir=true ;   
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
   glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
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
      sunmoon -> change_rotation(0.6);
      sunmoon -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
      column -> ring_movement(5);
      column -> change_rotation(5,5);
      column -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
   }
}