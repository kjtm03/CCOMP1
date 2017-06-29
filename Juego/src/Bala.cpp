#include "Bala.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>

Bala::Bala(int _m,int _n){_m = m;_n = n;}

void Bala::coordenada3(int m, int n)
{
    HANDLE hCon;
    COORD Pos;
    Pos.X = m;
    Pos.Y = n;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,Pos);
}
void Bala::mover()
{
    coordenada3(m,n);printf(" ");
    if(n>4)n--;
    coordenada3(m,n);printf("!");
}
