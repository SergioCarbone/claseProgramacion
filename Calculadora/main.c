#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"


int main()
{
    float valorA, valorB, resultadoDiv, resultadoSum, resultadoRes, resultadoMult;
    int operaciones, enteroA, respuestaA;

    printf("Ingrese el valor A: ");
    scanf("%f", &valorA);

    printf("Ingrese el valor B: ");
    scanf("%f", &valorB);

    printf("Que operacion desea: 1 = divide, 2 = suma, 3 = resta, 4 = multiplica, 5 = factorial, 6 = todas , 7 = salir : ");
    scanf("%d", &operaciones);

    switch (operaciones)
    {
        case 1:
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

        case 2:
            resultadoSum = suma(valorA, valorB);
            printf("El resultado de la suma entre %.2f y %.2f es : %.2f",valorA, valorB, resultadoSum);
            break;

        case 3:
            resultadoRes = resta(valorA, valorB);
            printf("El resultado de la resta entre %.2f y %.2f es: %.2f",valorA, valorB, resultadoRes);
            break;

        case 4:
            resultadoMult = multiplicar(valorA, valorB);
            printf("El resultado de la multiplicacion entre %.2f y %.2f es: %.2f",valorA, valorB, resultadoMult);
            break;

        case 5:
            enteroA = (int) valorA;

            respuestaA = factorial(enteroA);
            printf("El factorial de %d es: %d ", enteroA, respuestaA);
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
            printf("Chau!!");
            break;


    }


    return 0;
}
