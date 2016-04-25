/*
    Luis Alfonso Rojo Sánchez
    A01113049
    Fecha: 7 de Septiembre del 2015
    Tema: Composición
    Descripción: Agregar la clase Llanta y la clase Transmision al archivo
*/

#include <iostream>

using namespace std;

//Se declara la clase Engine
class Engine
{
//Se definen sus atributos privados
private:
    string type;
//Se definen sus atributos publicos
public:
    Engine(string type)
    {
        this->type = type;
    }

    string getType()
    {
        return type;
    }

    friend ostream& operator << (ostream& out, const Engine &pEngine)
    {
        out << pEngine.type;
        return out;
    }
};

//Se declara la clase Llanta
class Llanta
{
//Se declaran los atributos privados
private:
	string tipo;
	string marca;
//Se declaran los atributos publicos
public:
	Llanta(string tipoB, string marcaB): tipo(tipoB), marca(marcaB){};

	void setTipo(string tip){tipo = tip;}
	string getTipo(){return tipo;}
	void setMarca(string mar){marca = mar;}
	string getMarca(){return marca;}

	friend ostream& operator << (ostream& out, const Llanta &pLlanta)
	{
		out << pLlanta.tipo << " " << pLlanta.marca;
		return out;
	}
};

//Se declara la clase Transmision
class Transmision
{
//Se declaran los atributos privados
private:
	string tipo;
	string potencia;
//Se declaran los atributos publicos
public:
	Transmision(string tipoB, string potenciaB): tipo(tipoB), potencia(potenciaB){};

	void setTipo(string tip){tipo = tip;}
	string getTipo(){return tipo;}
	void setPotencia(string pot){potencia = pot;}
	string getPotencia(){return potencia;}

	friend ostream& operator << (ostream& out, const Transmision &pTransmision)
	{
		out << pTransmision.tipo << " " << pTransmision.potencia;
		return out;
	}
};

//Se declara la clase Car
class Car
{
	//Se definen atributos privados y crean objetos con clases hechas
private:
	string make;
	string model;
	string manufacturer;
	Engine engine;
	Llanta llanta;
	Transmision transmision;
public:
	Car (string p_make, string p_model, string p_manufacturer, const Engine &p_engine, const Llanta &p_llanta, const Transmision &p_transmision):
    make(p_make), model(p_model), manufacturer(p_manufacturer),engine(p_engine), llanta (p_llanta), transmision (p_transmision) {};

    void setMake(string ma){make = ma;}
    string getMake(){return make;}
    void setModel(string mod){model = mod;}
    string getModel(){return model;}
    void setManufacturer(string man){manufacturer = man;}
    string getManufacturer(){return manufacturer;}

    friend ostream& operator <<( ostream& out, const Car &pCar)
    {
    	out << pCar.make << " " << pCar.model << " " << pCar.manufacturer << " " << pCar.engine<< " "<<pCar.llanta<< " "<<pCar.transmision;
    	return out;
    }
};

int main ()
{
    //Se crean automoviles a partir de la clase Car
    Car car1("Mustang", "Convertible", "Ford", Engine("3.5L V5"), Llanta ("207/69/12", "Continental"), Transmision("Semi-Auto", "180 caballos"));
    Car car2("Mustang", "GT Coupe", "Ford", Engine("4.7L V8"), Llanta("215/85/17", "Michelin"), Transmision ("Automatico", "250 caballos"));

    //Se despliega en pantalla los datos de los autmoviles
    cout << car1 << endl;
    cout << car2 << endl;

}
