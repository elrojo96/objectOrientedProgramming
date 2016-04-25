/*
   A01113049 - Luis Alfonso Rojo Sánchez
   Fecha: 28 de Agosto del 2015
   Actividad en clase
   Crear e implmentar "CuentaBanco.h" en el archivo principal.
*/

#include <string>
#include <iostream>
#include "CompactDisc.h"
#include "CuentaBanco.h"

using namespace std;

CompactDisc cdInventory[10]; //Usa constructor vacio (instancias sin valor inicial)

int main(){
   CompactDisc myDisc("Bob Dylan's Greatest Hits", "Bob Dylan",2000, 5.99f, 20);
   CompactDisc *secondCD = new CompactDisc("Songs Of Innocence (2 CD; Deluxe Edition)", "U2", 2014, 13.30,60);
   cout << "Artista: " << myDisc.getArtista() << endl;
   cout << "Titulo: " << myDisc.getTitulo() << endl;
   cout << "Anio: " << myDisc.getAnio() << endl;
   cout << "Precio: " << myDisc.getPrecio() << endl;

   cout << "\nDisco #2"<<endl;
   cout << "Artista: " << secondCD->getArtista() << endl;
   cout << "Titulo: " << secondCD->getTitulo() << endl;
   cout << "Anio: " << secondCD->getAnio() << endl;
   cout << "Precio: " << secondCD->getPrecio() << endl;

   cdInventory[0].setArtista("James Taylor");
   cdInventory[0].setTitulo("Before This World");
   cdInventory[0].setAnio(2015);
   cdInventory[0].setPrecio(8.85);

   cout << "\nDisco de JTaylor" << endl;
   cout << "Artista: " << cdInventory[0].getArtista() << endl;
   cout << "Titulo: " << cdInventory[0].getTitulo() << endl;
   cout << "Anio: " << cdInventory[0].getAnio() << endl;
   cout << "Precio: " << cdInventory[0].getPrecio() << endl;

   cout << "\nImprime de nuevo myDisc"<< endl;
   myDisc.output( cout );

}
