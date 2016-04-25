/*
	Luis Alfonso Rojo Sánchez
	A01113049
	Fecha: 7 de Septiembre del 2015
	Tema: Composición
	Descripción: Crear la clase robot y como componentes camara, brazo y pierna (con al menos dos atributos)
*/

#include <iostream>
#include <string>

using namespace std;

//Se declara la clase camara
class Camara
{
//Se declaran los atributos privados
private:
	string tipo;
	string tamano;
//Se declaran los atributos publicos
public:
	Camara(string tipoB, string tamanoB): tipo(tipoB), tamano(tamanoB){};

	void setTipo(string tip){tipo = tip;}
	string getTipo(){return tipo;}
	void setTamano(string tam){tamano = tam;}
	string getTamano(){return tamano;}

	friend ostream& operator << (ostream& out, const Camara &pCamara)
	{
		out << pCamara.tipo << " " << pCamara.tamano;
		return out;
	}
};

//Se declara la clase brazo
class Brazo
{
//Se declaran los atributos privados
private:
	string peso;
	string tamano;
//Se declaran los atributos publicos
public:
	Brazo(string pesoB, string tamanoB): peso(pesoB), tamano(tamanoB){};

	void setPeso(string pes){peso = pes;}
	string getPeso(){return peso;}
	void setTamano(string tam){tamano = tam;}
	string getTamano(){return tamano;}

	friend ostream& operator << (ostream& out, const Brazo &pBrazo)
	{
		out << pBrazo.peso << " " << pBrazo.tamano;
		return out;
	}
};

//Se declara la clase pierna
class Pierna
{
//Se declaran los atributos privados
private:
	string peso;
	string largo;
//Se declaran los atributos publicos
public:
	Pierna(string pesoB, string largoB): peso(pesoB), largo(largoB){}

	void setPeso(string pes){peso = pes;}
	string getPeso(){return peso;}
	void setLargo(string lar){largo = lar;}
	string getLargo(){return largo;}

	friend ostream& operator << (ostream& out, const Pierna &pPierna)
	{
		out << pPierna.peso << " " << pPierna.largo;
		return out;
	}
};

//Se define la clase robot
class Robot
{
	//Se definen los atributos privados
private:
	string modelo;
	string proveedor;
	Camara camara;
	Brazo brazo;
	Pierna pierna;

public:
	Robot(string p_modelo, string p_proveedor, const Camara &p_camara, const Brazo &p_brazo, const Pierna &p_pierna):
	modelo(p_modelo), proveedor(p_proveedor), camara(p_camara), brazo(p_brazo), pierna(p_pierna){};

	void setModelo(string mod){modelo = mod;}
	string getModelo(){return modelo;}
	void setProveedor(string prov){proveedor = prov;}
	string getProveedor(){return proveedor;}

	friend ostream& operator << (ostream& out, const Robot &pRobot)
	{
		out << pRobot.modelo << " " << pRobot.proveedor << " " << pRobot.camara << " " << pRobot.brazo << " " << pRobot.pierna;
		return out;
	}
};

int main()
{
	//Se declaran las instancias instancias robot de la clase robot
	Robot robo1("Automatico", "USA", Camara("Inalambrica", "Pequena"), Brazo("10 kg", "7 mts"), Pierna("10 kgs", "16 mts"));
	Robot robo2("Manual", "Colombia", Camara("Alambrica", "Mediana"), Brazo("5 kg", "4 mts"), Pierna("7 kgs", "5 mts"));

	//Se desliegan en pantalla los ejemplos robot de la clase
	cout << robo1 << endl;
	cout << robo2 << endl;
}
