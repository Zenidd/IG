#include "column_ring.h"


ColumnRing::ColumnRing(unsigned int initial_rotation)
{
   rotation_degrees = initial_rotation;
   columnsphere = new ColumnSphere(0);
   anillo = new Anillo(30, 20, 1, 1);
}

void ColumnRing::draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled, bool LightsEnabled){
   glRotatef(rotation_degrees, 0.0,1.0,0.0);
   glPushMatrix();
      glPushMatrix();
         glScalef(16,8,16);
         glTranslatef(0,-0.5,0);
         anillo -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
      glPopMatrix();
      glPushMatrix();
         glTranslatef(32,0,0);
         columnsphere -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
      glPopMatrix();
   glPopMatrix();
}

void ColumnRing::change_rotation(int degrees, int satelital_degrees){
   if (ccw_rotation) rotation_degrees += degrees;
   else rotation_degrees -= degrees;
   // rotation_degrees %=360;
   // satelital_degrees %=360;
   columnsphere -> change_rotation(satelital_degrees);
}

void ColumnRing::set_rotation_sense(bool ccw_rotation_sense){
   if (ccw_rotation_sense){
      ccw_rotation = true;
      columnsphere -> set_rotation_sense(true);
   } 
   else {
      ccw_rotation = false;
      columnsphere -> set_rotation_sense(false);
   }
}

ColumnRing::~ColumnRing(){
   delete columnsphere;
   delete anillo;
}
