#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Nave.h"
#include "Borde.h"
#include "Kamikaze.h"
#include "Bala.h"
#include "list"
#define ESPACIO 32
using namespace std;

void coordenada(int x, int y){
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos_cursor;
    pos_cursor.X = x;
    pos_cursor.Y = y;
    SetConsoleCursorPosition(identi,pos_cursor);
}
void Ocultar_cursor(){
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 50;
    cursor.bVisible = false;
    SetConsoleCursorInfo(identi, &cursor);
}

void borde()
{
    for(int i = 1; i<79 ; i++){
        coordenada(i,2);printf("%c",205);//primera barra horizontal
        coordenada(i,33);printf("%c",205);//segunda barra horizontal
    }
    for(int j = 3; j<33 ; j++){
        coordenada(1,j);printf("%c",186);//primera barra vertical
        coordenada(78,j);printf("%c",186);//segunda barra vertical
    }
    coordenada(1,2);printf("%c",201);
    coordenada(78,2);printf("%c",187);
    coordenada(1,33);printf("%c",200);
    coordenada(78,33);printf("%c",188);
}


int main()
{
    list <Bala*> balas;
    list <Bala*>::iterator iterador;

    Borde limite(0,0);
    borde();
    Nave uno(37,30,6);
    uno.caracter();
    uno.borrar();
    uno.borrarCursor();
    uno.numeroVidas();
    Kamikaze kamikaze(10,10),kamikaze1(10,10);
    //bool game_over = true;
    bool game_over = false;
    while(!game_over){

       if (kbhit())
        {
            char tecla = getch();
            if(tecla == ESPACIO)
                balas.push_back(new Bala(uno.get_x()+2,uno.get_y()-1));
        }
        for(iterador = balas.begin();iterador != balas.end();iterador++)
        {
            (*iterador)->mover();
        }

        kamikaze.mover(); kamikaze.colision(uno);
        kamikaze1.mover(); kamikaze1.colision(uno);
        uno.morir();
        uno.mover();
        if(uno.get_vidas()==-1) {
                game_over = true;
                printf("Game Over!");
                //system("pause");
        }
        Sleep(30);
    }
}
