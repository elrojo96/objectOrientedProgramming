#ifndef CHEQUE_H_INCLUDED
#define CHEQUE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class cheque
{
private:
	int numeroChequera;
	float cantidadCheque;
	bool chequeCobrado;
public:
    cheque();
	cheque(int p_numeroChequera, float p_cantidadCheque, bool p_chequeCobrado):numeroChequera(p_numeroChequera), cantidadCheque(p_cantidadCheque), chequeCobrado(p_chequeCobrado) {};

	void setNumeroChequera(int num){numeroChequera = num;}
	int getNumeroChequera(){return numeroChequera;}
	void setCantidadCheque(float cant){cantidadCheque = cant;}
	float getCantidadCheque(){return cantidadCheque;}
	void setChequeCobrado(bool che){chequeCobrado = che;}
	bool getChequeCobrado(){return chequeCobrado;}

	void output(ostream& outs);
	void input(istream& inputs);
};

void cheque::output(ostream& outs)
{
	outs << "Numero de chequera: " << numeroChequera << endl;
	outs << "Cantidad del cheque: " << cantidadCheque << endl;
	outs << "El cheque fue cobrado: " << chequeCobrado << endl;
}

void cheque::input(istream& inputs)
{
	inputs >> numeroChequera;
	inputs >> cantidadCheque;
	inputs >> chequeCobrado;
}

cheque::cheque()
{
    numeroChequera = 0;
	cantidadCheque = 0;
	chequeCobrado = false;
}

#endif // CHEQUE_H_INCLUDED
