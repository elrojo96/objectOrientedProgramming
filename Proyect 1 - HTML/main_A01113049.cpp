/*
    Luis Alfonso Rojo Sánchez
    A01113049
    Proyecto 01
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream archivoEntrada;
    ofstream archivoSalida;

    string sNombreArchivo;
    string sNombreHTML;
    string sNombreEncabezado;
    string sTemporal;
    string sTemporal2;

    cout << "Escribe el nombre del archivo a leer sin extension: ";
    cin >> sNombreArchivo;

    cout << "Escribe el nombre del archivo a generar sin extension: ";
    cin >> sNombreHTML;

    sNombreArchivo += ".cpp";

    sNombreEncabezado = sNombreHTML;

    sNombreHTML += ".html";

    archivoEntrada.open(sNombreArchivo.c_str());
    archivoSalida.open(sNombreHTML.c_str());

    archivoSalida << "<!DOCTYPE html>" << endl;
    archivoSalida << "<html>" << endl;
    archivoSalida << "<head>" << endl;
    archivoSalida << "<title>" << endl;
    archivoSalida << sNombreEncabezado << endl;
    archivoSalida << "</title>" << endl;
    archivoSalida << "</head>" << endl;
    archivoSalida << "<body>" << endl;

    while(archivoEntrada >> sTemporal)
    {
        if(sTemporal == "/**")
        {
            while(archivoEntrada >> sTemporal && sTemporal != "*/")
            {
                getline(archivoEntrada, sTemporal2);

                if(sTemporal == "@progName")
                {
                    archivoSalida << "<h2>" << endl;
                    archivoSalida << sTemporal2 << endl;
                    archivoSalida << "</h2>" << endl;
                }
                else if(sTemporal == "@author")
                {
                    archivoSalida << "<strong> Autor: </strong>" << sTemporal2 << "<br>" << endl;
                }
                else if(sTemporal == "@date")
                {
                    archivoSalida << "<strong> Fecha de elaboracion: </strong>" << sTemporal2 << "<br>" << endl;
                }
                else if(sTemporal == "@funcName")
                {
                    archivoSalida << "<h3>" << endl;
                    archivoSalida << "<hr><br> Funcion: " << sTemporal2<< "<br>" << endl;
                    archivoSalida << "</h3>" << endl;
                }
                else if(sTemporal == "@desc")
                {
                    archivoSalida << "<strong> Descripcion: </strong>" << sTemporal2 << "<br>" << endl;
                }
                else if(sTemporal == "@param")
                {
                    archivoSalida << "<strong> Parametro: </strong>" << sTemporal2 << "<br>" << endl;
                }
                else if(sTemporal == "@return")
                {
                    archivoSalida << "<strong> Valor de retorno: </strong>" << sTemporal2 << "<br>" << endl;
                }
            }
        }
    }

    archivoSalida << "</body>" << endl;
    archivoSalida << "</html>" << endl;

    archivoEntrada.close();
    archivoSalida.close();

    cout << "Listo!, el archivo HTML ha sido generado :)" << endl;

    return 0;
}
