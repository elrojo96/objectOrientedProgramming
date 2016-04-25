/*
    Proyecto Final: SimuladorCPU

    Nombre: Luis Alfonso Rojo Sánchez
    
    Matrícula: A01113049
    
    main.cpp

    Descripción del programa: El SimluadorCPU se encarga de transformar código de ensamble en código 
    máquina y simular un CPU llevando acabo las operaciónes que el código indica.

    Descripción: Clase CPU que toma el código máquina e interpreta las instrucciones llevando a cabo la
    simulación de un CPU (Central Processing Unit).

    Fecha de entrega: 3 de Diciembre

*/

#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

//La clase CPU
class CPU
{
//Declaración de variables privadas
private:
    //Variable string para simular la memoria de la computadora
    string sArregloMemoria[30];
    //Variable string para simular el Instruction Register
    string sIR;
    //Variable int para simular el Accumulator
    int iAC;
    //Variable int para simular el Program Counter
    int iPC;
    //Función void para desplegar los resultados
    void desplegaResultados();
    //Función void para formatear los registros
    void formateaRegistros();
    //Función void para esperar que el usuario teclee enter para continuar
    void pressEnterToContinue();
    //Función int para convertir de string a int
    int stringToInt(string str);
//Declaración de variables públicas
public:
    //Declaración del contructor CPU
    CPU();
    //Función void que interpreta el código máquina y realiza las operaciones indicadas
    void interpreta(string nombre);
};

//Declaración del contructor CPU
CPU :: CPU()
{
    //Ciclo for que le da a los primeros 20 registros el texto de "-1"
    for(int i = 0; i < 20; i++)
    {
        //Elemento del arreglo es igualado a "-1"
        sArregloMemoria[i] = "-1";
    }
    //Ciclo for que le da los últimos 10 registros el texto de "0"
    for(int i = 20; i < 30; i++)
    {
        //Elemento del arreglo es igualado a "0"
        sArregloMemoria[i] = "0";
    }
    //Variable que simula al Instruction Register es igualada a "-1"
    sIR = "-1";
    //Variable que simula al Accumulator es igualada a 0
    iAC = 0;
    //Variable que simula al Program Counter es iguala a 0
    iPC = 0;
}

//Función void para desplegar los resultados
void CPU :: desplegaResultados()
{
    //Se despliegan los valores del Program Counter, Instruction Register y Accumulator
    cout << "PC= " << iPC + 1 << " IR= " << sIR << " AC= " << iAC << endl;
    //Se despliega que será desplegada la data memoria, es decir, los valores de los elementos del arreglo
    cout << "Data Memory" << endl;
    //Ciclo for que despliega los 10 elementos del arreglo
    for(int i = 20; i < 30; i++)
    {
        //Se despliega el valor de cada elemento del arreglo (10)
        cout << i << ": " << sArregloMemoria[i] << endl;
    }
}

//Función void para formatear los registros
void CPU :: formateaRegistros()
{
    //La variable que simula al Instruction register se resetea a "-1"
    sIR = "-1";
    //La variable que simula al Accumulator se resetea a 0
    iAC = 0;
    //La variable que simula al Program Counter se resetea a 0
    iPC = 0;
    //Ciclo for con el que se le da un "-1" a los primero 20 elemetos del arreglo
    for(int i = 0; i < 20; i++)
    {
        //Elemento del arreglo es igualado a "-1"
        sArregloMemoria[i] = "-1";
    }
    //Ciclo for que le da los últimos 10 registros el texto de "0"
    for(int i = 20; i < 30; i++)
    {
        //Elemento del arreglo es igualado a "0"
        sArregloMemoria[i] = "0";
    }
}

//Función void para esperar que el usuario teclee enter para continuar
//Cedo la creación de esta función al siguiente link: http://www.cplusplus.com/forum/articles/7312/
void CPU :: pressEnterToContinue()
{
    //Se depspliega que se presione enter para continuar
    std::cout << "Press ENTER to continue.." << endl;
    //La función espera a que el usuario teclee ENTER
    std::cin.ignore(std::numeric_limits <std::streamsize> :: max(), '\n');
}

//Función int para convertir de string a int
int CPU :: stringToInt(string str)
{
    //Variable int declarada e igualada a 0
    int num = 0;
    //Ciclo for que convierte el string a int
    for(int i = 0; i < str.length(); i++)
    {
        //Conversión de string a int
        num = num * 10 + (str[i] - '0');
    }
    //Regresa el numero
    return num;
}

//Función void que interpreta el código máquina y realiza las operaciones indicadas
void CPU :: interpreta(string nombre)
{
    //Variable para la lectura de archivos
    ifstream iArchivoEntrada;
    //Se abre el archivo de entrada tomando como referencia la varable del archivo de entrada más .obj
    iArchivoEntrada.open((nombre + ".obj").c_str());
    //Variable int x declarada e igualada a 0
    int x = 0;
    //Ciclo while que se realiza mientras el archivo de entrada le pueda dar datos al arreglo que simula la memoria
    while(iArchivoEntrada >> sArregloMemoria[x])
    {
        //Se aumenta la variable x en 1
        x++;
    }
    //Se cierra el archivp de entrada
    iArchivoEntrada.close();
    //Se iguala la variable que simula al Instruction register al elemento del arreglo que simula a la memoria con el valor que indica la variable que simula al Program Counter
    sIR = sArregloMemoria[iPC];
    //Ciclo while que se ejecuta mientras la variable que simula al Instruction Register no sea "-1["
    while(sIR != "-1")
    {
        //Variable int iAuxiliar declarada que es igualada a la funcion que convierte de string a int que tiene como parametros el recorte de la linea del elemento de arreglo que
        //simula a la memoria indicado por la variable que simula al Program Counter que es se le obitene un subtring desde la posición 1 y se obtienen 2 dígitos
        //Esta variable simula la localidad de memoria con la que trabajar
        int iAuxiliar = stringToInt(sArregloMemoria[iPC].substr(1,2));

        //Condición if que evalua que si el mnemonic es igual a 0
        if(sIR[0] == '0'){
            //Se despliega que se teclee un valor
            cout << "Teclea un valor: ";
            //Se lee un valor y almacena en el elemento del arreglo que simula la memoria indicado por la variable iAuxiliar
            cin >> sArregloMemoria[iAuxiliar];
            //Se llama a la función despliega resultados
            desplegaResultados();
            //Se aumenta la variable iPC en 1
            iPC++;
            //La variable que simula al Instruction Register es igualada al valor del elemento indicado por la variable que simula al Program Counter en el arreglo de memoria
            sIR = sArregloMemoria[iPC];
            //Se llama a la función que espera al usuario teclee enter para continuar
            pressEnterToContinue();
        }else if(sIR[0] == '1'){
            //Condición if que evalua que si el mnemonic es igual a 1
            //Se despliega el elemento del arreglo que simula a la memoria indicado por la variable iAuxiliar
            cout << sArregloMemoria[iAuxiliar];
            //Se llama a la función despliega resultados
            desplegaResultados();
            //Se aumenta la variable iPC en 1
            iPC++;
            //Se iguala la variable que simula el Instruction Register al elemento del arreglo de memoria indicado por la variable que simula al Program Counter
            sIR = sArregloMemoria[iPC];
            //Se llama a la función que espera al usuario teclee enter para continuar
            pressEnterToContinue();
        }else if(sIR[0] == '2'){
            //Condición if que evalua que si el mnemonic es igual a 2
            //Se iguala la variable que simula al Accumulator al elemento del arreglo de memoria indicado por la variable iAuxiliar convertido en int con la funcion stringToInt
            iAC = stringToInt(sArregloMemoria[iAuxiliar]);
            //Se llama a la función despliega resultados
            desplegaResultados();
            //Se aumenta la variable iPC en 1
            iPC++;
            //Se iguala la variable que simula el Instruction Register al elemento del arreglo de memoria indicado por la variable que simula al Program Counter
            sIR = sArregloMemoria[iPC];
            //Se llama a la función que espera al usuario teclee enter para continuar
            pressEnterToContinue();
        }else if(sIR[0] == '3'){
            //Condición if que evalua que si el mnemonic es igual a 3
            //Declaración de variable ostringstream oConvert1
            ostringstream oConvert1;
            //oConvert1 se le da el contenido de la variable que simula el Accumulator
            oConvert1 << iAC;
            //El elemento del arreglo indicado por la variable iAuxiliar es igualado a la variable oVariable1 convertida en int
            sArregloMemoria[iAuxiliar] = oConvert1.str();
            //Se llama a la función despliega resultados
            desplegaResultados();
            //Se aumenta la variable iPC en 1
            iPC++;
            //Se iguala la variable que simula el Instruction Register al elemento del arreglo de memoria indicado por la variable que simula al Program Counter
            sIR = sArregloMemoria[iPC];
            //Se llama a la función que espera al usuario teclee enter para continuar
            pressEnterToContinue();
        }else if(sIR[0] == '4'){
            //Condición if que evalua que si el mnemonic es igual a 4
            //La variable que simula al Accumulator es igual a ella misma más el elemento del arreglo indicado por la variable iAuxiliar convertido a int
            iAC = iAC + stringToInt(sArregloMemoria[iAuxiliar]);
            //Se llama a la función despliega resultados
            desplegaResultados();
            //Se aumenta la variable iPC en 1
            iPC++;
            //Se iguala la variable que simula el Instruction Register al elemento del arreglo de memoria indicado por la variable que simula al Program Counter
            sIR = sArregloMemoria[iPC];
            //Se llama a la función que espera al usuario teclee enter para continuar
            pressEnterToContinue();
        }else if(sIR[0] == '5'){
            //Condición if que evalua que si el mnemonic es igual a 5
            //La variable que simula al Accumulator es igual a ella misma menos el elemento del arreglo indicado por la variable iAuxiliar convertido a int
            iAC = iAC - stringToInt(sArregloMemoria[iAuxiliar]);
            //Se llama a la función despliega resultados
            desplegaResultados();
            //Se aumenta la variable iPC en 1
            iPC++;
            //Se iguala la variable que simula el Instruction Register al elemento del arreglo de memoria indicado por la variable que simula al Program Counter
            sIR = sArregloMemoria[iPC];
            //Se llama a la función que espera al usuario teclee enter para continuar
            pressEnterToContinue();
        }else if(sIR[0] == '6'){
            //Condición if que evalua que si el mnemonic es igual a 6
            //La variable que simula al Program Counter es igual a el elemento del arreglo de memoria indicado por la variable iAuxiliar convertido a int
            iPC = stringToInt(sArregloMemoria[iAuxiliar]);
            //Se llama a la función despliega resultados
            desplegaResultados();
            //Se aumenta la variable iPC en 1
            iPC++;
            //Se iguala la variable que simula el Instruction Register al elemento del arreglo de memoria indicado por la variable que simula al Program Counter
            sIR = sArregloMemoria[iPC];
            //Se llama a la función que espera al usuario teclee enter para continuar
            pressEnterToContinue();
        }else if(sIR[0] == '7'){
            //Condición if que evalua que si el mnemonic es igual a 7
            //Se llama a la función despliega resultados
            desplegaResultados();
            //Condicion que evalua si la variable que simula al Accumulator es menor a 0
            if(iAC < 0)
            {
                //La variable que simula al program counter es igual a el elemento del arreglo de la memoria indicado por la variable iAuxiliar convetida a int
                //con la función stringToInt
                iPC = stringToInt(sArregloMemoria[iAuxiliar]);
            }else
            {
                //Si no sucede, se aumenta la variable que simula el Program Counter en 1
                iPC++;
            }
            //Se iguala la variable que simula el Instruction Register al elemento del arreglo de memoria indicado por la variable iAuxiliar
            sIR = sArregloMemoria[iAuxiliar];
            //Se llama a la función que espera al usuario teclee enter para continuar
            pressEnterToContinue();
        }else if(sIR[0] == '8'){
            //Condición if que evalua que si el mnemonic es igual a 8
            //Se llama a la función despliega resultados
            desplegaResultados();
            //Condicion que evalua si la variable que simula al Accumulator es igual a 0
            if(iAC == 0)
            {
                //La variable que simula al program counter es igual a el elemento del arreglo de la memoria indicado por la variable iAuxiliar convetida a int
                //con la función stringToInt
                iPC = stringToInt(sArregloMemoria[iAuxiliar]);
            }else
            {
                //Si no sucede, se aumenta la variable que simula el Program Counter en 1
                iPC++;
            }
            //Se iguala la variable que simula el Instruction Register al elemento del arreglo de memoria indicado por la variable iAuxiliar
            sIR = sArregloMemoria[iAuxiliar];
            //Se llama a la función que espera al usuario teclee enter para continuar
            pressEnterToContinue();
        }else if(sIR[0] = '999'){
            //Condición if que evalua que si el mnemonic es igual a 999
            //Se iguala la variable que simula al Instruction Register a "-1" con el proposito de salir del ciclo while
            //y que el programa finalize
            sIR = "-1";
        }
    }
    //Se llama a la función que formatea los registros
    formateaRegistros();
}

#endif // CPU_H_INCLUDED
