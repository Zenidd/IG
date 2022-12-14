#include "column_ring.h"


ColumnRing::ColumnRing(unsigned int initial_rotation)
{
   rotation_degrees = initial_rotation;
   columnsphere = new ColumnSphere(0);
   anillo = new Anillo(30, 20, 1, 1);
}

void ColumnRing::draw(){
   glPushMatrix();
      glPushMatrix();
         glScalef(16,8,16);
         glTranslatef(0,-0.5,0);
         anillo -> draw(0,0,0,1);
      glPopMatrix();
      glRotatef(rotation_degrees, 0.0,1.0,0.0);
      glPushMatrix();
         glTranslatef(32,0,0);
         columnsphere -> draw();
      glPopMatrix();
   glPopMatrix();
}

void ColumnRing::change_rotation(unsigned int degrees, unsigned int satelital_degrees){
   rotation_degrees += degrees;
   columnsphere -> change_rotation(satelital_degrees);
}

ColumnRing::~ColumnRing(){
   delete columnsphere;
   delete anillo;
}
