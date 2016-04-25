/*
    Hangman 1

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

//using namespace std
using namespace std;

//Arreglos a utilizar
string palabras[] = {"sandias", "manzana", "papayas", "melones", "naranja", "durazno", "platano"};
string hangman[] =  {"  O", "  O\n /", "  O\n /|", "  O\n /|\\", "  O\n /|\\ \n  |", "  O\n /|\\ \n  | \n /", "  O\n /|\\ \n  | \n / \\"};

//Main
int main()
{
    //Declaracion de variables
    string xs, palabra, intentadas, seguir;
    int pal=0, pos;
    int intentos, fallos, encontro, encontradas;
    char letra;

    //Inicializacion de variable
    encontradas = 0;

    do
    {
        //Inicializacion de variables
        xs = "XXXXXXX";
        intentadas = "";
        palabra = palabras[pal++];  //Toma la siguiente palabra del arreglo
        encontradas = fallos = 0;

        //Ciclo mientras los fallos y las encontradas sean menores a 7
        while (fallos < 7 && encontradas < 7)
        {
            //Inicializacacion de la variable encontro
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
                //Se incrementa la variable fallos en 1
                fallos++;

                //Salto de linea
                cout << endl;

                //Se imprime el hangman en la posicion -1
                cout << hangman[fallos - 1];

                //Salto de linea
                cout << endl;

            }
            //Si no encontró instancias
            //Mostrar el hangman e incrementar número de fallos
        }

        //Condicion quemuestra que haz perdido
        if(fallos == 7)
        {
            cout << "Lo siento!, haz perdido." << endl;
        }

        //Condicion que muestra que haz ganado
        if(encontradas == 7)
        {
            cout << "Felicidades!, haz ganado." << endl;
        }

        //Se pide y se lee que si quiere jugar de nuevo
        cout << "\nDeseas jugar de nuevo? si/no"<< endl;
        cin >> seguir;
    }
    while(seguir == "si");
    return 0;
}
