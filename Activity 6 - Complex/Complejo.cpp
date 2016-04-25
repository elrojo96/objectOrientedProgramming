#include <iostream>
#include "Complejo.h"
using namespace std;

int main(){
   Complejo c1(3,4);
   Complejo c2(1,2);

   c1.add(c2);
   cout << "Resultado de la suma: ";
   c1.output( cout );

   c1.sub(c2);
   cout << "Resultado de la resta: ";
   c1.output( cout );

   Complejo c3 = c1 + c2; //Utiliza operador '+' sobrecargado
   cout << "Resultado de la suma C3: ";
   c3.output( cout );

   c1 = c1 + c2; //Utiliza operador '+' sobrecargado
   cout << "\nComplejo C1: ";
   c1.output( cout );

   cout << "Complejo C3: ";
   c3.output( cout );
   if(c1 == c3 ) //Utiliza operador '==' sobrecargado
      cout << "Si son iguales" << endl;
   else
      cout << "No son iguales" << endl;

   return 0;
}
