#include "auxiliar.h"
#include "malla.h"
#include "sun_moon.h"
#include "material.h"
#include "tuplasg.h"

SunMoon::SunMoon()
{
   Tupla4f m_ambiental(1.0, 1.0, 1.0, 1.0);
   Tupla4f m_difusa(1.0, 1.0, 1.0, 1.0);
   Tupla4f m_especular(0.0, 0.0, 0.0, 0.0);

   m_ambiental = {0.7, 0.0, 0.0, 0.1};
   m_difusa = {0.940, 0.0564, 0.0564, 0.5};
   m_especular = {0.940, 0.0564, 0.0564, 1.0};
   Material sun_m(m_ambiental, m_especular, m_difusa, 50.0);

   m_ambiental = {0.0, 0.0, 0.0, 0.1};
   m_difusa = {1.00, 0.785, 0.0800, 0.5};
   m_especular = {1.00, 0.785, 0.0800, 1.0};
   Material moon_m(m_ambiental, m_especular, m_difusa, 50.0);


   Tupla3f posicionLuz = Tupla3f(0.0f, 300.0f, -400.0f);
   Tupla4f ambiental(0, 0, 0, 0);
   Tupla4f difusa(0.84,0,0.9,1.0);
   Tupla4f especular(0.84,0,0.9,1.0);


   Tupla3f posicionLuz_moon = Tupla3f(0.0f, -300.0f, -400.0f);
   Tupla4f ambiental_moon(0.0, 0.0, 0.0, 0.0);
   Tupla4f difusa_moon(1.0,1.0,1.0,1.0);
   Tupla4f especular_moon(1.0,1.0,1.0,1.0);

   sun = new Esfera(50, 50, 10);
   moon = new Esfera(50, 50, 10);
   this->sun->setMaterial(sun_m);
   this->moon->setMaterial(moon_m);
   this->luzposicionalsol = new LuzPosicional(posicionLuz, GL_LIGHT3, ambiental, especular, difusa);
   this->luzposicionalmoon = new LuzPosicional(posicionLuz_moon, GL_LIGHT4, ambiental_moon, especular_moon, difusa_moon);

}



void SunMoon::draw(bool PointsEnabled, bool LinesEnabled, bool SolidEnabled, bool LightsEnabled){
   glPushMatrix();
      glRotatef(rotation, 0, 0, 1);
      luzposicionalsol -> activar();
      luzposicionalmoon -> activar();
      glTranslatef(0,0,-400);
      glPushMatrix();
         glTranslatef(0,300,0);
         glScalef(5,5,5);
         sun -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);
      glPopMatrix();
      glPushMatrix();
         glTranslatef(0,-300,0);
         glScalef(5,5,5);
         moon -> draw(PointsEnabled, LinesEnabled, SolidEnabled, LightsEnabled);   
      glPopMatrix();
   glPopMatrix();
}

void SunMoon::change_rotation(float units){
   rotation += units;

   // rotation %= 360;
}

