#include "Kamikaze.h"
#include "Nave.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

Kamikaze::Kamikaze(int _k, int _l){k = _k; l = _l;}
void Kamikaze::coordenada2(int i, int j)
{
    HANDLE hCon;
    COORD Pos;
    Pos.X = k;
    Pos.Y = l;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,Pos);
}

void Kamikaze::crear()
{
    coordenada2(k,l); printf("%c%c%c%c%c",4,40,207,41,4);
}
void Kamikaze::mover()
{
    coordenada2(k,l);   printf("       ");

    l++;
    if(l>32)
    {
        k = rand()%70+2;
        l = 3;
    }
    crear();
 }
void Kamikaze::colision(class Nave &uno)
{
    if(k >= uno.get_x()-5 && k <= uno.get_x()+4 && l >= uno.get_y() && l <= uno.get_y()+3)
    {
        uno.danio();
        uno.borrar();
        uno.caracter();
        uno.numeroVidas();
        k = rand()%70+2;
        //k= 34;
        l = 3;
    }
}
