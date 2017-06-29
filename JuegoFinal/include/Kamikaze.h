#ifndef Kamikaze_H
#define Kamikaze_H
#include "Posicion.h"


class Kamikaze//:public Posicion
{
        int x,y;

    public:
        Kamikaze(int,int);
        void coordenadas(int,int);
        void crear();
        void mover();
        void choque(class Nave &nave);
        int X() {return x;}
        int Y() {return y;}
        ~Kamikaze(){};


};

#endif // Kamikaze_H
