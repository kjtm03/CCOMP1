#include "Posicion.h"
#include <windows.h>

void Posicion::coordenadas(int x, int y)
{
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos_cursor;
    pos_cursor.X = x;
    pos_cursor.Y = y;
    SetConsoleCursorPosition(identi,pos_cursor);
}
