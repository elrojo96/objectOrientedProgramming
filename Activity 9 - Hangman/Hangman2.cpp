/*
    Hangman 2

    Integrantes:
    A01113049 - Luis Alfonso Rojo Sanchez
    A01088601 - Jorge Arturo Ramirez Reyna
    A00815878 - Ariel Santos

    Fecha: 28 de Septiembre
*/

//Bibliotecas usadas
#include <string>   //Parra trabajar con strings
#include <cstdlib>  // Para numeros random
#include <ctime>    //Para acceder a Time
#include <iostream> //Para que funcione el programa
#include <fstream>  //Biblioteca para trabajar con archivos

//using namespace std
using namespace std;

//Funcion que obtiene las palabras del archivo de texto
void vObtenedorPalabras(string sArregloPalabras[100])
{
    //Se declara el archivo para abrir el archivo
    ifstream iArchivoEntrada;

    //Abrir el archivo
    iArchivoEntrada.open("palabras.txt");

    //Declaracion de variable temporal
    int iTemporal = 0;

    //Se obtienen palabras
    while(!iArchivoEntrada.eof())
    {
        iArchivoEntrada >> sArregloPalabras[iTemporal];
        iTemporal++;
    }

    //Se cierra el archivo
    iArchivoEntrada.close();
}

//String de hangman a utilizar
string hangman[] =  {"  O", "  O\n /", "  O\n /|", "  O\n /|\\", "  O\n /|\\ \n  |", "  O\n /|\\ \n  | \n /", "  O\n /|\\ \n  | \n / \\"};

int main()
{
    //Declaracion de variables
    int iContador = 0;
    string sArregloPalabras[100];

    //Llamada para a la funcion para obtener las palabras
    vObtenedorPalabras(sArregloPalabras);

    //Declaracion de variables
    string xs, palabra, intentadas, seguir;
    int pal=0, pos;
    int intentos, fallos, encontro, encontradas;
    char letra;

    //Inicializacion de variables
    encontradas = 0;

    //Ciclo do while para que el jugador adivine la palabra
    do
    {
        //Inicializacion de variables
        xs = "XXXXXXX";
        intentadas = "";
        palabra = sArregloPalabras[pal++];  //Toma la siguiente palabra del arreglo
        encontradas = fallos = 0;

        //Ciclo do while que se realiza mientras los fallos y las encontradas sean menores a 7
        while (fallos < 7 && encontradas < 7)
        {
            //Inicializacion de variables
            encontro = 0;

            //Pedir una letra
            cout << "Teclea una letra: ";
            cin >> letra;

            //Buscar instancias de la letra en la palabra y para cada una
            //Substituye la X correspondiente en la posición apropiada
            //Substituye la letra en la palabra por un ‘-‘
            //Incrementa contador de letras encontradas
            for(int i = 0; i < palabra.length(); i++)
            {
                if(palabra[i] == letra)
                {
                    xs[i] = letra;
                    palabra[i] = '-';
                    encontradas++;
                    encontro++;
                }
            }

            //Se imprime xs
            cout << xs << endl;

            //Si encontró alguna instancia
            //felicitar
            if(encontro != 0)
            {
                cout << "Felcidades!, haz encontrado una letra." << endl;
            }
            else
            {
                //Se incrementa la variable de fallos en 1
                fallos++;

                //Salto de linea
                cout << endl;

                //Se imprime el hangman en la posicion -1
                cout << hangman[fallos - 1];

                //Salto de linea
                cout << endl;

            }
            //si no encontró instancias
            //Mostrar el hangman e incrementar número de fallos
        }

        //Condicion if que si se cumple se imprime que se ha perdido
        if(fallos == 7)
        {
            cout << "Lo siento!, haz perdido." << endl;
        }

        //Condicion if que si se cumple se imprime que se ha ganado
        if(encontradas == 7)
        {
            cout << "Felicidades!, haz ganado." << endl;
            //Se aumenta la variable contador en 1
            iContador++;
        }

        //Se pide y se lee si se desea jugar de nuevo
        cout << "\nDeseas jugar de nuevo? si/no"<< endl;
        cin >> seguir;

    }
    while(seguir == "si");
    return 0;
}
