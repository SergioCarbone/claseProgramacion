#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int main()
{
    float promImp, porcentajePar, porcentajeImp;
    int num, contImp11 = 0, maxPar, minNum, contPar = 0, conImp = 0, acumImp = 0, acumPar = 0, flag = 0, total = 0;
    char respuesta;

    do
    {
        printf("\nIngrese un numero entre 0 y 10.000: ");
        scanf("%d", &num);

        while(num < 0 || num > 10000)
        {
            printf("Esta fuera del rango, reingrese: ");
            scanf("%d", &num);
        }

        if ( num % 2 == 0)
        {
            if (num > maxPar ||contPar == 0)
            {
                maxPar = num;
            }
            contPar++;
            acumPar = acumPar + num;
        }
        else
        {
            if ( num >= 11)
            {
                contImp11++;
            }
            conImp++;
            acumImp = num + acumImp;
        }

        if ( num < minNum || flag == 0)
        {
            minNum = num;
            flag = 1;
        }

        total = total + num;



        printf("Desea continuar? s/n: ");
        respuesta = tolower(getch());

        while(respuesta != 's' && respuesta != 'n')
        {
            printf("\nIngrese respuesta correcta: s/n ");
            respuesta = tolower(getch());
        }


    }
    while( respuesta == 's');
    promImp = (float)acumImp / conImp;
    porcentajePar = (contPar * 100) / (conImp + contPar);
    porcentajeImp = 100 - porcentajePar;

    printf("\nCantidad de numeros pares: %d", contPar);
    printf("\nCantidad de impares >= a 11: %d", contImp11);
    if ( contPar > 0)
    {
        printf("\nMaximo numero par ingresado: %d", maxPar);
    }
    else
    {
        printf("\nNo se ingresaron numeros pares");
    }

    printf("\nEl minimo numero ingresado es: %d", minNum);
    printf("\nEl promedio de numeros impares es: %2.f", promImp);
    printf("\nEl porcentaje de numeros pares es: %2.f", porcentajePar);
    printf("\nEl porcentaje de numeros impares es: %2.f", porcentajeImp);
    printf("\nLa suma de todos los numeros ingresados es: %d", total);
    if ( acumPar > acumImp)
    {
        printf("\nLos numeros pares fueron mas que los impares y la diferencia es de: %d", acumPar - acumImp);
    }
    else
    {
        printf("\nLos numeros impares fueron mas que los pares y la diferencia es de: %d" , acumImp - acumPar);
    }
    return 0;
}







/*Se ingresan numeros (enteros mayores a 0 y menores a 10.000),
no se cuantos.
Se pide:

Cantidad de pares

Cantidad de impares (mayores o iguales a 11)

Maximo numero par ingresado

Minimo numero ingresado

Promedio de numeros impares

Porcentaje de numeros impares y pares

La suma de todos los numeros

La diferencia entre pares e impares (si es que la suma de pares
es mayor que los impares) o la diferencia entre impares y pares
(si es que la suma de impares es mayor que los pares)
*/
