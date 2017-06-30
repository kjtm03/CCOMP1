#JuegoFinal

## Introduction

Juego de naves, en el que tienes que destruir a una horda de naves kamikazes que intentaran destruirte.

## Code Samples

void Limites(){
    for(int i = 2; i<78; i++){ //limites arriba y abajo
        pos.coordenadas(i,3); printf("%c",205);
        pos.coordenadas(i,33); printf("%c",205);
    }

    for(int i =4; i<33; i++){ //limites derecha y izquierda
        pos.coordenadas(2,i); printf("%c",186);
        pos.coordenadas(77,i); printf("%c",186);

## Installation

->Ejecutar el juego y divertirse, si puede v: