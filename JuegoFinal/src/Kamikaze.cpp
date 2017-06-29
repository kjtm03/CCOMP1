#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Nave.h"
#include "Kamikaze.h"
#include <stdlib.h>
using namespace std;

Kamikaze::Kamikaze(int _x, int _y)
{
   x = _x;
   y = _y;
}
void Kamikaze::coordenada(int x, int y)
{
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos_cursor;
    pos_cursor.X = x;
    pos_cursor.Y = y;

    SetConsoleCursorPosition(identi,pos_cursor);
}

void Kamikaze::crear()
{
   coordenada(x,y); printf("%c%c%c%c%c",4,40,207,41,4);
}
void Kamikaze::mover()
{
    coordenada(x,y); printf("     ");
    y++;
    if(y>32){
        x = rand()%70+2;
        y = 3;
    }
    crear();
}
void Kamikaze::choque(Nave &nave)
{
    if(x >= nave.X() && x <= nave.X()+5 && y >= nave.Y() && y <= nave.Y()+2)
    {
        nave.BajarCorazones();
        nave.borrar();
        nave.crear();
        nave.VidaCorazones();
        x = rand()%70+2;
        y = 3;
    }
}

Kamikaze::~Kamikaze()
{

}
