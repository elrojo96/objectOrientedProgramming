/*
    Desviacion estandar

    Integrantes:
    A01113049 - Luis Alfonso Rojo Sanchez
    A01088601 - Jorge Arturo Ramirez Reyna
    A00815878 - Ariel Santos

    Fecha: 5 de Octubre
*/

//Bibliotecas usadas
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>

//using namespace std
using namespace std;

//Main
int main()
{
    //Declaracion de variables
    ifstream iArchivoEntrada;
    string sLinea[28];
    string sArregloNombres[28];
    char cComaTemporal;
    double dArregloCalificaciones[28];

    //Abrir el archivo
    iArchivoEntrada.open("Califs1erParcial.txt");

    //Declaracion de la variable i
    int i = 0;

    //Obtener matriculas y calificaciones
    while(!iArchivoEntrada.eof())
    {
        iArchivoEntrada >> sArregloNombres[i];

        if(sArregloNombres[i][sArregloNombres[i].length()-1] == ',')
        {
            sArregloNombres[i] = sArregloNombres[i].substr(0, 9);
            iArchivoEntrada >> dArregloCalificaciones[i];
        }
        else
        {
            iArchivoEntrada >> cComaTemporal;
            iArchivoEntrada >> dArregloCalificaciones[i];
        }

        i++;
    }

    //Cerrar el archivo
    iArchivoEntrada.close();

    //Calcular media poblacional
    double dMediaPoblacional;
    double dAcumulador;

    for(int i = 0; i < 28; i++)
    {
        dAcumulador += (dArregloCalificaciones[i]);
    }

    dMediaPoblacional = dAcumulador / 28.0;

    //Calcular deviacion estandar
    double dDesviacionEstandar;

    double dAcumulador1[28];
    double dAcumulador2;

    for(int i = 0; i < 28; i++)
    {
        dAcumulador1[i] = ((dArregloCalificaciones[i] - dMediaPoblacional) * (dArregloCalificaciones[i] - dMediaPoblacional));
    }

    for(int i = 0; i < 28; i++)
    {
        dAcumulador2 += dAcumulador1[i];
    }

    dDesviacionEstandar = sqrt((1.0/28.0) * dAcumulador2);

    //Calcular varianza
    double dVarianza;

    dVarianza = pow(dDesviacionEstandar, 2);

    //Se muestran los resultados
    cout << "La media poblacional es: " << dMediaPoblacional << endl;
    cout << "La desviacion estandar es: " << dDesviacionEstandar << endl;
    cout << "La varianza es: " << dVarianza << endl;

    return 0;
}
