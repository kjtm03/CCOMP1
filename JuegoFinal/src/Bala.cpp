#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Nave.h"
#include "Kamikaze.h"
#include "Bala.h"
#include <stdlib.h>
#include <vector>
using namespace std;

Bala::Bala(int _x, int _y)
{
  x = _x;
  y = _y;
}
void Bala::mover()
{
    coordenadas(x,y); printf(" ");
    //if(y>4)
    y--;
    coordenadas(x,y); printf("%c",248);
}
bool Bala::fuera()
{
  if(y == 3)
    return true;
  else
    return false;
}

