#ifndef ASTEROIDE_H
#define ASTEROIDE_H



class Asteroide//:public Nave
{
        int x,y;

    public:
        Asteroide(int,int);
        void coordenada(int,int);
        void crear();
        void mover();
        void choque(class Nave &nave);
        int X() {return x;}
        int Y() {return y;}
        ~Asteroide();


};

#endif // ASTEROIDE_H
