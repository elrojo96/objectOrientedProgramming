/*
    Fecha: 24 de Agosto del 2015
    Alumno: Luis Alfonso Rojo Sanchez
    Matricula: A01113049
    Tarea #1 - Ejercicio 2
    Descripcion: Programa que toma un archivo y lee matriculas y calificaciones, promediando estas, creando asi un nuevo archivo
    donde coloca la matricula con su respectivo promedio
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	//Se declara la matricula como variable string
	string sMatricula;

	//Se declaran como enteros la calificacion, el promedio, la cantidad y la suma
	int iCalificacion;
	int iPromedio;
	int iCantidad;
	int iSuma;

	//Se declaran los archivos de entrada y de salida
	ifstream entrada;
	ofstream salida;

	//Variable para la cantidad de trabajos que el alumno debio de haber preguntado
	int iTrabajos;
	cout << "(Se supone que tienen que ser 5)" << endl;
    cout << "Hola Profesor!, cuantos trabajos debio de haber entregado el alumno: ";
    cin >> iTrabajos;

	//Se abren los archivos
	entrada.open("calificaciones.txt");
	salida.open("promedios.txt");

	//Se lee mientras no se llegue al final del archivo de entrada
	while(!entrada.eof())
	{
		//Se lee la matricula
		entrada >> sMatricula;

		//Se lee la cantidad de claificaciones que viene registradas
		entrada >> iCantidad;

		//Se pone la suma de las calificaciones en 0
		iSuma = 0;

		//Ciclo para leer cada una de las calificaciones
		for(int i = 1; i <= iCantidad; i++)
		{
			//Se lee una calificacion
			entrada >> iCalificacion;

			//Se suma a las calificaciones previas
			iSuma = iSuma + iCalificacion;
		}

		//Se obtiene el promedio
		iPromedio = iSuma / iTrabajos;

		//Variable para obtene la parte decimal del promedio
		double dDecimal = (iSuma % iTrabajos) * 2;

		//Se escribe la matricula en el archivo
		salida << sMatricula << " ";

		//Se escribe el promedio calculado
		salida << iPromedio << "." << dDecimal << endl;
	}

	//Se cierran los archivos
	entrada.close();
	salida.close();

	//Mensaje de despedida
	cout << "\nListo!, se han obtenido los promedios en un nuevo archivo!\n";

	return 0;
}
