/*
    Hangman 3

    Integrantes:
    A01113049 - Luis Alfonso Rojo Sanchez
    A01088601 - Jorge Arturo Ramirez Reyna
    A00815878 - Ariel Santos

    Fecha: 28 de Septiembre
*/

//Bibliotecas a usa
#include <string>   //Parra trabajar con strings
#include <cstdlib>  // Para numeros random
#include <ctime>    //Para acceder a Time
#include <iostream> //Para que funcione el programa
#include <fstream>  //Biblioteca para trabajar con archivos

//using namespace std
using namespace std;

//Funcion que obtiene ahora palabras diferentes del archivo de texto
void vObtenedorPalabras(string sArregloPalabras[100], int &iTemporal)
{
    //Declaracion de variable para leer el archivo
    ifstream iArchivoEntrada;

    //Se abre el archivo
    iArchivoEntrada.open("palabras.txt");

    //Obtener palabras
    while(!iArchivoEntrada.eof())
    {
        iArchivoEntrada >> sArregloPalabras[iTemporal];

        //Se incrementa la variable temporal en 1
        iTemporal++;
    }

    //Cerrar el archivo
    iArchivoEntrada.close();
}

//String hangman que se imprime
string hangman[] =  {"  O", "  O\n /", "  O\n /|", "  O\n /|\\", "  O\n /|\\ \n  |", "  O\n /|\\ \n  | \n /", "  O\n /|\\ \n  | \n / \\"};

//Main
int main()
{
    //Funcion srand
    srand (time(NULL));

    //Declaracion de variables contador y temporal
    int iContador = 0;
    int iTemporal = 0;

    //Declaracion de arreglo string de palabras
    string sArregloPalabras[100];

    //Llamada a la funcion que obtiene las palabras del archivo de texto
    vObtenedorPalabras(sArregloPalabras, iTemporal);

    //Declaracion de variables originales
    string xs, palabra, intentadas, seguir;
    int pal=0, pos;
    int intentos, fallos, encontro, encontradas;
    char letra;

    //Inicializacion de variables encontradas
    encontradas = 0;

    //Ciclo do while que se realiza mientras el usuario teclee si
    do
    {
        //Inicizalizacion de variables
        xs = "";
        intentadas = "";
        palabra = sArregloPalabras[rand() % iTemporal];  //Toma la siguiente palabra del arreglo
        encontradas = fallos = 0;

        //Ciclo for que copia las x's a al string xs
        for(int i = 0; i < palabra.length(); i++)
        {
            xs += 'X';
        }

        //Ciclo while que se realiza mientras fallos sea menor a 7 y encontradas sea menor a la longitud de palabra
        while (fallos < 7 && encontradas < palabra.length())
        {
            //Inicializacion de la variable encontro
            encontro = 0;

            //Se pide y se lee una letra
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
                //Se incrementa fallos en 1
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

        //Se imprime que se ha perdido
        if(fallos == 7)
        {
            cout << "Lo siento!, haz perdido." << endl;
        }
        if(encontradas == 7) //Sie imprime que se ha ganado
        {
            cout << "Felicidades!, haz ganado." << endl;

            //Se incrementa la variable contador en 1
            iContador++;
        }

        //Se pide y se lee si se desea continuar
        cout << "\nDeseas jugar de nuevo? si/no"<< endl;
        cin >> seguir;

    }
    while(seguir == "si");
    return 0;
}
