/*
	A01113049 - Luis Alfonso Rojo Sánchez
	Fecha: 28 de Agosto del 2015
	Actividad en clase
	Crear e implmentar "CuentaBanco.h" en el archivo principal.
*/

#include <iostream>
#include <string>
using namespace std;

//Clase
class CuentaBanco
{
	private:

		//Atributos
		string numero;
		string nombre;
		string fecha;
		float saldo;

	public:

		CuentaBanco(){} //Constructor vacio
		CuentaBanco(string num, string nom, string fe, float sal); //Constructor

		//Funciones miembro de la clase
		void depositar(float sal){saldo += sal;}
		void extraer(float sal){saldo -= sal;}

		//Metodos modificadores
		void setNumero(string num){numero = num;}
		void setNombre(string nom){nombre = nom;}
		void setFecha(string fe){fecha = fe;}
		void setSaldo(float sal){saldo = sal;}

		//Metodos accesadores
		string getNumero(){return numero;}
		string getNombre(){return nombre;}
		string getFecha(){return fecha;}
		float getSaldo(){return saldo;}

		void output(ostream& outs)
		{
			outs << "Nombre: " << nombre << endl;
			outs << "Numero: " << numero << endl;
			outs << "Saldo: " << saldo << endl;
			outs << "Fecha: " << fecha << endl;
		}
};

CuentaBanco::CuentaBanco(string num, string nom, string fe, float sal)
{
	//Constructor
	numero = num;
	nombre = nom;
	fecha = fe;
	saldo = sal;
}
