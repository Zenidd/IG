#include "auxiliar.h"
#include "malla.h"
#include "column_sphere.h"


ColumnSphere::ColumnSphere(unsigned int initial_rotation) : rotation_degrees(initial_rotation)
{
   esfera = new Esfera(30, 20, 1, "black_hole.jpeg");
   satelite = new Esfera(30, 20, 1);
}

void ColumnSphere::draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled, bool LightsEnabled){
   glPushMatrix();
      glPushMatrix();   
         glScalef(8,8,8);
         esfera -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
      glPopMatrix();
      glPushMatrix();
         glRotatef(rotation_degrees, 1.0,0.0,0.0);
         glTranslatef(0,16,0);
         glScalef(4,4,4);
         satelite -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
      glPopMatrix();
   glPopMatrix();
}

void ColumnSphere::change_rotation(int degrees){
   if (ccw_rotation) rotation_degrees += degrees;
   else rotation_degrees -= degrees;
   rotation_degrees %= 360;
   // std::cout << "Rotation degrees are: " << rotation_degrees << std::endl;
}

void ColumnSphere::set_rotation_sense(bool ccw_rotation_sense){
   if (ccw_rotation_sense) ccw_rotation = true;
   else  ccw_rotation = false;
   
}