/*
    Matrices con Sobrecarga de Operadores

    Integrantes:
    A01113049 - Luis Alfonso Rojo Sanchez
    A01088601 - Jorge Arturo Ramirez Reyna
    A00815878 - Ariel Santos

    Fecha: 19 de Octubre
*/

//Operaciones entre matrices cuadradas: suma, resta, transpuesta, multiplicación
//Sobrecarga de operadores: + - * >> <<
//Constructores con parametros default

const int MAX = 20;

class Matriz {
private:
   int arr[MAX][MAX];
   int n;
public:
   //Las funciones 'friend' pueden acceder directamente a los atributos de la clase
   Matriz(int size);
   Matriz traspuesta();

   friend Matriz operator +(const Matriz& m1, const Matriz& m2);
   friend Matriz operator -(const Matriz& m1, const Matriz& m2);
   friend Matriz operator *(const Matriz& m1, const Matriz& m2);
   friend ostream& operator <<(ostream& outs, const Matriz& matriz);
   friend istream &operator>>( istream  &input, Matriz& matriz);
};

Matriz::Matriz(int size = MAX) {
   n = size;
}

Matriz Matriz::traspuesta(){
   Matriz temp;
   temp.n = n;
   for(int i=0; i<n; i++)
     for(int j=0; j<n; j++)
 	     temp.arr[i][j] = arr[j][i];
   return temp;
}

Matriz operator +(const Matriz& m1, const Matriz& m2){      //SUMA DE MATRICES
   Matriz temp;
   temp.n = m1.n;
   for(int i=0; i<m1.n; i++)
     for(int j=0; j<m1.n; j++)
  	    temp.arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
      return temp;
}

Matriz operator -(const Matriz& m1, const Matriz& m2){      //RESTA DE MATRICES
   Matriz temp;
   temp.n = m1.n;
   for(int i=0; i<m1.n; i++)
     for(int j=0; j<m1.n; j++)
        temp.arr[i][j] = m1.arr[i][j] - m2.arr[i][j];
      return temp;
}

Matriz operator *(const Matriz& m1, const Matriz& m2){      //MULTIPLICACION DE MATRICES
   Matriz temp;
   temp.n = m1.n;
   for(int i=0; i<m1.n; i++)
     for(int j=0; j<m1.n; j++)
        temp.arr[i][j] = m1.arr[i][j] * m2.arr[i][j];
      return temp;
}


//Imprime matriz cuadrada
ostream& operator <<(ostream& outs, const Matriz& matriz) {
   for(int i=0; i<matriz.n; i++) {
      outs << "|  " ;
      for(int j=0; j<matriz.n; j++)
 	    outs << matriz.arr[i][j] << "  ";
      outs << "|" << endl;
   }
}
