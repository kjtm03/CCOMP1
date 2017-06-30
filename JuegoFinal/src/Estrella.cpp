/*#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Estrella.h"
#include "Posicion.h"
#define ARRIBA 72

#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
using namespace std;

Estrella::Estrella(int _x, int _y)
{
   x = _x;
   y = _y;
}

void Estrella::crear()
{
    coordenadas(x,y); printf("%c",42);
}
void Estrella::mover()
{
    coordenadas(x,y); printf(" ");
    y++;
    if(y>30){
        x = rand()%30+3;
        y = 10;
    }
    crear();
}
void Estrella::choque(Nave &nave)
{
    if(x >= nave.X()-5 && x <= nave.X()+4 && y >= nave.Y() && y <= nave.Y()+3)
    {

        nave.crear();

    }
}
void Estrella::choque(list<Kamikaze *> &kamikazes)
{
    kamikazes.crear();
}

*/



