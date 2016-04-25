/*
	Luis Alfonso Rojo Sánchez
	A01113049
	Fecha: 31 de Agosto de 2015
	Tema: Numero racional
*/

#include <iostream>

using namespace std;

class NumeroRacional
{
private:
	int iNumerador;
	int iDenominador;
public:
	friend NumeroRacional operator +(const NumeroRacional&, const NumeroRacional&);
	friend NumeroRacional operator -(const NumeroRacional&, const NumeroRacional&);
	friend NumeroRacional operator *(const NumeroRacional&, const NumeroRacional&);
	friend NumeroRacional operator /(const NumeroRacional&, const NumeroRacional&);
};

int NumeroRacional operator +(const NumeroRacional& a, const NumeroRacional& b)
{
	NumeroRacional nTemporal;
	nTemporal.iNumerador = ((a.iNumerador * b.iDenominador) + (a.iDenominador * b.iNumerador)) / (a.iDenominador * b.iDenominador);
	return nTemporal;
}

int NumeroRacional operator -(const NumeroRacional& a, const NumeroRacional& b)
{
	NumeroRacional nTemporal;
	nTemporal.iNumerador = ((a.iNumerador * b.iDenominador) - (a.iDenominador * b.iNumerador)) / (a.iDenominador * b.iNumerador);
	return nTemporal;
}

int NumeroRacional operator *(const NumeroRacional& a, const NumeroRacional& b)
{
	NumeroRacional nTemporal;
	nTemporal.iNumerador = ((a.iNumerador * b.iDenominador) / (a.iDenominador * b.iDenominador));
	return nTemporal;
}

int NumeroRacional operator /(const NumeroRacional& a, const NumeroRacional& b)
{
	NumeroRacional nTemporal;
	nTemporal.iNumerador = ((a.iNumerador * b.iDenominador) / (b.iNumerador * a.iDenominador));
	return nTemporal;
}
