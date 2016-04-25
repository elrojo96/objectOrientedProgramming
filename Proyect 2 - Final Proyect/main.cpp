/*
    Proyecto Final: SimuladorCPU

    Nombre: Luis Alfonso Rojo Sánchez

    Matrícula: A01113049

    main.cpp

    Descripción del programa: El SimluadorCPU se encarga de transformar código de ensamble en código
    máquina y simular un CPU llevando acabo las operaciónes que el código indica.

    Descripción: main que permite que el programa funcione correctamente combinando las clases y proporcionando
    a este el nombre del archivo de texto a interpretar

    Fecha de entrega: 3 de Diciembre

*/

//Inlusión de las bibliotecas necesarias
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include <stdlib.h>

//Inclusión de using namespace sts
using namespace std;

//Inclusión de la clase Ensamblador y la clase CPU
#include "Ensamblador.h"
#include "CPU.h"

//main
int main()
{
    //Variable string para el nombre del archivo
    string sNombre;

    //Se despliega que tienes que teclear el "archivo", en el caso del nombre del programa de prueba del proyecto
    cout << "Hola tienes que teclear *archivo* para el caso del programa prueba del proyecto" << endl;
    //Se despliega que tienes que teclear el "archivo", en el caso del nombre del programa de ejemploCreado del proyecto
    cout << "Para el ejemplo creado se puedes teclear primero un numero entero y luego un numero menor a ese" << endl;
    //Se despliega que se teclee el nombre del archivo a leer sin la extensión
    cout << "Teclea el nombre del archivo que contiene el codigo de ensamble [sin extension]: ";
    //Se lee el nombre del archivo a leer
    cin >> sNombre;

    //Se crea un objeto de la clase Ensamblador
    Ensamblador eVariable;

    //Se llama a la función setNombreArchivoEntrada del objeto eVariable pasandole como parametro la variable del nombre del archivo a abrir
    eVariable.setNombreArchivoEntrada(sNombre);
    //Se llama a la función setNombreArchivoSalida del objeto eVariable pasandole como parametro la variable del nombre del archivo a crear
    eVariable.setNombreArchivoSalida(sNombre);

    //Se llama a la función traductorEnsambladorMaquina del objeto eVariable que traduce el código de ensamble en código máquina (y cierra los archivos).
    eVariable.traductorEnsambladorMaquina();

    //Se crea la un objeto de la clase CPU
    CPU cVariable;

    //Se llama a la cunción interpreta parandole como parametro el nombre de la variable del nombre del archivo a crear
    cVariable.interpreta(sNombre);

    return 0;
}
