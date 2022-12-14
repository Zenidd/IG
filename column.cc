#include "auxiliar.h"
#include "malla.h"
#include "column.h"



Column::Column()
{
   direction = DOWN;
   columnpilar = new ColumnPilar();
}

void Column::draw(){
   columnpilar -> change_rotation();
   columnpilar -> draw();   
}
