#include "auxiliar.h"
#include "malla.h"

// *****************************************************************************
//
// IG_D Clase Malla3D
//
// *****************************************************************************
// -----------------------------------------------------------------------------
// Función de visualización de la malla,



void Malla3D::draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled)
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   if ( id_vbo_ver == 0 ) id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER, sizeof(v[0])*v.size(), v.data());
   if ( id_vbo_tri == 0 ) id_vbo_tri = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, sizeof(f[0])*f.size(), f.data());


   if ( id_vbo_c_s == 0 ) id_vbo_c_s = CrearVBO(GL_ARRAY_BUFFER, sizeof(c_s[0])*c_s.size(), c_s.data());
   if ( id_vbo_c_l == 0 ) id_vbo_c_l = CrearVBO(GL_ARRAY_BUFFER, sizeof(c_l[0])*c_l.size(), c_l.data());
   if ( id_vbo_c_p == 0 ) id_vbo_c_p = CrearVBO(GL_ARRAY_BUFFER, sizeof(c_p[0])*c_p.size(), c_p.data());
   
   glEnableClientState( GL_COLOR_ARRAY );

   glBindBuffer( GL_ARRAY_BUFFER , id_vbo_ver );
   // usar como buffer de vertices el actualmente activo
   glVertexPointer( 3, GL_FLOAT , 0, 0 );
   // deactivar buffer: VBO de vértices.
   glBindBuffer( GL_ARRAY_BUFFER , 0 );

   // habilitar el uso de tabla de vértices  
   glEnableClientState( GL_VERTEX_ARRAY );
   // activar buffer: VBO de triángulos
   glBindBuffer( GL_ELEMENT_ARRAY_BUFFER , id_vbo_tri );




   if (LinesEnabled){
      if ( id_vbo_c_l != 0 ) {
         // glBindBuffer(GL_ARRAY_BUFFER , id_vbo_c_l); // Usar el buffer activo para el color
         // glColorPointer( 3, GL_FLOAT , 0, 0 );
         // glBindBuffer( GL_ARRAY_BUFFER , 0 );
      }
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      // glScalef(20,20,20);
      glDrawElements( GL_TRIANGLES , 3*f.size(), GL_UNSIGNED_INT , 0 ) ;
   } 
   
   if (PointsEnabled){
      if ( id_vbo_c_s != 0 ) {
         // glBindBuffer(GL_ARRAY_BUFFER , id_vbo_c_s); // Usar el buffer activo para el color
         // glColorPointer( 3, GL_FLOAT , 0, 0 );
         // glBindBuffer( GL_ARRAY_BUFFER , 0 );
      }
      glPointSize(6);
      glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
      // glScalef(20,20,20);
      glDrawElements( GL_TRIANGLES , 3*f.size(), GL_UNSIGNED_INT , 0 ) ;
   }

   if (SolidEnabled){
      if ( id_vbo_c_p != 0 ) {
         // glBindBuffer(GL_ARRAY_BUFFER , id_vbo_c_p); // Usar el buffer activo para el color
         // glColorPointer( 3, GL_FLOAT , 0, 0 );
         // glBindBuffer( GL_ARRAY_BUFFER , 0 );
      }
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      // glScalef(20,20,20);
      glDrawElements( GL_TRIANGLES , 3*f.size(), GL_UNSIGNED_INT , 0 ) ;
   } 


   // desactivar buffer: VBO de triángulos
   glBindBuffer( GL_ELEMENT_ARRAY_BUFFER , 0 );
   // desactivar uso de array de vértices y colores
   glDisableClientState( GL_VERTEX_ARRAY );
   glDisableClientState( GL_COLOR_ARRAY );
}


GLuint Malla3D::CrearVBO(GLuint tipo_vbo, GLuint tam, GLvoid * puntero_ram)
{
   GLuint id_vbo ;    // resultado: identificador de VBO
   glGenBuffers( 1, & id_vbo ); // crear nuevo VBO, obtener identificador
   glBindBuffer( tipo_vbo , id_vbo);    // activar el VBO usando su identificador 
   glBufferData( tipo_vbo, tam, puntero_ram, GL_STATIC_DRAW );    // esta instrucción hace la transferencia de datos desde RAM hacia GPU
   glBindBuffer( tipo_vbo , 0 ); // desactivación del VBO (activar 0) 
   return id_vbo ; // devolver el identificador resultado  
}