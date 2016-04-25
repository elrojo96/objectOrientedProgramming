/*
    Tarea: Turtle Graphics

    main.cpp

    Integrantes:
    A01113049 - Luis Alfonso Rojo Sanchez
    A01088601 - Jorge Arturo Ramirez Reyna
    A00815878 - Ariel Santos

    Fecha: 19 de Noviembre
*/

#include "Turtle.h"
#include <iostream>

using namespace std;

int main()
{
    Turtle turtle("solidGun.txt");
    int instr=0;

    turtle.clearArea() ; //Clear the drawing area

    while (instr != 9)
        instr = turtle.move();

    turtle.printArea();

    //turtle.clearArea() ; //Clear the drawing area

    return 0;
}
