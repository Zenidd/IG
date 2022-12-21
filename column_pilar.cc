#include "auxiliar.h"
#include "malla.h"
#include "column_pilar.h"


ColumnPilar::ColumnPilar(unsigned int initial_rotation)
{
   columnring_current_height = 30;
   rotation_degrees = initial_rotation;
   cilindro = new Cilindro(30, 20, 1, 1);
   columnring = new ColumnRing();
}

void ColumnPilar::draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled, bool LightsEnabled){
   glPushMatrix();
      glPushMatrix();
         glScalef(8, 64, 8);
         cilindro -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
      glPopMatrix();
      glPushMatrix();
         glTranslatef(0, columnring_current_height , 0);
         columnring -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
      glPopMatrix();
   glPopMatrix();
}

void ColumnPilar::ring_movement(unsigned int units){
   rotation_degrees+=units;
   // std::cout << "columnring_current_height es " << rotation_degrees << std::endl;
   columnring_current_height=sin(rotation_degrees*(M_PI/180))*20 +30;
   // std::cout << "columnring_current_height es " << columnring_current_height << std::endl;
}


void ColumnPilar::change_rotation(unsigned int ring_degrees, unsigned int sphere_degrees){
   columnring -> change_rotation(ring_degrees, sphere_degrees );
}

void ColumnPilar::set_rotation_sense(bool ccw_rotation){
   columnring -> set_rotation_sense(ccw_rotation);
}


