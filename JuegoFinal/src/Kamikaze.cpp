#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Nave.h"
#include "Kamikaze.h"
#include <stdlib.h>
#include "Posicion.h"
using namespace std;

Kamikaze::Kamikaze(int _x, int _y)
{
   x = _x;
   y = _y;
}

void Kamikaze::crear()
{
   coordenadas(x,y); printf("%c%c%c%c%c",4,40,207,41,4);
}
void Kamikaze::mover()
{
    coordenadas(x,y); printf("     ");
    y++;
    if(y>32){
        x = rand()%70+2;
        y = 3;
    }
    crear();
}
void Kamikaze::choque(Nave &nave)
{
    if(x >= nave.X()-5 && x <= nave.X()+4 && y >= nave.Y() && y <= nave.Y()+3)
    {
        nave.BajarCorazones();
        nave.borrar();
        nave.crear();
        nave.VidaCorazones();
        x = rand()%70+2;
        y = 3;
    }
}

