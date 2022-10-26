
#include "auxiliar.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{

    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;
    Scale             = 1.0 ; 

    ejes.changeAxisSize( 5000 );
    cubo = new Cubo(70);
    piramide = new PiramidePentagonal(70, 50);
    objetoply = new ObjPLY("./plys/untitled.ply");
   //  objrevolucion = new ObjRevolucion("./plys/lata-pinf.ply", 80);
   //  objrevolucion1 = new ObjRevolucion("./plys/lata-psup.ply", 80);
   //  objrevolucion2 = new ObjRevolucion("./plys/lata-pcue.ply", 80);


   cono = new Cono(10, 4, 30, 10);
   cono1 = new Cono(10, 4, 60, 20);
   cono2 = new Cono(10, 4, 120, 30);
   esfera = new Esfera(100, 150, 10);
   esfera1 = new Esfera(100, 150, 20);
   esfera2 = new Esfera(100, 150, 30);
   

   cilindro = new Cilindro(20, 20, 4, 300);
   cilindro1 = new Cilindro(20, 20, 4, 600);

}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer
	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );

   glEnable(GL_CULL_FACE);
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
   ejes.draw();
   glScalef(Scale,Scale,Scale);
   if (CubeEnabled) cubo -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   if (PyramidEnabled) piramide -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   glPushMatrix ();
   glTranslatef(0, 0, -100);
   if (OplyEnabled) objetoply -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   glPopMatrix ();
   // objrevolucion -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   // objrevolucion1 -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   // objrevolucion2 -> draw(PointsEnabled, LinesEnabled, SolidEnabled);

   glPushMatrix ();
   glTranslatef(0, 0, -50);
   cono -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   glPopMatrix ();
   glPushMatrix ();
   glTranslatef(0, 0, 0);
   cono1 -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   glPopMatrix ();
   glPushMatrix ();
   glTranslatef(0, 0, 60);
   cono2 -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   glPopMatrix ();
   glPushMatrix ();
   glTranslatef(0, 50, -50);
   esfera -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   glPopMatrix ();
   glPushMatrix ();
   glTranslatef(0, 100, 0);
   esfera1 -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   glPopMatrix ();
   glPushMatrix ();
   glTranslatef(0, 160, 60);
   esfera2 -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   glPopMatrix ();

   glPushMatrix ();
   glTranslatef(0, -10, 0);
   cilindro -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   glPopMatrix ();   

   glPushMatrix ();
   glTranslatef(0, -20, 0);
   cilindro1 -> draw(PointsEnabled, LinesEnabled, SolidEnabled);
   glPopMatrix ();   
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
   switch( toupper(tecla) )
   {
      case 'Q' :
         if (modoMenu!=NADA)
            modoMenu=NADA;            
         else {
            salir=true ;
         }
         break ;
      case 'O' :
         cout << "MODO SEL DE OBJETO" << endl;
         modoMenu=SELOBJETO; 
         break ;
      case 'V' :
         cout << "MODO VISUALIZACION" << endl;
         modoMenu=SELVISUALIZACION;
         break ;
      case 'C' :
         if (modoMenu==SELOBJETO) 
            if (!CubeEnabled) CubeEnabled = true;
            else CubeEnabled = false;
         else {
            cout << "Primero activa modo de Sel. Objeto (O)" << endl;
         }
         break ;
      case 'P' :
         if (modoMenu==SELOBJETO) 
            if (!PyramidEnabled) PyramidEnabled = true;
            else PyramidEnabled = false;
         else {
            cout << "Primero activa modo de Sel. Objeto (O)" << endl;
         }
         break ;
      case 'K' :
         if (modoMenu==SELOBJETO) 
            if (!OplyEnabled) OplyEnabled = true;
            else OplyEnabled = false;
         else {
            cout << "Primero activa modo de Sel. Objeto (O)" << endl;
         }
         break ;         
      case 'D' :
         if (modoMenu==SELVISUALIZACION) 
            if (!PointsEnabled) PointsEnabled = true;
            else PointsEnabled = false;
         else {
            cout << "Primero activa modo de visualizacion (V)" << endl;
         }
         break ;
      case 'L' :
         if (modoMenu==SELVISUALIZACION) 
            if (!LinesEnabled) LinesEnabled = true;
            else LinesEnabled = false;
         else {
            cout << "Primero activa modo de visualizacion (V)" << endl;
         }
         break ;
      case 'S' :
         if (modoMenu==SELVISUALIZACION) 
            if (!SolidEnabled) SolidEnabled = true;
            else SolidEnabled = false;
         else {
            cout << "Primero activa modo de visualizacion (V)" << endl;
         }
         break ;
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
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         Observer_angle_y-- ;
         break;
	   case GLUT_KEY_RIGHT:
         Observer_angle_y++ ;
         break;
	   case GLUT_KEY_UP:
         Observer_angle_x-- ;
         break;
	   case GLUT_KEY_DOWN:
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
