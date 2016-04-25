/*
  A01113049 - Luis Alfonso Rojo Sánchez
  Fecha: 28 de Agosto del 2015
  Actividad en clase
  Crear e implmentar "CuentaBanco.h" en el archivo principal.
*/

#include <string>
using namespace std;

class CompactDisc { //Clase
private:
   string titulo;  //Atributo
   string artista;
   int anio;
   float precio;
   int existencia;
public:
   CompactDisc(){} //Constructor vacio
   CompactDisc(string ti, string au, int an, float pre, int ex); //Constructor
   void setTitulo(string tit){ titulo = tit;}  //Metodo modificador
   string getTitulo(){ return titulo;}         //Metodo accesador
   void setArtista(string art){artista = art;}
   string getArtista(){return artista;}
   void setAnio(int an){anio=an;}
   int getAnio(){return anio;}
   void setPrecio(float pre){precio=pre;}
   float getPrecio(){return precio;}
   void setExistencia(int existen){existencia = existen;}
   int getExistencia(){return existencia;}
   void output(ostream& outs){
      outs << "Artista:" << artista << endl;
      outs << "Titulos: "<< titulo << endl;
      outs << "Anio: " << anio << endl;
      outs << "Precio: " << precio<< endl;
   }
};

CompactDisc::CompactDisc(string ti, string ar, int an, float pre, int ex){ //Constructor
       titulo = ti;
       artista = ar;
       anio = an;
       precio = pre;
       existencia=ex;
}
