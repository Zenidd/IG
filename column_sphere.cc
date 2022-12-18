#include "auxiliar.h"
#include "malla.h"
#include "column_sphere.h"


ColumnSphere::ColumnSphere(unsigned int initial_rotation) : rotation_degrees(initial_rotation)
{
   esfera = new Esfera(30, 50, 1);
   satelite = new Esfera(30, 50, 1);
}

void ColumnSphere::draw(){
   glPushMatrix();
      glPushMatrix();   
         glScalef(8,8,8);
         esfera -> draw(0,0,0,1);
      glPopMatrix();
      glPushMatrix();
         glRotatef(rotation_degrees, 1.0,0.0,0.0);
         glTranslatef(0,16,0);
         glScalef(4,4,4);
         satelite -> draw(0,0,0,1);
      glPopMatrix();
   glPopMatrix();
}

void ColumnSphere::change_rotation(unsigned int degrees){
   rotation_degrees += degrees;
}