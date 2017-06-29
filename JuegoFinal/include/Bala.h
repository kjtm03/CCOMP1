#ifndef BALA_H
#define BALA_H


class Bala//:public Nave
{
        int x,y;
public:
    Bala(int,int);
    int X() {return x;}
    int Y() {return y;}
    void mover();
    bool fuera();
    void coordenada(int,int);
    ~Bala();

};

#endif // BALA_H
