#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float valorA, valorB, resultadoDiv, resultadoSum, resultadoRes, resultadoMult;
    int enteroA, respuestaA;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("Ingrese el valor A: ");
        scanf("%f", &valorA);

        printf("Ingrese el valor B: ");
        scanf("%f", &valorB);

        printf("1- Calcular la suma (A+B)\n");
        printf("2- Calcular la resta (A-B)\n");
        printf("3- Calcular la division (A/B)\n");
        printf("4- Calcular la multiplicacion (A*B)\n");
        printf("5- Calcular el factorial (A!)\n");
        printf("6- Calcular todas las operacione\n");
        printf("7- Salir\n");

        printf("Que operacion desea realizar? : ");
        scanf("%d",&opcion);

        while(opcion < 1 || opcion > 7)
        {
            printf("Elija entre las opciones 1 - 7: ");
            scanf("%d", &opcion);
        }

        switch(opcion)
        {
        case 1:
            resultadoSum = suma(valorA, valorB);
            printf("El resultado de la suma entre %.2f y %.2f es : %.2f\n",valorA, valorB, resultadoSum);
            break;
        case 2:
            resultadoRes = resta(valorA, valorB);
            printf("El resultado de la resta entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoRes);
            break;
        case 3:
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

        case 4:
            resultadoMult = multiplicar(valorA, valorB);
            printf("El resultado de la multiplicacion entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoMult);
            break;
        case 5:
            enteroA = (int) valorA;

            respuestaA = factorial(enteroA);
            printf("El factorial de %d es: %d \n", enteroA, respuestaA);
            break;
        case 6:
            resultadoDiv = dividir(valorA, valorB);
            printf("El resultado de la division entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoDiv);

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
        case 7:
            seguir = 'n';
            break;
        }


    }

    return 0;
}
