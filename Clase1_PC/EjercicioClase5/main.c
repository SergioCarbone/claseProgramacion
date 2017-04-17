#include <stdio.h>
#include <stdlib.h>
#include "../funciones.h"
#define MAX 5

int main()
{
    float array[MAX], numMax, numMin, suma, promedio;
    int indice, opcion;

    for(indice=0; indice<MAX; indice++)
    {
        array[indice] = getFloat("Ingrese un valor: ");
    }

    do
    {
        opcion = getInt("\n1-Mostrar\n2-Cargar\n3-Salir\nOpcion: ");

        switch(opcion)
        {
        case 1:
            printf("\nIndice:  Valor: \n");
            for(indice=0; indice<MAX; indice++)
            {
                printf(" %d       %.2f   \n", indice, array[indice]);
                suma = suma + array[indice];
                if(numMax < array[indice]|| indice == 0)
                {
                    numMax = array[indice];
                }
                if(numMin > array[indice]|| indice == 0)
                {
                    numMin = array[indice];
                }
            }
            promedio = suma / MAX;
            printf("El maximo es: %.2f\nEl minimo es: %.2f\nEl promedio es: %.2f", numMax,numMin,promedio);
            break;
        case 2:
            indice = getInt("Ingrese el la posicion a modificar: ");
            if(indice >= 0 && indice < MAX)
            {
                array[indice] = getFloat("Ingrese el valor: ");
            }
            else
            {
                printf("Esta fuera del rango: ");
            }
            break;

        }
    }
    while(opcion != 3);


    return 0;
}
/*
int edad[MAX];
   float sueldo[MAX];
   int i, pos;
   char respuesta = 's';

   for(i=0;i<MAX;i++)
   {
       edad[i]=0;
       sueldo[i]=0;
   }

  do
  {
      pos = getInt("Ingrese la posicion que desea cargar: ");
      edad[pos]= getEdad("Ingrese la edad: ");
      sueldo[pos] = getFloat("Ingrese el sueldo: ");
      respuesta = getChar("\nDesea continuar: s/n: ");

  }while(respuesta == 's');


   printf("\n_______________________\n");

   for(i=0;i<MAX;i++)
   {

       printf("\nEdad: %d Seldo: %.2f ",edad[i], sueldo[i]);
   }
   */
