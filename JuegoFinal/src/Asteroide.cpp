#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Nave.h"
#include "Asteroide.h"
#include <stdlib.h>
using namespace std;

Asteroide::Asteroide(int _x, int _y)
{
   x = _x;
   y = _y;
}
void Asteroide::coordenada(int x, int y)
{
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos_cursor;
    pos_cursor.X = x;
    pos_cursor.Y = y;

    SetConsoleCursorPosition(identi,pos_cursor);
}

void Asteroide::crear()
{
   coordenada(x,y); printf("%c",2);
}
void Asteroide::mover()
{
    coordenada(x,y); printf(" ");
    y++;
    if(y>32){
        x = rand()%71+4;
        y = 4;
    }
    crear();
}
void Asteroide::choque(Nave &nave)
{
    if(x >= nave.X() && x <= nave.X()+8 && y >= nave.Y() && y <= nave.Y()+2)
    {
        nave.BajarCorazones();
        nave.borrar();
        nave.crear();
        nave.VidaCorazones();
        x = rand()%71+4;
        y = 4;
    }
}

Asteroide::~Asteroide()
{

}
