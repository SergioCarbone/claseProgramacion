#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 100

#include "Practica_29.03.h"

int main()
{
    int v[CANTIDAD],i =0, aux, opcion, max, min;
    float promedio;
    char seguir = 's';


    do
    {
        printf("Ingrese la edad: ");
        scanf("%d", &aux);

        while( aux < 0 || aux > 100)
        {
            printf("Error. Ingrese la edad :");
            scanf("%d", &aux);
        }

        v[i] = aux;
        i++;
        printf("Desea Continuar: S/N ");
        fflush(stdin); // Borra los enter y toma el caracter
        scanf("%c", &seguir);

    }
    while( seguir == 's');

    do
    {
    printf("Opcion 1 - Calcular el promedio: \n");
    printf("Opcion 2 - Calcular la edad maxima: \n");
    printf("Opcion 3 - Calcular la edad minima: \n");
    printf("Opcion 4 - Salir \n");

    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        promedio = prom (v, i );
        printf("El promedio de las edades ingresadas es: %2.f \n", promedio);
        break;

    case 2:
        max = maximo(v,i);
        printf("La maxima edad ingresada es: %d \n", max);
        break;

    case 3:
        min = minimo(v,i);
        printf("La minima edad ingresada es: %d \n", min);
        break;
    }

    }while ( opcion > 0 && opcion < 4);

    return 0;
}
