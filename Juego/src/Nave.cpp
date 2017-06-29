#include "Nave.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_IZQUIERDA 75
#define TECLA_DERECHA 77
#define ESPACIO 32

Nave::Nave(int _x, int _y,int _vidas){x = _x; y = _y; vidas = _vidas;}
void Nave::coordenada(int x, int y)
{
    HANDLE hCon;
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,Pos);
}
void Nave::borrarCursor()
{
     HANDLE hCon;
     hCon = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_CURSOR_INFO cursor;
     cursor.dwSize = 50;
     cursor.bVisible = false;
     SetConsoleCursorInfo(hCon, &cursor);
}
void Nave::caracter()
{
    coordenada(x,y);printf("  %c",30);
    coordenada(x,y+1);printf("%c%c%c%c%c",30,40,207,41,30);
    coordenada(x,y+2);printf("%c%c%c%c%c",197,200,178,188,197);
}
void Nave::borrar()
{
    coordenada(x-5,y);printf("     ");
    coordenada(x,y);printf("           ");
    coordenada(x,y+1);printf("           ");
    coordenada(x,y+2);printf("      ");
}
void Nave::mover()
{
    if (kbhit())
            {
                char tecla = getch();
                borrar();
                if(tecla == 'a' && x>2)x--;
                if(tecla == 'd' && x+5<78)x++;
                if(tecla == 'w' && y>3)y--;
                if(tecla == 's'&& y+3<33)y++;
                if(tecla == 'e')vidas++;
                if(tecla == TECLA_IZQUIERDA && x>2)x--;
                if(tecla == TECLA_DERECHA && x+5<78)x++;
                if(tecla == TECLA_ARRIBA && y>3)y--;
                if(tecla == TECLA_ABAJO && y+3<33)y++;
                numeroVidas();
                //PlaySound(TEXT("Terran.wav"),NULL,SND_SYNC);
                caracter();
            }
}
void Nave::numeroVidas()
{
    coordenada(2,35);printf("Vidas: ");
    coordenada(8,35);printf("                      ");
    for(int i = 0; i<vidas;i++){
        coordenada(9+i,35); printf("%c",3);
    }
}
void Nave::morir()
{
    if(vidas == 0){
        borrar();
        coordenada(x,y);printf("  xx  ");
        coordenada(x,y+1);printf(" xxxx ");
        coordenada(x,y+2);printf("  xx  ");
        Sleep(350);

        borrar();
        coordenada(x,y);printf("x xx x");
        coordenada(x,y+1);printf(" xxxx ");
        coordenada(x,y+2);printf("x xx x");
        Sleep(350);

        borrar();
        vidas = -1;
        //numeroVidas();
        //caracter();
    }
}
