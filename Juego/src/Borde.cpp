#include "Borde.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>

Borde::Borde(int _i, int _j){i = _i; j = _j;}
void Borde::coordenada1(int i, int j)
{
    HANDLE hCon;
    COORD Pos;
    Pos.X = i;
    Pos.Y = j;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,Pos);
}
void Borde::crearLimites()
{
    for(int i = 1; i<79 ; i++){
        coordenada1(i,2);printf("%c",205);//primera barra horizontal
        coordenada1(i,33);printf("%c",205);//segunda barra horizontal
    }
    for(int j = 3; j<33 ; j++){
        coordenada1(1,j);printf("%c",186);//primera barra vertical
        coordenada1(78,j);printf("%c",186);//segunda barra vertical
    }
    coordenada1(1,2);printf("%c",201);
    coordenada1(78,2);printf("%c",187);
    coordenada1(1,33);printf("%c",200);
    coordenada1(78,33);printf("%c",188);
}
