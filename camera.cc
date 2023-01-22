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
    this->dist =sqrt(eye[X]*eye[X]+eye[Z]*eye[Z]+eye[Y]*eye[Y]);
    this->factor = 1;
    this->alpha=-atan(eye[X]/eye[Z])*(180/M_PI);
    this->beta=-atan(sqrt(eye[X]*eye[X]+eye[Y]*eye[Y])/eye[Z])*(180/M_PI);
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
    alpha+=(float)(x*0.1);
    beta+=(float)(y*0.1);

    eye(Z) =  dist * cosf((alpha)*(M_PI/180)) * cosf((beta)*(M_PI/180));   
    eye(Y) = dist * -sinf((beta)*(M_PI/180));
    eye(X) = dist * -sinf(alpha*(M_PI/180)) * cosf((beta)*(M_PI/180));

}

void Camara::mover(float x, float y, float z){
    at(0) += x*20;
    at(1) += y*20;
    at(2) += z*20;

    eye(0) += x*20;
    eye(1) += y*20;
    eye(2) += z*20;

    this->dist =sqrt(eye[X]*eye[X]+eye[Z]*eye[Z]+eye[Y]*eye[Y]);
    this->alpha=-atan(eye[X]/eye[Z])*(180/M_PI);
    this->beta=-atan(sqrt(eye[X]*eye[X]+eye[Y]*eye[Y])/eye[Z])*(180/M_PI);
}
void Camara::zoom ( float factor ){
    this->factor += factor;
}

void Camara::setObserver(){ // completar
    gluLookAt(  eye[X], eye[Y], eye[Z],
                 at[X], at[Y], at[Z],
                 up[X], up[Y], up[Z]);
} 

void Camara::updateVisualizationVolume(float width, float height){

    float aux_widht = width/10;
    float aux_height = height/10;

    float ratioxy = float(aux_height)/float(aux_widht); // xy
    float ratioyx = float(aux_widht)/float(aux_height); // yx


    this->left = -aux_height*ratioyx*factor;
    this->right = aux_height*ratioyx*factor;
    this->bottom = -aux_widht*ratioxy*factor;
    this->top = aux_widht*ratioxy*factor;


    // std::cout << "RATIO XY: " << ratioxy << "RATIO YX: " << ratioyx << std::endl;
    // std::cout << "aux_height: " << aux_height << "aux_widht: " << aux_widht << std::endl;
}

void Camara::setProyeccion (){   
    if(tipo == 0){ // Tipo 0 = perspectiva
        // std::cout << "FRUSTUM" << std::endl;
        glFrustum(left*factor, right*factor, 
                bottom*factor, top*factor, 
                near, far);
    }
    else if (tipo == 1) { // Tipo 1 = ortogonal
        // glMatrixMode( GL_PROJECTION );
        // glLoadIdentity();
        // std::cout << "ORTHO" << std::endl;
        glOrtho(left*factor*3, right*factor*3, 
                bottom*factor*3, top*factor*3, 
                near, far);
    }
}