#ifndef Kamikaze_H
#define Kamikaze_H



class Kamikaze//:public Nave
{
        int x,y;

    public:
        Kamikaze(int,int);
        void coordenada(int,int);
        void crear();
        void mover();
        void choque(class Nave &nave);
        int X() {return x;}
        int Y() {return y;}
        ~Kamikaze();


};

#endif // Kamikaze_H
