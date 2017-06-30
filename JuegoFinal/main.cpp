#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <windows.h>
#include <conio.h>
#include "Nave.h"
#include "Kamikaze.h"
#include "Bala.h"
#include "Posicion.h"
#define ESPACIO 32


using namespace std;
Posicion pos;
void Ocultar_cursor(){
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 50;
    cursor.bVisible = false;
    SetConsoleCursorInfo(identi, &cursor);
}

void Limites(){
    for(int i = 2; i<78; i++){ //limites arriba y abajo
        pos.coordenadas(i,3); printf("%c",205);
        pos.coordenadas(i,33); printf("%c",205);
    }

    for(int i =4; i<33; i++){ //limites derecha y izquierda
        pos.coordenadas(2,i); printf("%c",186);
        pos.coordenadas(77,i); printf("%c",186);
    }
    //bordes
    pos.coordenadas(2,3); printf("%c",201);
    pos.coordenadas(2,33); printf("%c",200);
    pos.coordenadas(77,3); printf("%c",187);
    pos.coordenadas(77,33); printf("%c",188);

}
void pausa();
int main()
{
    bool GameOver = true;
    bool temp = false;
    char tecla;

    do
    {
        system("cls");
        cin.clear();
        cout << "Space Arcade" << endl;
        cout << "-------------" << endl << endl;
        cout << "\t1 .- Jugar" << endl;
        cout << "\t2 .- Opciones" << endl;
        cout << "\t3 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";

        cin >> tecla;

		switch(tecla)
		{
			case '1':
				system("cls");
				GameOver = false;
                temp = true;
				pausa();
				break;

			case '2':
				system("cls");
				cout << "En construccion...\n";
				pausa();
				break;

			case '3':
				system("cls");
				temp = true;
				break;

			default:
				system("cls");
				cout << "Opcion no valida.\a\n";
				pausa();
				break;
		}
    }while(temp!=true);

    Nave nave(35,30,3,3);

    list<Kamikaze *> kamikazes;
    list<Kamikaze *>::iterator k;
    for(int i = 0; i<4; i++){
        kamikazes.push_back(new Kamikaze(rand()%70+1, rand()%5+4));
    }

    list <Bala *> balas;
    list <Bala *>::iterator b;
    nave.crear();
    nave.borrar();
    nave.ocultar();

    int puntos = 0;
    while(!GameOver){
        pos.coordenadas(4,2); printf("Puntos %d", puntos);

        //DISPAROS
        if(kbhit())
        {
          char tecla = getch();
          if(tecla == ESPACIO)
            balas.push_back(new Bala(nave.X()+2, nave.Y()-1));
        }
        //DISPAROS NO TRASPASAN
        for(b = balas.begin(); b != balas.end(); b++)
        {
            (*b)->mover();
            if((*b)->fuera()){
                pos.coordenadas((*b)->X(), (*b)->Y()); printf(" ");
                delete(*b);
                b = balas.erase(b);
            }

        }
        for(k = kamikazes.begin(); k != kamikazes.end(); k++)
        {
            (*k)->mover();
            (*k)->choque(nave);
        }
        //COLISION BALAS/kamikazes
        for(k = kamikazes.begin(); k != kamikazes.end(); k++){
            for(b = balas.begin(); b != balas.end(); b++){
                if((*k)->X()+2 == (*b)->X() && ((*k)->Y()+1 == (*b)->Y() || (*k)->Y() == (*b)->Y())){
                //if((*k)->X() == (*b)->X() || (*k)->X()+1 == (*b)->X() || (*k)->X()+2 == (*b)->X() || (*k)->X()+3 == (*b)->X() || (*k)->X()+4 == (*b)->X() || (*k)->X()+5 == (*b)->X() && (*k)->X()+2 == (*b)->X() && ((*k)->Y() == (*b)->Y()-1 || (*k)->Y() == (*b)->Y())){
                //if((*b)->X() >= (*k)->X() && (*b)->X() <= (*k)+5 && ((*k)->Y()+1 == (*b)->Y() || (*k)->Y() == (*b)->Y())){
                    pos.coordenadas((*b)->X(), (*b)->Y()); printf(" ");
                    delete (*b);
                    b = balas.erase(b);

                    kamikazes.push_back(new Kamikaze(rand()%70+1, 4));
                    pos.coordenadas((*k)->X(), (*k)->Y()); printf("     ");
                    delete(*k);
                    k = kamikazes.erase(k);
                    puntos+=2;

                }
            }
        }

    nave.mover();

    nave.VidaCorazones();
    nave.Morir();
    Limites();
    if(nave.V()==0) GameOver = true;
    Sleep(29);
    }
    system("cls");
    pos.coordenadas(35,13);printf("xxxxxxxxxxxxx");
    pos.coordenadas(35,14);printf("xxxxxxxxxxxxx");
    pos.coordenadas(35,15);printf("FIN DEL JUEGO");
    pos.coordenadas(35,16);printf("xxxxxxxxxxxxx");
    pos.coordenadas(35,17);printf("xxxxxxxxxxxxx");
    pos.coordenadas(35,18);printf("             ");
    pos.coordenadas(35,19);printf("             ");
    pos.coordenadas(35,20);printf("             ");
}
void pausa()
{
    cout << "";
    getwchar();
    getwchar();
}
