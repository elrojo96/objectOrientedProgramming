    /*
        Actividad: Conteo de caracteres - Ejercicio 1

        Fecha: 26 de Agosto de 2015

        Integrantes:
        A01113049 - Luis Alfonso Rojo Sánchez
        A00818019 - Candy Torres Flores
    */

#include <string>
#include <iostream>
#include <map>

using namespace std;

string myStr("Luis  Alfonso Rojo   Sanchez");
string minusculas("abcdefghijklmnopqrstuvwxyz");
string mayusculas("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
int conteoLetras[32];
//Mapa para obtene las letras y cantidad de letras que fueron usadas
map <char, int> miMapa;

//Borra espacios duplicados y no-letras, cambia mayusculas por minusculas
void preparaString(string &inStr)
{
   int i=0;
   int pos;
   char letra;
   while( i < inStr.length() ) {
      letra = inStr[i];
      pos = minusculas.find(letra);
      if (pos == -1){ //No es una minuscula
         if (letra == ' ') { //Si es un espacio
            while( inStr[i+1] == ' ') //Borrar ese espacio adicional y los que le sigan
               inStr.erase(i+1,1);
            i++;
         } else {//Sera una mayuscula?
            pos = mayusculas.find(letra);
            if ( pos != -1){ //Es una mayuscula
               inStr[i] = minusculas[pos]; //Sustuirla por una minuscula
               i++;
             } else //Si no es minuscula ni mayuscula entonces es un no-letra, borrarlo
                 inStr.erase(i, 1);
         }
     } else i++; //Era una una letra minuscula, ir al siguiente caracter
   }
}

void cuentaCaracteres(string inStr)
{
    //Ciclo que termina hasta que termina la cantidad de caracteres
    for(int i = 0; i < inStr.length(); i++)
    {
        //Condicionamiento para que no se realize si el caracter a comparar es un espacio
        if(inStr[i] != ' ')
        {
            //Se compara si no ha habido ese valor en el mapa
            if(miMapa[inStr[i]] == NULL)
            {
                //Como no ha estado ese valor en el mapa, se le da el valor de 1 en ese lugar
                miMapa[inStr[i]] = 1;
            }
            else
            {
                //Como ya ha estado ese valor, se le agrega 1
                miMapa[inStr[i]]++;
            }
        }
    }
}

void imprimeCuenta()
{
    //Se crea un iterador para poder imprimir el mapa
    map <char, int> :: iterator it;

    //Se menciona lo que se va a imprimir
    cout << "Letra - Cantidad" << endl;

    //Ciclo que dura desde donde comienza hasta donde termina el mapa
    for(it = miMapa.begin(); it != miMapa.end(); it++)
    {
        //Se imprime la letra y la cantidad de veces que aparece en la frase
        cout << it -> first << " - " << it -> second << endl;
    }
}

int cuentaPalabras(string inStr)
{
    //Se inicializa la variable para obtener la cantidad de espacios
    int iCantidadPalabras = 0;

    //Ciclo for que dura hasta que se acaba la longitud de la frase
    for(int i = 0; i < inStr.length(); i++)
    {
        //Condicion que compara el elemento de la frase con el caracterer espacio
        if(inStr[i] == ' ')
        {
            //Se le suma 1 a la variable
            iCantidadPalabras++;
        }
    }
    //Se le suma 1 a la variable para obtener la cantidad de palabras
    iCantidadPalabras++;

    return iCantidadPalabras;
}

int main()
{
   cout << "String de entrada: " << myStr<< endl;
   preparaString(myStr);
   cout << "String modificado: " << myStr << endl;

   cout << cuentaPalabras(myStr) << " palabras" << endl;
   cuentaCaracteres(myStr);
   imprimeCuenta();
   return 0;
}
