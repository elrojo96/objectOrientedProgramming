/*
	Luis Alfonso Rojo Sánchez
	A01113049
	Tarea 2
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "cheque.h"

using namespace std;

int main()
{
	cheque arregloCheques[100];

	ifstream archivoEntrada;
	ofstream archivoSalida;

	int iContador = 0;

	int numeroChequera;
	float cantidadCheque;
	string chequeCobrado;

	float arregloDepositos[100];

	float fSaldoAnterior;

	int iCantidadSi = 0;

	cout << "Cual es el saldo anterior de la cuenta: ";
	cin >> fSaldoAnterior;

	archivoEntrada.open("cheques.txt");

	while(archivoEntrada >> numeroChequera)
	{

		archivoEntrada >> cantidadCheque;
		archivoEntrada >> chequeCobrado;

		arregloCheques[iContador].setNumeroChequera(numeroChequera);
		arregloCheques[iContador].setCantidadCheque(cantidadCheque);

		if(chequeCobrado == "si")
		{
			arregloCheques[iContador].setChequeCobrado(true);
		}else if(chequeCobrado == "no")
		{
			arregloCheques[iContador].setChequeCobrado(false);
		}

		iContador += 1;
	}

	archivoEntrada.close();

	archivoEntrada.open("depositos.txt");

	int iContador2 = 0;

	while(archivoEntrada >> arregloDepositos[iContador2])
	{
		iContador2 += 1;
	}

	archivoEntrada.close();

	float fNuevoSaldo;

	fNuevoSaldo = fSaldoAnterior;

	for(int i = 0; i < iContador2; i++)
	{
		fNuevoSaldo = fNuevoSaldo + arregloDepositos[i];
	}

	for(int i = 0; i < iContador; i++)
	{
		if(arregloCheques[i].getChequeCobrado() == true)
		{
			fNuevoSaldo = fNuevoSaldo - arregloCheques[i].getCantidadCheque();
			iCantidadSi ++;
		}
	}

	archivoSalida.open("chequera.txt");

	archivoSalida << "El balance anterior es: " << fSaldoAnterior << endl;
	archivoSalida << "El balance nuevo es: " << fNuevoSaldo << endl;

	archivoSalida.close();

    cout << endl;

	cout << "El total de los cheques que han sido cobrados: " << iCantidadSi << endl;
	cout << "El total de los depositos realizados: " << iContador2 << endl;
	cout << "El nuevo saldo en la cuenta de cheques: " << fNuevoSaldo << endl;

	cout << endl;

	cout << "La lista de los cheques cobrados es: " << endl;
	for(int i = 0; i < iContador; i++)
	{
		if(arregloCheques[i].getChequeCobrado() == true)
		{
			cout << arregloCheques[i].getCantidadCheque() << endl;
		}
	}

	cout << endl;

	cout << "La lista de los cheques no cobrados es: " << endl;
	for(int i = 0; i < iContador; i++)
	{
		if(arregloCheques[i].getChequeCobrado() == false)
		{
			cout << arregloCheques[i].getCantidadCheque() << endl;
		}
	}

	return 0;
}
