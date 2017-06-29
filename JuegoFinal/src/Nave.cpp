#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Nave.h"
#define ARRIBA 72

#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
using namespace std;

Nave::Nave(int _x,int _y,int _corazones,int _vidas)
{
    x = _x;
    y = _y;
    corazones = _corazones;
    vidas = _vidas;
}
void Nave::coordenada(int x, int y)
{
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos_cursor;
    pos_cursor.X = x;
    pos_cursor.Y = y;

    SetConsoleCursorPosition(identi,pos_cursor);
}
void Nave::ocultar()
{
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 50;
    cursor.bVisible = false;

    SetConsoleCursorInfo(identi, &cursor);
}
void Nave::crear(){
    coordenada(x,y);printf("  %c",30);
    coordenada(x,y+1);printf("%c%c%c%c%c",30,40,207,41,30);
    coordenada(x,y+2);printf("%c%c%c%c%c",197,200,178,188,197);
}
void Nave::borrar(){
    coordenada(x,y);  printf("         ");
    coordenada(x,y+1);printf("         ");
    coordenada(x,y+2);printf("         ");
}
void Nave::mover(){
    if(kbhit()){
        char tecla = getch();
        borrar();
        if(tecla == 'a' && x>2)x--;
        if(tecla == 'd' && x+5<78)x++;
        if(tecla == 'w' && y>3)y--;
        if(tecla == 's'&& y+3<33)y++;

        if(tecla== IZQUIERDA && x>3)x--;
        if(tecla== DERECHA && x+6 <78)x++;
        if(tecla== ARRIBA && y>4)y--;
        if(tecla==ABAJO && y+3 <33)y++;
        if(tecla=='e')corazones--;//bajar coras
        crear();
        VidaCorazones();
    }
}
void Nave::VidaCorazones(){
    coordenada(50,2); printf("Vidas: %d",vidas);
    coordenada(64,2); printf("Salud: ");
    coordenada(70,2); printf("       ");
    for(int i = 0; i<corazones; i++){
        coordenada(70+i,2);printf("%c",3);
    }
}
void Nave::Morir(){
    if(corazones==0){
        borrar();
        coordenada(x,y);   printf("   **    ");//EXPLOCIONES
        coordenada(x,y+1); printf("  ****   ");
        coordenada(x,y+2); printf("   **    ");
        Sleep(350);

        borrar();
        coordenada(x,y);   printf(" * ** * ");//EXPLOCIONES 2
        coordenada(x,y+1); printf("  ****  ");
        coordenada(x,y+2); printf(" * ** * ");
        Sleep(350);

        borrar();
        vidas--;
        crear();
        corazones = 3;
        VidaCorazones();

    }
}

