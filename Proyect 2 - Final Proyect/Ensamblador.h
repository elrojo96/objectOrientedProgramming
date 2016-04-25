/*
    Proyecto Final: SimuladorCPU

    Nombre: Luis Alfonso Rojo Sánchez
    
    Matrícula: A01113049
    
    main.cpp

    Descripción del programa: El SimluadorCPU se encarga de transformar código de ensamble en código 
    máquina y simular un CPU llevando acabo las operaciónes que el código indica.

    Descripción: Clase Ensamblador que se encarga de tomar el el archivo de texto y transforma el
    código de ensamble en código máquina, que este posteriormente será interpretado por la clase
    CPU.

    Fecha de entrega: 3 de Diciembre

*/

#ifndef ENSAMBLADOR_H_INCLUDED
#define ENSAMBLADOR_H_INCLUDED

//La clase Ensamblador
class Ensamblador
{
    //Declaración de variables privadas
    private:
        //Variable string para el nombre del archivo de entrada
        string sNombreArchivoEntrada;
        //Variable string para el nombre del archivo de salida
        string sNombreArchivoSalida;
    //Declaración de variables públicas
    public:
        //Declaración del contructor Ensamblador
        Ensamblador();

        //Función void para ponerle un nombre al archivo de entrada
        void setNombreArchivoEntrada(string sNombre);
        //Función void para ponerle un nombre al archivo de salida
        void setNombreArchivoSalida(string sNombre);

        //Función string para saber como se llama el archivo de entrada con que estamos trabajando [En este caso no la utilizamos].
        string getNombreArchivoEntrada();
        //Función string para saber como se llama el archivo de salida con que estamos trabajando [En este caso no la utilizamos].
        string getNombreArchivoSalida();

        //Función void que traduce el código de ensamble a código máquina
        void traductorEnsambladorMaquina();
};

//Constructor de la clase Ensamblador
Ensamblador :: Ensamblador()
{
    //Se limpia el nombre del archivo de entrada
    sNombreArchivoEntrada = "";
    //Se limpia el nombre del archivo de salida
    sNombreArchivoSalida = "";
}

//Función void para ponerle un nombre al archivo de entrada 
void Ensamblador :: setNombreArchivoEntrada(string sNombre)
{
    //Igualación de la variable en el main a la variable de la función
    sNombreArchivoEntrada = sNombre;
}

//Función void para ponerle un nombre al archivo de salida
void Ensamblador :: setNombreArchivoSalida(string sNombre)
{
    //Igualación de la variable en el main a la variable de la función
    sNombreArchivoSalida = sNombre;
}

//Función string para saber como se llama el archivo de entrada con que estamos trabajando [En este caso no la utilizamos].
string Ensamblador :: getNombreArchivoEntrada()
{
    //Regresa el nombre del archivo de entrada
    return sNombreArchivoEntrada;
}

//Función string para saber como se llama el archivo de salida con que estamos trabajando [En este caso no la utilizamos].
string Ensamblador :: getNombreArchivoSalida()
{
    //Regresa el nombre del archivo de salida
    return sNombreArchivoSalida;
}

//Función void que traduce el código de ensamble a código máquina
void Ensamblador :: traductorEnsambladorMaquina()
{
    //Variable string que será el mnemonic a trabajar
    string sMnemonic;
    //Variable string que será localidad con la que trabajr
    string sLocalidad;

    //Variable ifstream para la lectura de archivos
    ifstream ifArchivoEntrada;
    //Variable ofsream para la escritura de archivos
    ofstream ofArchivoSalida;

    //Variable tring temporal
    string sTemporal;

    //Se iguala la variable temporal  el nombre del archivo de entrada más .asm
    sTemporal = sNombreArchivoEntrada + ".asm";
    //Se abre el archivo de texto, si no se comunica que no se pudo realizar la tarea
    ifArchivoEntrada.open(sTemporal.c_str());

    //Se iguala la variable temporal  el nombre del archivo de esalida más .obj
    sTemporal = sNombreArchivoSalida + ".obj";
    //Se crea el archivo de texto, si no se comunica que no se pudo realizar la tarea
    ofArchivoSalida.open(sTemporal.c_str());

    //Cilo while que se realiza mientras se pueda estar leyendo del archivo de entrada
    while(getline(ifArchivoEntrada, sTemporal))
    {
        //Variable string stream para la linea con la que se esta trabajando
        stringstream ssLinea;

        //sTemporal le asigna el contenido que posee a ssLinea
        ssLinea << sTemporal;

        //ssLinea reparte el mnemonic y la localidad a las localidades correspondientes
        ssLinea >> sMnemonic >> sLocalidad;

        //Condición que evalua que se encuentre un punto y coma en el mnemonic
        if(sMnemonic.find(";") != -1)
        {
            //Se borra el punto y coma de la variable
            sMnemonic.erase(sMnemonic.length() - 1);
        }

        //Condición que evalua que se encuentre un punto y coma en la localidad
        if(sLocalidad.find(";") != -1)
        {
            //Se borra el punto y coma de la variable
            sLocalidad.erase(sLocalidad.length() - 1);
        }

        //Condicion if que evalua si el mnemonic es igual a "IN"
        if(sMnemonic == "IN"){
            //Se escribe un 0 en el archivo de salida
            ofArchivoSalida << "0";
            //Se escribe la localidad en el archivo de salida
            ofArchivoSalida << sLocalidad << endl;
        }else if(sMnemonic == "OUT"){
            //Condicion if anidada que evalua si el mnemonic es igual a "OUT"
            //Se escribe un 1 en el archivo de salida
            ofArchivoSalida << "1";
            //Se escribe la localidad en el archivo de salida
            ofArchivoSalida << sLocalidad << endl;
        }else if(sMnemonic == "LDA"){
            //Condicion if anidada que evalua si el mnemonic es igual a "LDA"
            //Se escribe un 2 en el archivo de salida
            ofArchivoSalida << "2";
            //Se escribe la localidad en el archivo de salida
            ofArchivoSalida << sLocalidad << endl;
        }else if(sMnemonic == "STA"){
            //Condicion if anidada que evalua si el mnemonic es igual a "STA"
            //Se escribe un 3 en el archivo de salida
            ofArchivoSalida << "3";
            //Se escribe la localidad en el archivo de salida
            ofArchivoSalida << sLocalidad << endl;
        }else if(sMnemonic == "ADD"){
            //Condicion if anidada que evalua si el mnemonic es igual a "ADD"
            //Se escribe un 4 en el archivo de salida
            ofArchivoSalida << "4";
            //Se escribe la localidad en el archivo de salida
            ofArchivoSalida << sLocalidad << endl;
        }else if(sMnemonic == "SUB"){
            //Condicion if anidada que evalua si el mnemonic es igual a "SUB"
            //Se escribe un 5 en el archivo de salida
            ofArchivoSalida << "5";
            //Se escribe la localidad en el archivo de salida
            ofArchivoSalida << sLocalidad << endl;
        }else if(sMnemonic == "JUMP"){
            //Condicion if anidada que evalua si el mnemonic es igual a "JUMP"
            //Se escribe un 6 en el archivo de salida
            ofArchivoSalida << "6";
            //Se escribe la localidad en el archivo de salida
            ofArchivoSalida << sLocalidad << endl;
        }else if(sMnemonic == "BRAN"){
            //Condicion if anidada que evalua si el mnemonic es igual a "BRAN"
            //Se escribe un 7 en el archivo de salida
            ofArchivoSalida << "7";
            //Se escribe la localidad en el archivo de salida
            ofArchivoSalida << sLocalidad << endl;
        }else if(sMnemonic == "BRAZ"){
            //Condicion if anidada que evalua si el mnemonic es igual a "BRAZ"
            //Se escribe un 8 en el archivo de salida
            ofArchivoSalida << "8";
            //Se escribe la localidad en el archivo de salida
            ofArchivoSalida << sLocalidad << endl;
        }else if(sMnemonic == "HALT"){
            //Condicion if anidada que evalua si el mnemonic es igual a "HALT"
            //Se escribe un 999 en el archivo de salida
            ofArchivoSalida << "999" << endl;
        }
    }

    //Se cierra el archivo de entrada
    ifArchivoEntrada.close();
    //Se cierra el archivo de salida
    ofArchivoSalida.close();
}

#endif // ENSAMBLADOR_H_INCLUDED
