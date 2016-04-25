/*
    Actividad: Conteo de caracteres - Ejercicio 2

    Fecha: 26 de Agosto de 2015

    Integrantes:
    A01113049 - Luis Alfonso Rojo Sánchez
    A00818019 - Candy Torres Flores
*/

#include <iostream>
#include <string>

using namespace std;

//Funcion que reemplaza a los digitos por x's
void checaReemplaza(string &sLineaDeTexto, int iInicio, int iFin)
{
    //Declaracion de variable booleana
    bool bValor = true;

    //Ciclo for para irse desde el principio hasta el final de la palabra
    for(int i = iInicio; bValor && i <= iFin; i++)
    {
        //Comparacion para si el caracter es o no es un numero
        if(!((sLineaDeTexto[i] >= '0') && (sLineaDeTexto[i] <= '9')))
        {
            //La variable toma el valor de falso porque la palabras son puras letras o letras con numeros
            bValor = false;
        }
        else if(i == iFin) //Como la palabra son digitos son puros digitos se cambian por x's
        {
            //Ciclo que cambia todos los digitos por x's
            for(int a = iInicio; a <= iFin; a++)
            {
                //el digito se reemplaza por x
                sLineaDeTexto[a] = 'x';
            }
        }
    }
}

int main()
{
    //Declaracion de variables
    string sLineaDeTexto = "Mi usuarioID es juan17 y mi codigo de 4 digitos es 1234 el cual es secreto.";

    //Se despliega la linea de texto a como está inicialmente
    cout << sLineaDeTexto << endl;

    //Se declaran variables para las posicione
    int iInicio = 0;
    int iFin = 0;

    //Ciclo do while que obtiene las posiciones
    do
    {
        iFin = sLineaDeTexto.find(' ', iInicio) - 1;

        //Se llama a la funcion para formatear digitos por x's
        checaReemplaza(sLineaDeTexto, iInicio, iFin);

        iInicio = iFin + 2;
    }
    while(iFin < (sLineaDeTexto.length() - 1));

    //Salto de linea
    cout << endl;

    //Se despliega la linea de texto modificada
    cout << sLineaDeTexto;

    //Salto de linea
    cout << endl;

    return 0;
}
