#ifndef NAVE_H
#define NAVE_H


class Nave
{
    private:
        int x, y;
        int vidas;
    public:
        Nave(int _x, int _y, int _vidas);
        void coordenada(int, int);
        void borrarCursor();
        void caracter();
        void borrar();
        void mover();
        void numeroVidas();
        void morir();
        int get_x(){return x;}
        int get_y(){return y;}
        int get_vidas(){return vidas;}
        void danio(){vidas--;}
};

#endif // NAVE_H
