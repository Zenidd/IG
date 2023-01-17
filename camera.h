 #include "auxiliar.h"
 #include "tuplasg.h"


class Camara {
    Tupla3f eye;
    Tupla3f at;
    Tupla3f up;
    float left, right, near, far ; // o bien aspect, fov, near, far;
    float top, bottom;
    float alpha, beta;
    const float dist = 200;
    public:
        int tipo ; // ORTOGONAL o Perspectiva
        Camara (Tupla3f eye, Tupla3f at, Tupla3f up, int tipo, float left, 
                float right, float bottom, float top, float near, float far);
        void rotarXExaminar ( float angle );
        void rotarYExaminar ( float angle );
        void rotarZExaminar ( float angle );
        void rotarXFirstPerson ( float angle );
        void rotarYFirstPerson ( float angle );
        void girar (int x, int y);
        void mover ( float x, float y, float z );
        void zoom ( float factor );
        void setObserver (); // completar
        void setProyeccion ();
};