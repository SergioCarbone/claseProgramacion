#include <stdio.h>
#include <stdlib.h>


int main()
{
    float num, max, min, promedio, suma = 0;
    int i;

    for( i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%f", &num);
        suma = suma + num;

        if( num > max || i == 1)
        {
            max = num;
        }
        if( num < min || i == 1)
        {
            min = num;
        }
    }
    promedio = suma / 5;

    printf("El promedio es: %.2f", promedio);
    printf("\nEl numero mayor: %.2f y el numero menor: %.2f", max,min);

    return 0;
}
/*
    float num, max, min, promedio, suma;
    int i;

    printf("Ingrese un numero: ");
    scanf("%f", &num);
    max = num;
    min = num;
    suma = num;

    for( i=0; i<4; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%f", &num);
        suma = suma + num;

        if( num > max )
        {
            max = num;
        }
        if( num < min )
        {
            min = num;
        }
    }
    promedio = suma / 5;

    printf("El promedio es: %.2f", promedio);
    printf("\nEl numero mayor: %.2f y el numero menor: %.2f", max,min);

    */

