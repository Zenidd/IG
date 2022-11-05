#include "auxiliar.h"
#include "malla.h"


// *****************************************************************************
//
// IG_D Clase Malla3D
//
// *****************************************************************************
// -----------------------------------------------------------------------------
// Función de visualización de la malla,

void Malla3D::draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled, bool LightsEnabled)
{
   calcularNormales();
   // VBO Vertices y triangulos
   if ( id_vbo_ver == 0 ) id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER, sizeof(v[0])*v.size(), v.data());
   if ( id_vbo_tri == 0 ) id_vbo_tri = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, sizeof(f[0])*f.size(), f.data());

   // VBO Colores (Sin iluminacion)
   if ( id_vbo_c_s == 0 && !LightsEnabled) id_vbo_c_s = CrearVBO(GL_ARRAY_BUFFER, sizeof(c_s[0])*c_s.size(), c_s.data());
   if ( id_vbo_c_l == 0 && !LightsEnabled) id_vbo_c_l = CrearVBO(GL_ARRAY_BUFFER, sizeof(c_l[0])*c_l.size(), c_l.data());
   if ( id_vbo_c_p == 0 && !LightsEnabled) id_vbo_c_p = CrearVBO(GL_ARRAY_BUFFER, sizeof(c_p[0])*c_p.size(), c_p.data());

   // VBO Luces
   if ( id_vbo_n_ver == 0 && LightsEnabled) id_vbo_n_ver = CrearVBO(GL_ARRAY_BUFFER, sizeof(nv[0])*nv.size(), nv.data());


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
         glBindBuffer(GL_ARRAY_BUFFER , id_vbo_c_l); 
         glColorPointer( 3, GL_FLOAT , 0, 0 );
         glBindBuffer( GL_ARRAY_BUFFER , 0 );
      }
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      glDrawElements( GL_TRIANGLES , 3*f.size(), GL_UNSIGNED_INT , 0 ) ;
   } 
   
   if (PointsEnabled){
      if ( id_vbo_c_p != 0 ) {
         glBindBuffer(GL_ARRAY_BUFFER , id_vbo_c_p);
         glColorPointer( 3, GL_FLOAT , 0, 0 );
         glBindBuffer( GL_ARRAY_BUFFER , 0 );
      }
      glPointSize(6);
      glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
      glDrawElements( GL_TRIANGLES , 3*f.size(), GL_UNSIGNED_INT , 0 ) ;
   }

   if (SolidEnabled){
      if ( id_vbo_c_s != 0 ) {
         glBindBuffer(GL_ARRAY_BUFFER , id_vbo_c_s); 
         glColorPointer( 3, GL_FLOAT , 0, 0 );
         glBindBuffer( GL_ARRAY_BUFFER , 0 );
      }
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

      glDrawElements( GL_TRIANGLES , 3*f.size(), GL_UNSIGNED_INT , 0 ) ;
   } 

   if (LightsEnabled){
      m.aplicar ();
      if ( id_vbo_n_ver != 0 ) {
         glBindBuffer(GL_ARRAY_BUFFER , id_vbo_n_ver); 
         glNormalPointer( GL_FLOAT, sizeof(nv[0]) , nv[0]);
         glBindBuffer( GL_ARRAY_BUFFER , 0 );
      }
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

      glDrawElements( GL_TRIANGLES , 3*f.size(), GL_UNSIGNED_INT , 0 ) ;

      std::cout << "El brillo de mi material es " << m.brillo << std::endl;
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

   void Malla3D::calcularNormales()
   {
      std::vector<Tupla3f> nc;
      nc.resize(f.size());
      nv.resize(v.size());
      Tupla3f q, p, r;
      Tupla3f a, b;
      Tupla3f normal_c;
      for (unsigned int i = 0; i < nv.size(); i++){
         nv[i]={0.0,0.0,0.0};
      }
      for (unsigned int i = 0; i < f.size(); i++){
         q=v[f[i](X)]; p=v[f[i](Y)]; r=v[f[i](Z)];
         a=q-p;
         b=r-p;
         normal_c = a.cross(b);
         nc[i]=normal_c.normalized();
         // std::cout << "{" <<nc[i][X] << "," << nc[i][Y] << "," << nc[i][Z] << "}" << std::endl;

         nv[f[i](X)] = nv[f[i](X)] + nc[i];
         nv[f[i](Y)] = nv[f[i](Y)] + nc[i];
         nv[f[i](Z)] = nv[f[i](Z)] + nc[i];
      }
      for (unsigned int i = 0; i < nv.size(); i++){
         nv[i]=nv[i].normalized();
         // std::cout << "{" <<nv[i][X] << "," << nv[i][Y] << "," << nv[i][Z] << "}" << std::endl;
      }
   }


void Malla3D::setMaterial(Material mat)
{
   m.brillo    = 55.0f;
   m.ambiente  = {35.0f, 0.0f, 0.0f, 0.0f};
   m.difuso    = {35.0f, 0.0f, 0.0f, 0.0f};
   m.especular = {35.0f, 0.0f, 0.0f, 0.0f};
}