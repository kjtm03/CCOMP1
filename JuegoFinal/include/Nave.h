#ifndef NAVE_H
#define NAVE_H
#include "Posicion.h"

class Nave:public Posicion
{
    private:
        int x,y;
        int corazones;
        int vidas;

    public:
        Nave(int ,int, int, int);
        int X() {return x;}
        int Y() {return y;}
        int V() {return vidas;}
        void BajarCorazones() {corazones--;}
        void ocultar();
        void crear();
        void borrar();
        void mover();
        void VidaCorazones();
        void Morir();
        ~Nave(){};
};

#endif // NAVE_H
