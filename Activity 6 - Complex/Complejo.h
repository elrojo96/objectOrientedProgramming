#include <iostream>
using namespace std;

class Complejo {
   float a;
   float b; //numero imaginario
public:
   //Las funciones 'friend' pueden acceder directamente a los atributos de la clase
   friend Complejo operator +(const Complejo& c1, const Complejo& c2);
   friend bool operator ==(const Complejo& c1, const Complejo& c2);
   Complejo(){a = b = 0;} //Constructor vacío (sin atributos)
   Complejo(float v1, float v2);
   void add(Complejo c);
   void sub(Complejo c);
   void output(ostream& outs);
};



Complejo::Complejo(float v1, float v2){
   a = v1;
   b = v2;
}

void Complejo::add(Complejo c){
   a = a + c.a;
   b = b + c.b;
}

void Complejo::sub(Complejo c){
   a = a - c.a;
   b = b - c.b;
}

void Complejo::output(ostream& outs){
   outs << a << " + " << b <<"i" << endl;
   }

Complejo operator +(const Complejo& c1, const Complejo& c2) {
   Complejo temp; //Utiliza el constructor sin atributos
   temp.a = c1.a + c2.a;
   temp.b = c1.b + c2.b;
   return temp;
}

bool operator ==(const Complejo& c1, const Complejo& c2) {
   return (c1.a == c2.a) && (c1.b == c2.b);
}
