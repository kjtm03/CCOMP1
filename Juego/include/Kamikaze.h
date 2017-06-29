#ifndef KAMIKAZE_H
#define KAMIKAZE_H


class Kamikaze
{
    private:
        int k,l;
    public:
        Kamikaze(int _k, int _l);
        void coordenada2(int i, int j);
        void crear();
        void mover();
        void colision(class Nave &uno);

};

#endif // KAMIKAZE_H
