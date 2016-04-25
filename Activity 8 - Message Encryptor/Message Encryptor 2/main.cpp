#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//Variable para leer el archivo
	ifstream iArchivoEntrada;

	//Variable para almacenar el contenido del archivo de texto
	string sLineaDeTexto;

	//Variable para la cantidad de caracteres de la variable string
	int iCantidad;

	//Variable para la validación de una respuesta
	char sRespuesta = 'a';

	//Variable para la llave correcta
	int iLlaveCorrecta;

	//Variable que copia el contenido de sLineaTexto y lo resetea
	string sLineaDeTextoCopia;

	//Se abre el archivo
	iArchivoEntrada.open("encriptado.txt");

	//Se le asigna el contenido del archivo de texto a la variable sLinea
	iArchivoEntrada >> sLineaDeTexto;

	//Se cierra el archivo
	iArchivoEntrada.close();

	//Se obtiene la cantidad de caracteres de la linea de texto
	iCantidad = sLineaDeTexto.length();

	//Se iguala sLineaDeTextoCopia a sLineaDeTexto
	sLineaDeTextoCopia = sLineaDeTexto;

	//Ciclo do while que se ejecuta hasta que el usuario teclea 'X' o 'x'
	do{
		//Ciclo for que utriliza como parametro la llave
		for(int iLlave = 1; iLlave <= 100; iLlave++)
		{
			//Se muestra el mensaje encriptado
            cout << "El mensaje encriptado es: " << sLineaDeTexto << endl;

			//Se iguala la llave de la variable correcta a la llave de la variable usada
			iLlaveCorrecta = iLlave;

			//Cilo for que desencripta cada llave
			for(int i = 0; i < iCantidad; i++)
			{
				//Condicion si el caracter es mayor a 32
                if((sLineaDeTexto[i] - 32) >= 32)
                {
                    //El caracter va a ser igual al caracter menos la llave
                    sLineaDeTexto[i] = sLineaDeTexto[i] - iLlave;
                    //Se evalua que el caracter sea menor a 127
                }
                else if(sLineaDeTexto[i] < 127)
                {
                    //El caracter va a ser igual al caracter menos 32 mas 127 menos la llave
                    sLineaDeTexto[i] = ((sLineaDeTexto[i] - 32) + 127) - iLlave;
                }
			}

	        //Se muestra el mensaje ya decodificado
	        cout << "El mensaje desencriptado es: " << sLineaDeTexto << endl;
	        //Se muestra que llave fue usada
	        cout << "La clave usada fue: " << iLlaveCorrecta << endl;
	        //Se muestra al usuario el mensaje de teclear una letra para continuar o salir
	        cout << "Teclee cualquier letra para continuar o 'x' o 'X' para salir: ";
	        //Se lee la respuesta
	        cin >> sRespuesta;

	        //Salto de linea
	        cout << endl;

	        //Se resetea el mensaje ya decodificado al mensaje original
	        sLineaDeTexto = sLineaDeTextoCopia;

        }

	}while(sRespuesta != 'X' && sRespuesta != 'x');

	//Se muestra el valor correcto de la llave
	cout << "El valor correcto de la llave es: " << iLlaveCorrecta << endl;

	return 0;
}
