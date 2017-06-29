#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Nave.h"
#include "Asteroide.h"
#include "Bala.h"
#include <stdlib.h>
#include <vector>
using namespace std;

Bala::Bala(int _x, int _y)
{
  x = _x;
  y = _y;
}
void Bala::coordenada(int x, int y)
{
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos_cursor;
    pos_cursor.X = x;
    pos_cursor.Y = y;

    SetConsoleCursorPosition(identi,pos_cursor);
}
void Bala::mover()
{
    coordenada(x,y); printf("   ");
     if(y>4)y--;
    coordenada(x,y); printf("c");
}
bool Bala::fuera()
{
  if(y==5) return true;
  return false;
}
Bala::~Bala()
{

}
