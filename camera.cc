#include "auxiliar.h"
#include "malla.h"
#include "camera.h"
#include "material.h"
#include "tuplasg.h"

Camara::Camara (Tupla3f eye, Tupla3f at, Tupla3f up, int tipo, float left, 
                float right, float bottom, float top, float near, float far){
    this->eye = eye;
    this->at = at;
    this->up = up;
    this->tipo = tipo;
    this->left = left; 
    this->right = right;
    this->near = near;
    this->far = far;
    this->top = top;
    this->bottom = bottom;
}

// Tipo 0 = perspectiva
// Tipo 1 = ortogonal

void Camara::rotarXExaminar(float angle){

}
void Camara::rotarYExaminar(float angle){

}
void Camara::rotarZExaminar(float angle){

}
void Camara::rotarXFirstPerson(float angle){

}
void Camara::rotarYFirstPerson(float angle){

}
void Camara::girar(int x, int y){

    alpha+=(float)(x*0.01);
    beta+=(float)(y*0.01);

    eye(Z) = dist*cos(alpha)*cos(beta);
    eye(Y) = dist*cos(alpha)*sin(beta);
    eye(X) = dist*sin(alpha);

    std::cout << eye << "\n";

}

void Camara::mover(float x, float y, float z){

}
void Camara::zoom ( float factor ){

}

void Camara::setObserver(){ // completar
    gluLookAt(  eye[X], eye[Y], eye[Z],
                 at[X], at[Y], at[Z],
                 up[X], up[Y], up[Z]);
} 

void Camara::setProyeccion (){   
    if(tipo == 0){ // Tipo 0 = perspectiva
        // glMatrixMode( GL_PROJECTION );
        // glLoadIdentity();
        std::cout << "FRUSTUM" << std::endl;
        glFrustum(left, right, 
                bottom, top, 
                near, far);
    }
    else if (tipo == 1) { // Tipo 1 = ortogonal
        // glMatrixMode( GL_PROJECTION );
        // glLoadIdentity();
        std::cout << "ORTHO" << std::endl;
        glOrtho(left, right, 
        bottom, top, 
        near, far);
    }
}