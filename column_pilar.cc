#include "auxiliar.h"
#include "malla.h"
#include "column_pilar.h"


ColumnPilar::ColumnPilar(unsigned int initial_rotation)

{
   columnring_current_height = 70;
   columnring_max_height = 64;
   columnring_min_height = 8;
   rotation_degrees = initial_rotation;
   cilindro = new Cilindro(30, 50, 1, 1);
   columnring = new ColumnRing();
}

void ColumnPilar::draw(){
   glPushMatrix();
      glPushMatrix();
         glScalef(8, 64, 8);
         cilindro -> draw(0, 0, 0, 1);
      glPopMatrix();
      glPushMatrix();
         glTranslatef(0, columnring_current_height , 0);
         glRotatef(rotation_degrees, 0.0, 1.0, 0.0);
         columnring -> draw();
      glPopMatrix();
   glPopMatrix();
}


void ColumnPilar::change_rotation(unsigned int degrees, unsigned int ring_degrees, unsigned int sphere_degrees){
   rotation_degrees += degrees;
   rotation_degrees %= 360;
   columnring -> change_rotation(ring_degrees, sphere_degrees );
}

void ColumnPilar::change_height(unsigned int height){
   columnring_current_height += 1;
   if (columnring_current_height >= columnring_max_height) columnring_current_height = columnring_max_height;
   if (columnring_current_height <= columnring_max_height) columnring_current_height = columnring_min_height;
}

