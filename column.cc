#include "auxiliar.h"
#include "malla.h"
#include "column.h"



Column::Column()
{
   direction = DOWN;
   columnpilar = new ColumnPilar();
   esfera = new Esfera(10, 10, 10);
}

void Column::draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled, bool LightsEnabled){
   glPushMatrix();
      columnpilar -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);   
   glPopMatrix();
}

void Column::change_rotation(unsigned int ring_degrees, unsigned int sphere_degrees){
   // ring_degrees %= 360;
   // sphere_degrees %= 360;
   columnpilar -> change_rotation(ring_degrees, sphere_degrees );
}

void Column::set_rotation_sense(bool ccw_rotation){
   columnpilar -> set_rotation_sense(ccw_rotation );
}

void Column::ring_movement(unsigned int units){
   columnpilar -> ring_movement(units);
}
