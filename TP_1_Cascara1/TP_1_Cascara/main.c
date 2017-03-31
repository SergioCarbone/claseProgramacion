#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float valorA, valorB, resultadoDiv, resultadoSum, resultadoRes, resultadoMult;
    int opcion = 0, enteroA, respuestaA, flagA = 0, flagB = 0;
    char seguir='s';

    do
    {
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese el primer operando: ");
            scanf("%f", &valorA);
            flagA = 1;
            break;
        case 2:
            printf("Ingrese el segundo operando: ");
            scanf("%f", &valorB);
            flagB = 1;
            break;
        case 3:
            if ( flagA == 0)
            {
                printf("Falta ingresar el primer operando, por favor reingrese: ");
                scanf("%f", &valorA);
                flagA = 1;
                break;
            }
            else if ( flagB == 0)
            {
                printf("Falta ingresar el segundo operando, por favor reingrese: ");
                scanf("%f", &valorB);
                flagB = 1;
                break;
            }
            else
            {
                resultadoSum = suma(valorA, valorB);
                printf("El resultado de la suma entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoSum);
                break;
            }

        case 4:
            if ( flagA == 0)
            {
                printf("Falta ingresar el primer operando, por favor reingrese: ");
                scanf("%f", &valorA);
                flagA = 1;
                break;
            }
            else if ( flagB == 0)
            {
                printf("Falta ingresar el segundo operando, por favor reingrese: ");
                scanf("%f", &valorB);
                flagB = 1;
                break;
            }
            else
            {
                resultadoRes = resta(valorA, valorB);
                printf("El resultado de la resta entre %.2f y %.2f es: %.2f \n",valorA, valorB, resultadoRes);
                break;
            }
        case 5:
            if ( flagA == 0)
            {
                printf("Falta ingresar el primer operando, por favor reingrese: ");
                scanf("%f", &valorA);
                flagA = 1;
                break;
            }
            else if ( flagB == 0)
            {
                printf("Falta ingresar el segundo operando, por favor reingrese: ");
                scanf("%f", &valorB);
                flagB = 1;
                break;
            }
            else
            {
                if(valorB == 0)
                {
                    printf("No se puede dividir entre 0\n");
                    break;
                }
                else
                {
                    resultadoDiv = dividir(valorA, valorB);
                    printf("El resultado de la division entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoDiv);
                    break;
                }
            }
        case 6:
            if ( flagA == 0)
            {
                printf("Falta ingresar el primer operando, por favor reingrese: ");
                scanf("%f", &valorA);
                flagA = 1;
                break;
            }
            else if ( flagB == 0)
            {
                printf("Falta ingresar el segundo operando, por favor reingrese: ");
                scanf("%f", &valorB);
                flagB = 1;
                break;
            }
            else
            {
                resultadoSum = suma(valorA, valorB);
                printf("El resultado de la suma entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoSum);
                break;
            }
        case 7:
            if ( flagA == 0)
            {
                printf("Falta ingresar el primer operando, por favor reingrese: ");
                scanf("%f", &valorA);
                flagA = 1;
                break;
            }
            else
            {
                enteroA = (int) valorA;

                respuestaA = factorial(enteroA);
                printf("El factorial de %d es: %d \n", enteroA, respuestaA);
                break;
            }
        case 8:
            if ( flagA == 0)
            {
                printf("Falta ingresar el primer operando, por favor reingrese: ");
                scanf("%f", &valorA);
                flagA = 1;
                break;
            }
            else if ( flagB == 0)
            {
                printf("Falta ingresar el segundo operando, por favor reingrese: ");
                scanf("%f", &valorB);
                flagB = 1;
                break;
            }
            else
            {
                if(valorB == 0)
                {
                    printf("No se puede dividir entre 0\n");
                }
                else
                {
                    resultadoDiv = dividir(valorA, valorB);
                    printf("El resultado de la division entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoDiv);
                }

                resultadoSum = suma(valorA, valorB);
                printf("El resultado de la suma entre %.2f y %.2f es : %.2f\n",valorA, valorB, resultadoSum);

                resultadoRes = resta(valorA, valorB);
                printf("El resultado de la resta entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoRes);

                resultadoMult = multiplicar(valorA, valorB);
                printf("El resultado de la multiplicacion entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoMult);

                enteroA = (int) valorA;

                respuestaA = factorial(enteroA);
                printf("El factorial de %d es: %d \n", enteroA, respuestaA);
                break;
            }
        case 9:
            seguir = 'n';
            break;
        }

    }
    while(seguir=='s');


    return 0;
}
