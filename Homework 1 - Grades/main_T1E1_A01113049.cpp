/*
    Fecha: 24 de Agosto del 2015
    Alumno: Luis Alfonso Rojo Sanchez
    Matricula: A01113049
    Tarea #1 - Ejercicio 1
    Descripcion: Programa que toma un archivo y coloca comas a los numeros en donde corresponde y los vuelve a escribir en un
    nuevo archivo.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    //Declaracion de variables strings
    string sEntrada;
    string sSalida;
    string sParte;

    //Declaracion de variable de tamano
    int iTamano;

    //Declaracion de variables de archivos
    ifstream entrada;
    ofstream salida;

    //Se abren los arhivos
    entrada.open("numerosViejos.txt");
    salida.open("numerosNuevos.txt");

    //Mientras no se llegue al final del archivo
    while(getline(entrada, sEntrada)) //A quien corresponda, utilize un getline para hacer el codigo mas eficiente
    {
        //Se formatea la variable sSalida
        sSalida = "";

        //Si la longitud de sEntrada es mayor que 3
        if(sEntrada.length() > 3)
        {
            //Mientras la longitud de sentrada sea mayor que 3
            while(sEntrada.length() > 3)
            {
                //Se obtiene el numero de caracteres
                iTamano = sEntrada.length();

                //Se copian los ultimos 3 caracteres de sEntrada al principio de  sSalida
                sParte = sEntrada.substr(iTamano - 3);
                sSalida.insert(0, sParte);

                //Se pone una coma al inicio de la ssalida
                sSalida.insert(0, ",");

                //Se borra los 3 últimos caracteres de sentrada
                sEntrada.erase(iTamano - 3);
            }

            //Se copia los caracteres restantes de sentrada a ssalida
            sSalida.insert(0, sEntrada);
        }
        else
        {
            //Si no es asi, se copia completo sentrada a ssalida
            sSalida.insert(0, sEntrada);
        }

        //Escribir ssalida al archivo de salida
        salida << sSalida << endl;
    }

    //Se cierran los archivos
    entrada.close();
    salida.close();

    //Mensaje de despedida
    cout << "Listo!, a tus numeros se le han colocado comas correctamente!";

    //Salto de linea
    cout << endl;

    return 0;
}
