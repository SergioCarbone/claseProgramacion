#include <stdio.h>
#include <stdlib.h>


int compactar(int array[], int size, int indice)
{
    for ( ;indice < size-1; indice++)
        array[indice] = array[indice+1];
    return size - 1;
}

int calcularIndiceMinimo(int array[], int size)
{
    int indice=1;
    int minimo = array[0];
    int indiceMinimo = 0;
    for ( ;indice < size; indice++)
    {
       if(array[indice] < minimo)
       {
           minimo = array[indice];
           indiceMinimo = indice;
       }

    }
    return indiceMinimo;
}

void nadiaSort(int array[], int size,int arrayOrdenado[])
{
    int i;
    int indiceMinimo;
    int sizeInicial = size;
    for(i=0;i<sizeInicial;i++)
    {
        indiceMinimo = calcularIndiceMinimo(array,size);
        arrayOrdenado[i] = array[indiceMinimo];
        size = compactar(array,size,indiceMinimo);
    }
}

int ordenarVector (int num[], int posicion)

{
    int i;
    int cantidad = 6;
    int aux1 = num[0];
    int aux2 = num[1];
    int numero;

    for (i = 0 ; i < cantidad ; i++)
    {
        if (aux2 < aux1)
        {
            numero = aux2;
            aux1 = aux2;
            aux1 = num[posicion +1 ];
            aux2 = num[posicion +1 ];
        }
        else
        {
            aux1 = num[posicion +1];
            aux2 = num[posicion +1];
        }
    }
    return numero;
}

float promedio(int edad[], int cantidad){

    float retornoPromedio;
    int i, suma=0;

    for(i=0;i<cantidad;i++){
        suma=suma+edad[i];
    }
    retornoPromedio=(float)suma/cantidad;

    return retornoPromedio;
}

