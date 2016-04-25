/*
    Matrices con Sobrecarga de Operadores

    Integrantes:
    A01113049 - Luis Alfonso Rojo Sanchez
    A01088601 - Jorge Arturo Ramirez Reyna
    A00815878 - Ariel Santos

    Fecha: 19 de Octubre
*/

//Operaciones entre matrices cuadradas A y B: suma, resta, transpuesta, multiplicación
//Sobrecarga de operadores: + - * >> <<
//Constructores con parametros default

#include <iostream>
#include <fstream>
using namespace std;

#include "Matriz.h"

int main() {
   ifstream inputFile;
   ofstream outputFile;

   Matriz A;
   Matriz B(20);
   Matriz C(15);

   inputFile.open("matrices.txt");
   outputFile.open("resultado.txt");

   inputFile >> A;
   inputFile >> B;

   outputFile << "Matriz A" << endl;
   outputFile << A;

   outputFile << "Matriz B" << endl;
   outputFile << B;

   C = A + B;
   outputFile << "Resultado de la suma de matrices cuadradas A+B" << endl;
   outputFile << C;

   C = B - A;
   outputFile << "Resultado de la resta de matrices cuadradas B-A" << endl;
   outputFile << C ;

   C = A.traspuesta();
   outputFile << "Resultado de la matriz transpuesta de A" << endl;
   outputFile << C ;

   C = A * B;
   outputFile << "Resultado de la multiplicacion de matrices cuadradas A*B" << endl;
   outputFile << C ;

   inputFile.close();
   outputFile.close();

   /*
      Demostrar que:
         A(B+C) = AB + AC
         (A+B)C = AC + BC
         (AB)t= Bt * At
         AI = IA = A
   */

   cout << A * (B + C) << endl;
   cout << (A + B) * C << endl;
   /*cout << (A * B) * t << " = " <<  At << endl;
   cout << AI << " = " << IA <<  " " << A << endl;*/

   return 0;
}
