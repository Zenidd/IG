// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJREVOLUCION_H_INCLUDED
#define OBJREVOLUCION_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class ObjRevolucion : public Malla3D
{
   public:
    ObjRevolucion();
    ObjRevolucion(const std::string & archivo, int num_instancias);
    ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias) ;
    void replicas(std::vector<Tupla3f> tabla_vertices, int num_instancias);
private:
    void crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias);
    void polos(std::vector<Tupla3f> archivo);
    void crearTapa(std::vector<Tupla3f> perfil_original, int num_instancias, char polo);
    void createColours(int size);
    std::vector<Tupla3f> v_perfil ;
    Tupla3f v_polo_n, v_polo_s;
    bool polo_n = false, polo_s = false;
} ;




#endif
