/*
    Practica en pareja #1
    Titulo: Matrices
    Fecha: 13 de Agosto del 2015
    Integrantes:
    A01113049 - Luis Alfonso Rojo Sánchez
    A01088601 - Jorge Arturo Ramirez Reyna
*/

#include <iostream>

using namespace std;

void imprimeMatriz(int iMatriz[3][3], int iNumero)
{
    for(int i = 0; i < iNumero; i++)
    {
        for(int j = 0; j < iNumero; j++)
        {
            cout << iMatriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    //Mensaje de bienvenida
    cout << "Hola!, este programa toma dos matrices y las suma, las resta y las multiplica." << endl;

    //Salto de linea
    cout << endl;

    int iMatrizA[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int iMatrizB[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int iMatrizC[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int iNumero = 3;


    //Se imprimen los valores de la primera matriz
    cout << "Los valores de la primera matriz son: " << endl;
    imprimeMatriz(iMatrizA, iNumero);

    //Salto de linea
    cout << endl;

    //Se imprimen los valores de la segunda matriz
    cout << "Los valores de la segunda matriz son: " << endl;
    imprimeMatriz(iMatrizB, iNumero);

    //Salto de linea
    cout << endl;

    //Suma de matrices A + B
    for(int i = 0; i < iNumero; i++)
    {
        for(int j = 0; j < iNumero; j++)
        {
            iMatrizC[i][j] = iMatrizA[i][j] + iMatrizB[i][j];
        }
    }

    //Se imprime la matriz de la suma
    cout << "El resultado de la suma de las matrices es: " << endl;
    imprimeMatriz(iMatrizC, iNumero);

    //Salto de linea
    cout << endl;

    //Resta de matrices A - B
    for(int i = 0; i < iNumero; i++)
    {
    for(int j = 0; j < iNumero; j++)
        {
            iMatrizC[i][j] = iMatrizA[i][j] - iMatrizB[i][j];
        }
    }

    //Se imprime la matriz de la resta
    cout << "El resultado de la resta de las matrices es: " << endl;
    imprimeMatriz(iMatrizC, iNumero);

    //Salto de linea
    cout << endl;

    //Multiplicacion de matrices A * B
    for(int c = 0; c < iNumero; c++)
    {
        for(int b = 0; b < iNumero; b++)
        {
            for(int a = 0; a < iNumero; a++)
            {
                iMatrizC[c][b] += iMatrizA[c][a] * iMatrizB[a][b];
            }
        }
    }

    //Se imprime la matriz de la resta
    cout << "El resultado de la multiplicacion de las matrices es: " << endl;
    imprimeMatriz(iMatrizC, iNumero);

    return 0;
}
